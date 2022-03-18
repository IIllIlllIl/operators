//
// Created by Phoenix Wang on 2022/3/14.
//

#include "multiway_merge.h"

table *multiway_merge::sort(table *t0, bool (*cmp)(std::vector<std::string>, std::vector<std::string>)) {
    std::string path = t0->getPath();
    int defaultMax = t0->getDefaultMax();
    int maxBlk = t0->getMaxBlk();
    std::vector<std::string> schema = t0->getSchema();
    table* srt = new table(path + ".srt", schema, defaultMax, maxBlk);
    table* res = new table(path + ".res", schema, defaultMax, maxBlk);

    // sort in every block
    segment* blk;
    std::vector<int> seq;
    std::vector<std::vector<std::string>> buffer;
    int size = t0->getCurrentSeq();
    for (int i = 0; i < size; i++) {
        blk = t0->getBlock(i);
        srt->addBlock(blk_operators::block_sort(blk, cmp));
        seq.push_back(0);
        buffer.push_back(srt->getBlock(i)->read_row(0));
    }

    // merge
    int flag = 0;
    int lines, index, min_pos;
    segment* blk_buf = new segment(schema, defaultMax);
    std::vector<std::string> min;
    while ( flag == 0) {
        // if all blocks are done
        flag = 1;
        for (index = 0; index < size; index++) {
            if (seq[index] >= 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            break;
        }

        // find smallest row in buffer
        min = buffer[index];
        min_pos = index;
        for (int i = (index + 1); i < size; i++) {
            if (seq[i] < 0) {
                continue;
            }
            if (!cmp(min, buffer[i])) {
                min_pos = i;
                min = buffer[min_pos];
            }
        }
        blk_buf->add_row(min);
        if (blk_buf->lines() >= defaultMax) {
            res->addBlock(blk_buf);
            blk_buf = new segment(schema, defaultMax);
        }

        // reload
        blk = srt->getBlock(min_pos);
        lines = blk->lines();
        seq[min_pos]++;
        if (seq[min_pos] < lines) {
            buffer[min_pos] = srt->getBlock(min_pos)->read_row(seq[min_pos]);
        }
        else {
            seq[min_pos] = -1;
        }
    }

    // add blk_buf to res;
    if (blk_buf->lines() > 0) {
        res->addBlock(blk_buf);
    }

    return res;
}

table *multiway_merge::connect_multi(table *table0, table *table1,
                                     int (*condition)(std::vector<std::string>, std::vector<std::string>)) {
    return nullptr;
}

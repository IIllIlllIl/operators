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

table *multiway_merge::p_sort(table *t0, bool (*cmp)(std::vector<std::string>, std::vector<std::string>)) {
    std::string path = t0->getPath();
    int defaultMax = t0->getDefaultMax();
    int maxBlk = t0->getMaxBlk();
    std::vector<std::string> schema = t0->getSchema();
    table* srt = new table(path + ".srt", schema, defaultMax, maxBlk);
    table* res = new table(path + ".mst", schema, defaultMax, maxBlk);

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

table *multiway_merge::connect(table *t0, table *t1,
                                     bool (*cmp0)(std::vector<std::string>, std::vector<std::string>),
                                     bool (*cmp1)(std::vector<std::string>, std::vector<std::string>),
                                     bool (*cmp)(std::vector<std::string>, std::vector<std::string>),
                                     int (*cond)(std::vector<std::string>, std::vector<std::string>)) {
    // sort
    table* ts0 = p_sort(t0, cmp0);
    table* ts1 = p_sort(t1, cmp1);

    // creat result table
    int max, blk;
    int max0 = t0->getDefaultMax();
    int max1 = t1->getDefaultMax();
    int blk0 = t0->getMaxBlk();
    int blk1 = t1->getMaxBlk();
    max = max0 > max1 ? max0 : max1;
    blk = blk0 > blk1 ? blk0 : blk1;
    std::vector<std::string> vec, vec0, vec1;
    vec0 = t0->getSchema();
    vec1 = t1->getSchema();
    vec.insert(vec.end(), vec0.begin(), vec0.end());
    vec.insert(vec.end(), vec1.begin(), vec1.end());

    // find and erase duplicates
    std::vector<int>diff;
    for(int i = 0; i < vec0.size(); i++) {
        for(int j = 0; j < vec1.size(); j++) {
            if(vec0[i] == vec1[j]) {
                diff.push_back(i);
            }
        }
    }
    std::vector<std::string>::iterator it;
    for(int i = 0 ; i < diff.size(); i++) {
        it = vec.begin();
        it += diff[i] - i;
        vec.erase(it);
    }

    table * res = new table(t0->getPath() + ".res", vec, max, blk);
    segment* blk_buf = new segment(vec, max);
    std::vector<std::string> data0, data1, data;
    int n_blk0 = 0, n_blk1 = 0, n_row0 = 0, n_row1 = 0, flag0 = 0, flag1 = 0;

    // connect
    while ((n_blk0 >= 0) && (n_blk1 >= 0)) {
        if (flag0 == 0) {
            flag0 = 1;
            data0 = ts0->getBlock(n_blk0)->read_row(n_row0);
        }
        if (flag1 == 0) {
            flag1 = 1;
            data1 = ts1->getBlock(n_blk1)->read_row(n_row1);
        }

        if (cond(data0, data1) == 0) {
            data.insert(data.end(), data0.begin(), data0.end());
            data.insert(data.end(), data1.begin(), data1.end());
            std::vector<std::string>::iterator it;
            for (int i = 0; i < diff.size(); i++) {
                it = data.begin();
                it += diff[i] - i;
                data.erase(it);
            }
            blk_buf->add_row(data);
            if (blk_buf->lines() >= max) {
                res->addBlock(blk_buf);
                blk_buf = new segment(vec, max);
            }
            data.clear();
        }

        // reload
        if (cmp(data0, data1)) {
            flag0 = 0;
            n_row0 ++;
            if (n_row0 >= ts0->getBlock(n_blk0)->lines()) {
                n_row0 = 0;
                n_blk0++;
                if (n_blk0 >= ts0->getCurrentSeq()) {
                    n_blk0 = -1;
                    flag0 = 1;
                }
            }
        }
        else {
            flag1 = 0;
            n_row1 ++;
            if (n_row1 >= ts1->getBlock(n_blk1)->lines()) {
                n_row1 = 0;
                n_blk1++;
                if (n_blk1 >= ts0->getCurrentSeq()) {
                    n_blk1 = -1;
                    flag1 = 1;
                }
            }
        }
    }

    // add blk_buf to res;
    if (blk_buf->lines() > 0) {
        res->addBlock(blk_buf);
    }

    return res;
}

void multiway_merge::blk_sort(table* t0, table* srt, int blk_num,
                              bool (*cmp)(std::vector<std::string>, std::vector<std::string>)) {
    srt->addBlock(blk_operators::block_sort(t0->getBlock(blk_num), cmp));
}

table *multiway_merge::sort_pthread(table *t0, bool (*cmp)(std::vector<std::string>, std::vector<std::string>)) {
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
    std::thread p[size];
    for (int i = 0; i < size; i++) {
        p[i] = std::thread(blk_sort, t0, srt, i, cmp);
    }
    for (int i = 0; i < size; i++) {
        p[i].join();
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



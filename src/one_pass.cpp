//
// Created by Phoenix Wang on 2022/2/12.
//

#include <set>
#include "one_pass.h"

// table
table *one_pass::project(table *t0, std::vector<std::string> schema) {
    table* res = new table(t0->getPath() + ".res", schema, t0->getDefaultMax(), t0->getMaxBlk());
    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        res->addBlock(blk_operators::block_project(t0->getBlock(i), schema));
    }
    return res;
}

table *one_pass::choose(table *t0, int (*condition)(std::vector<std::string>)) {
    table* res = new table(t0->getPath() + ".res", t0->getSchema(), t0->getDefaultMax(), t0->getMaxBlk());
    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        res->addBlock(blk_operators::block_choose(t0->getBlock(i), condition));
    }
    return res;
}

table *one_pass::product(table *t0, table *t1) {
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

    table* ret = new table(t0->getPath() + ".res", vec, max, blk);
    // if duplicates exist
    std::set<std::string> vecSet(vec.begin(), vec.end());
    if(vec.size() != vecSet.size()) {
        return nullptr;
    }

    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        for (int j = 0; j < t0->getBlock(i)->lines(); j++) {
            for (int k = 0; k < t1->getCurrentSeq(); k++) {
                ret->addBlock(blk_operators::block_product(t0->getBlock(i), t1->getBlock(k), j));
            }
        }
    }

    return ret;
}

table *
one_pass::connect(table *t0, table *t1, int (*condition)(std::vector<std::string>, std::vector<std::string>)) {
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

    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        for (int j = 0; j < t0->getBlock(i)->lines(); j++) {
            for (int k = 0; k < t1->getCurrentSeq(); k++) {
                res->addBlock(blk_operators::block_connect(t0->getBlock(i), t1->getBlock(k), j, condition));
            }
        }
    }

    return res;
}

table *one_pass::deduplicate(table *t0) {
    table* res = new table(t0->getPath() + ".res", t0->getSchema(), t0->getDefaultMax(), t0->getMaxBlk());
    std::vector<std::vector<std::string>> buffer;
    std::vector<std::string> row;

    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        segment* ret = new segment(t0->getSchema(), t0->getDefaultMax());
        segment* buf = t0->getBlock(i);
        for (int j = 0; j < buf->lines(); j++) {
            row = buf->read_row(j);
            int flag = 0;
            for (int k = 0; k < buffer.size(); k++) {
                if (row == buffer[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                buffer.push_back(row);
                ret->add_row(row);
            }
        }
        res->addBlock(ret);
    }

    return res;
}




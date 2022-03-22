//
// Created by Phoenix Wang on 2022/3/19.
//


#include "index_based.h"


table *index_based::connect(table *t0, table *t1,
                            std::vector<std::vector<std::string>>
                            (*f)(std::vector<std::string>)) {
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
    std::vector<std::string> data0, data;
    std::vector<std::vector<std::string>> data1;

    for (int i = 0; i < t0->getCurrentSeq(); i++) {
        for (int j = 0; j < t0->getBlock(i)->lines(); j++) {
            data0 = t0->getBlock(i)->read_row(j);
            data1 = f(data0);
            for (int k = 0; k < data1.size(); k++) {
                data.insert(data.end(), data0.begin(), data0.end());
                data.insert(data.end(), data1[k].begin(), data1[k].end());
                std::vector<std::string>::iterator it;
                for(int i = 0 ; i < diff.size(); i++) {
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
        }
    }

    return res;
}

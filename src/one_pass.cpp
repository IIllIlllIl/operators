//
// Created by Phoenix Wang on 2022/2/12.
//

#include "one_pass.h"


segment one_pass::block_project(segment* buffer, std::vector<std::string> schema) {
    segment ret (schema, buffer->getMax());
    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> vec;

    for (int i = 0; i < schema.size(); i++) {
        vec = buffer->read_column(schema[i]);
        if (vec[0] == "$error") {
            // unexpected schema
            return ret;
        }
        else {
            for (int j = 0; j < vec.size(); j++) {
                if (i == 0) {
                    rows.push_back({vec[j]});
                }
                else {
                    rows[j].push_back(vec[j]);
                }
            }
        }
    }
    ret.add_rows(rows);

    return ret;
}

segment one_pass::block_choose(segment *buffer, int (*condition)(std::vector<std::string>)) {
    segment ret (buffer->get_schema(), buffer->getMax());
    std::vector<std::string> vec;

    for (int i = 0; i < buffer->lines(); i++) {
        vec = buffer->read_row(i);
        // condition() == 0
        if (condition(vec) == 0) {
            ret.add_row(vec);
        }
    }

    return ret;
}

segment one_pass::block_sort(segment *buffer, bool (*cmp)(std::vector<std::string>, std::vector<std::string>)) {
    segment ret (buffer->get_schema(), buffer->getMax());
    std::vector<std::vector<std::string>> vec;

    for (int i = 0; i < buffer->lines(); i++) {
        vec.push_back(buffer->read_row(i));
    }

    std::sort(vec.begin(), vec.end(), cmp);

    ret.add_rows(vec);

    return ret;
}

segment one_pass::block_product(segment *buf1, segment *buf2) {
    int max;
    int max1 = buf1->getMax();
    int max2 = buf2->getMax();
    max = max1 > max2 ? max1 : max2;
    std::vector<std::string> vec, vec1, vec2;
    vec1 = buf1->get_schema();
    vec2 = buf2->get_schema();
    vec.insert(vec.end(), vec1.begin(), vec1.end());
    vec.insert(vec.end(), vec2.begin(), vec2.end());

    segment ret(vec, max);
    // if duplicates exist
    std::set<std::string> vecSet(vec.begin(), vec.end());
    if(vec.size() != vecSet.size()) {
        return ret;
    }

    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> data, data0, data1;

    for (int i = 0; i < buf1->lines(); i++) {
        data0 = buf1->read_row(i);
        for (int j = 0; j < buf2->lines(); j++) {
            data1 = buf2->read_row(j);
            data.insert(data.end(), data0.begin(), data0.end());
            data.insert(data.end(), data1.begin(), data1.end());
            rows.push_back(data);
            data.clear();
        }
    }

    ret.add_rows(rows);

    return ret;
}

segment one_pass::block_connect(segment *buf1, segment *buf2,
                                int (*condition)(std::vector<std::string>, std::vector<std::string>)) {
    int max;
    int max1 = buf1->getMax();
    int max2 = buf2->getMax();
    max = max1 > max2 ? max1 : max2;
    std::vector<std::string> vec, vec1, vec2;
    vec1 = buf1->get_schema();
    vec2 = buf2->get_schema();
    vec.insert(vec.end(), vec1.begin(), vec1.end());
    vec.insert(vec.end(), vec2.begin(), vec2.end());

    // find and erase duplicates
    std::vector<int>diff;
    for(int i = 0; i < vec1.size(); i++) {
        for(int j = 0; j < vec2.size(); j++) {
            if(vec1[i] == vec2[j]) {
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

    segment ret(vec, max);
    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> data, data0, data1;

    for (int i = 0; i < buf1->lines(); i++) {
        data0 = buf1->read_row(i);
        for (int j = 0; j < buf2->lines(); j++) {
            data1 = buf2->read_row(j);
            if (condition(data0, data1) == 0) {
                data.insert(data.end(), data0.begin(), data0.end());
                data.insert(data.end(), data1.begin(), data1.end());
                std::vector<std::string>::iterator it;
                for(int i = 0 ; i < diff.size(); i++) {
                    it = data.begin();
                    it += diff[i] - i;
                    data.erase(it);
                }
                rows.push_back(data);
                data.clear();
            }
        }
    }

    ret.add_rows(rows);

    return ret;
}



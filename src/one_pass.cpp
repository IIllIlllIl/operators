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

segment one_pass::block_sort(segment *buffer) {
    segment ret (buffer->get_schema(), buffer->getMax());

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

    return ret;
}



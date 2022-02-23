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
    return ret;
}


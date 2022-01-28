//
// Created by Phoenix Wang on 2022/1/27.
//

#include "segment.h"
#include <iostream>

segment::segment(std::vector<std::string> data) {
    for (int i = 0; i < data.size(); i++){
        schema.push_back(data[i]);
        seg["$schema"].push_back(data[i]);
    }
}

int segment::display() {
    std::cout << seg << std::endl;
    return 0;
}

std::vector<std::string> segment::get_schema() {
    return schema;
}

int segment::add_row(std::vector<std::string> data) {
    if (schema.size() != data.size()) {
       // error data length
        return -1;
    }

    for (int i = 0; i < schema.size(); i++) {
        seg[schema[i]].push_back(data[i]);
    }

    return 0;
}

int segment::add_rows(std::vector<std::vector<std::string>> data) {
    for (int i = 0; i < data.size(); i++) {
        add_row(data[i]);
    }
}

std::vector<std::string> segment::read_row(int seq) {
    if (!seg[schema[0]][seq]) {
        // out of range
        return {"$error", "out of range"};
    }

    std::vector<std::string> buffer;
    for (int i = 0; i < schema.size(); i++) {
        buffer.push_back(seg[schema[i]][seq].as<std::string>());
    }

    return buffer;
}

std::vector<std::string> segment::read_column(std::string name) {
    int flag_name_exist = 1;
    for (int i = 0; i < schema.size(); i++) {
        if (name == schema[i]) {
            flag_name_exist = 0;
            break;
        }
    }
    if (flag_name_exist){
        // name is not in schema
        return {"$error", "not exist"};
    }

    std::vector<std::string> buffer;
    for (int i = 0; seg[name][i]; i++) {
        buffer.push_back(seg[name][i].as<std::string>());
    }

    return buffer;
}
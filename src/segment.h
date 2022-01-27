//
// Created by Phoenix Wang on 2022/1/27.
//
// segment.h
// a segment of a table
#include <yaml-cpp/yaml.h>
#include <vector>
#include <string>

#ifndef OPERATORS_SEGMENT_H
#define OPERATORS_SEGMENT_H


class segment {
    YAML::Node seg;
    std::vector<std::string> schema;

public:
    // create a segment with its schema
    segment(std::vector<std::string> data);

    // display the whole segment
    int display();
    // display schema
    std::vector<std::string> get_schema();

    // add data
    int add_row(std::vector<std::string> data);
    int add_column(std::vector<std::string> data);
    // read data
    std::vector<std::string> read_row(int seq);
    std::vector<std::string> column(int seq);
};


#endif //OPERATORS_SEGMENT_H

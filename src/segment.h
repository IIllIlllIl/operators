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
    // add data
    int add_row(std::vector<std::string> data);
    int add_Column(std::vector<std::string> data);
};


#endif //OPERATORS_SEGMENT_H

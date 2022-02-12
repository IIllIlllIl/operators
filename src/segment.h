//
// Created by Phoenix Wang on 2022/1/27.
//
// segment.h
// a segment of a table, which should be small enough for memory
#include <yaml-cpp/yaml.h>
#include <vector>
#include <string>
#include "file_io.h"

#ifndef OPERATORS_SEGMENT_H
#define OPERATORS_SEGMENT_H
#define MAX 32


class segment {
public:
    YAML::Node seg;
    std::vector<std::string> schema;
    int max = MAX;
    file_io files;

public:
    // create a segment with its schema
    segment(std::vector<std::string> schema);
    segment(std::vector<std::string> schema, int val);
    segment(std::string path);

    // display the whole segment
    int display();
    // display schema
    std::vector<std::string> get_schema();
    // set max
    int setMax(int val);
    // show the number of lines in seg
    int lines();

    // add data
    int add_row(std::vector<std::string> data);
    int add_rows(std::vector<std::vector<std::string>> data);
    // int add_column(std::vector<std::string> data);

    // read data
    std::vector<std::string> read_row(int seq);
    std::vector<std::string> read_column(std::string name);

    // io
    int read_node(std::string path);
    int write_node(std::string path);
};


#endif //OPERATORS_SEGMENT_H

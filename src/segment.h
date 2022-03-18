//
// Created by Phoenix Wang on 2022/1/27.
//
// segment.h
// a segment of a table, which should be small enough for memory


#ifndef OPERATORS_SEGMENT_H
#define OPERATORS_SEGMENT_H


#include <vector>
#include <string>
#include "file_io.h"
//#include <yaml-cpp/yaml.h>
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>


#define MAX 32


/* yaml
class segment {
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
    // max
    int setMax(int val);
    inline int getMax() {return max;}
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
};*/

// json
class segment {
    Json::Value seg;
    std::vector<std::string> schema;
    int max = MAX;
public:
    // create a segment with its schema
    segment(std::vector<std::string> schema);
    segment(std::vector<std::string> schema, int val);
    segment(std::string path);

    // display the whole segment
    int display();
    // display arguments
    inline std::vector<std::string> get_schema() {return schema;}
    inline void setMax(int val) {max = val;}
    inline int getMax() const {return max;}
    // show the number of lines in seg
    inline int lines() {return seg[schema[0]].size();}

    // add data
    int add_row(std::vector<std::string> data);
    int add_rows(std::vector<std::vector<std::string>> data);

    // read data
    std::vector<std::string> read_row(int seq);
    std::vector<std::string> read_column(std::string name);

    // io
    int read_node(std::string path);
    int write_node(std::string path);
};

#endif //OPERATORS_SEGMENT_H

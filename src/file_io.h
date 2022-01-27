//
// Created by Phoenix Wang on 2022/1/24.
//
// file_io.h
// read data from files and write data to files
//

#include <yaml-cpp/yaml.h>
/*
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>
 */
#include <fstream>
#include <string>

#ifndef OPERATORS_FILE_IO_H
#define OPERATORS_FILE_IO_H


class file_io {
public:
    //read a yaml node from a file by its path
    int readNode(YAML::Node &node, std::string path);
    //write a yaml node to a file by its path
    int writeNode(YAML::Node node, std::string path);
};


#endif //OPERATORS_FILE_IO_H

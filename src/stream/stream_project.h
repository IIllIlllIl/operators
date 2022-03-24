//
// Created by Phoenix Wang on 2022/3/24.
//
// stream_project.h
// project


#ifndef OPERATORS_STREAM_PROJECT_H
#define OPERATORS_STREAM_PROJECT_H


#include "../stream.h"


class stream_project : public stream{
    std::vector<std::string> schema;
public:
    stream_project(std::vector<std::string> str);
    segment* op(segment *blk);
};


#endif //OPERATORS_STREAM_PROJECT_H

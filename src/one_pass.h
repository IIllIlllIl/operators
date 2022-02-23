//
// Created by Phoenix Wang on 2022/2/12.
//
// one_pass.h
// one pass algorithm on segment

#include "segment.h"

#ifndef OPERATORS_ONE_PASS_H
#define OPERATORS_ONE_PASS_H


class one_pass {
public:
    // block
    static segment block_project(segment* buffer, std::vector<std::string> schema);
    static segment block_choose(segment* buffer, int (*condition)(std::vector<std::string>));
};


#endif //OPERATORS_ONE_PASS_H

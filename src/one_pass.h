//
// Created by Phoenix Wang on 2022/2/12.
//
// one_pass.h
// one pass algorithm on segment

#include <cstdlib>
#include "segment.h"

#ifndef OPERATORS_ONE_PASS_H
#define OPERATORS_ONE_PASS_H


class one_pass {
public:
    // block
    static segment block_project(segment* buffer, std::vector<std::string> schema);
    static segment block_choose(segment* buffer, int (*condition)(std::vector<std::string>));
    static segment block_product(segment* buf1, segment* buf2);
    static segment block_sort(segment* buffer);
};



#endif //OPERATORS_ONE_PASS_H

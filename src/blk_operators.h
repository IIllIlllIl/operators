//
// Created by Phoenix Wang on 2022/3/17.
//
// blk_operators.h
// one pass algorithm on segments(blocks)


#ifndef OPERATORS_BLK_OPERATORS_H
#define OPERATORS_BLK_OPERATORS_H


#include "segment.h"
#include <cstdlib>
#include <sstream>
#include <iostream>


class blk_operators {
public:
    // block
    static segment* block_project(segment* buffer, std::vector<std::string> schema);
    static segment* block_choose(segment* buffer, int (*condition)(std::vector<std::string>));
    static segment* block_sort(segment* buffer, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    // static segment* block_product(segment* buf1, segment* buf2);
    static segment* block_product(segment* buf1, segment* buf2, int row);
    // static segment block_connect(segment* buf1, segment* buf2, int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static segment* block_connect(segment* buf1, segment* buf2, int row, int (*condition)(std::vector<std::string>, std::vector<std::string>));
};


#endif //OPERATORS_BLK_OPERATORS_H

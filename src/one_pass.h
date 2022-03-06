//
// Created by Phoenix Wang on 2022/2/12.
//
// one_pass.h
// one pass algorithm on segment

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "segment.h"

#ifndef OPERATORS_ONE_PASS_H
#define OPERATORS_ONE_PASS_H


class one_pass {
public:
    // block
    static segment block_project(segment* buffer, std::vector<std::string> schema);
    static segment block_choose(segment* buffer, int (*condition)(std::vector<std::string>));
    static segment block_sort(segment* buffer, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static segment block_product(segment* buf1, segment* buf2);
    static segment block_connect(segment* buf1, segment* buf2, int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static bool cmp(std::vector<std::string> row1, std::vector<std::string> row2) {
        int total1, total2;
        std::stringstream x1, x2;
        x1 << row1[2];
        x2 << row2[2];
        x1 >> total1;
        x2 >> total2;
        return total1 < total2;
    }
    static int equal(std::vector<std::string> row1, std::vector<std::string> row2) {
        return !(row1[2] == row2[0]);
    }
};

#endif //OPERATORS_ONE_PASS_H

//
// Created by Phoenix Wang on 2022/2/12.
//
// one_pass.h
// one pass algorithm on segment/table

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "segment.h"
#include "table.h"

#ifndef OPERATORS_ONE_PASS_H
#define OPERATORS_ONE_PASS_H


class one_pass {
public:
    // block
    static segment* block_project(segment* buffer, std::vector<std::string> schema);
    static segment* block_choose(segment* buffer, int (*condition)(std::vector<std::string>));
    static segment block_sort(segment* buffer, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static segment* block_product(segment* buf1, segment* buf2);
    static segment* block_product(segment* buf1, segment* buf2, int row);
    static segment block_connect(segment* buf1, segment* buf2, int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static segment* block_connect(segment* buf1, segment* buf2, int row, int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static bool cmp(std::vector<std::string> row1, std::vector<std::string> row2) {
        int total1, total2;
        std::stringstream x1, x2;
        x1 << row1[2];
        x2 << row2[2];
        x1 >> total1;
        x2 >> total2;
        return total1 < total2;
    }
    static int testCondition(std::vector<std::string> row) {
        std::stringstream x;
        double num;
        x << row[4];
        // c(row[4]);
        x >> num;
        // c(num);
        if (num > 300000) {
            return 0;
        }
        else {
            return -1;
        }
    }
    static int equal(std::vector<std::string> row1, std::vector<std::string> row2) {
        return !(row1[2] == row2[0]);
    }

    // table
    static table * project(table *t0, std::vector<std::string> schema);
    static table * choose(table *t0, int (*condition)(std::vector<std::string>));
    static table * product(table *table0, table *table1);
    static table * connect(table *table0, table *table1, int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static table * deduplicate (table * t0);
};

#endif //OPERATORS_ONE_PASS_H

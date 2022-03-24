//
// Created by Phoenix Wang on 2022/2/12.
//
// one_pass.h
// one pass algorithm


#ifndef OPERATORS_ONE_PASS_H
#define OPERATORS_ONE_PASS_H


#include <cstdlib>
#include <sstream>
#include <iostream>
#include <thread>
#include "blk_operators.h"
#include "segment.h"
#include "stream.h"


class one_pass {
public:
    // block test
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
    static table * connect(table *table0, table *table1,
                           int (*condition)(std::vector<std::string>, std::vector<std::string>));
    static table * deduplicate (table * t0);
    static table * stream_operators(table* t, std::vector<stream*> op);
};

#endif //OPERATORS_ONE_PASS_H

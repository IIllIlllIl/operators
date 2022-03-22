//
// Created by Phoenix Wang on 2022/3/14.
//
// multiway_merge.h
// multiway merge algorithm


#ifndef OPERATORS_MULTIWAY_MERGE_H
#define OPERATORS_MULTIWAY_MERGE_H


#include "one_pass.h"


class multiway_merge {
private:
    static table* p_sort(table* table, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
public:
    static table* sort(table* table, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static table* sort_pthread(table* table, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static table* connect_multi(table *table0, table *table1,
                                 bool (*cmp_table0)(std::vector<std::string>, std::vector<std::string>),
                                 bool (*cmp_table1)(std::vector<std::string>, std::vector<std::string>),
                                 bool (*cmp)(std::vector<std::string>, std::vector<std::string>),
                                 int (*condition)(std::vector<std::string>, std::vector<std::string>));
    // test
    static bool cmp0(std::vector<std::string> row1, std::vector<std::string> row2) {
        int total1, total2;
        std::stringstream x1, x2;
        x1 << row1[2];
        x2 << row2[2];
        x1 >> total1;
        x2 >> total2;
        return total1 < total2;
    }

    static bool cmp1(std::vector<std::string> row1, std::vector<std::string> row2) {
        int total1, total2;
        std::stringstream x1, x2;
        x1 << row1[0];
        x2 << row2[0];
        x1 >> total1;
        x2 >> total2;
        return total1 < total2;
    }

    static bool cmp(std::vector<std::string> row1, std::vector<std::string> row2) {
        int total1, total2;
        std::stringstream x1, x2;
        x1 << row1[2];
        x2 << row2[0];
        x1 >> total1;
        x2 >> total2;
        return total1 < total2;
    }
};


#endif //OPERATORS_MULTIWAY_MERGE_H

//
// Created by Phoenix Wang on 2022/3/14.
//
// multiway_merge.h
//


#ifndef OPERATORS_MULTIWAY_MERGE_H
#define OPERATORS_MULTIWAY_MERGE_H


#include "one_pass.h"


class multiway_merge {
public:
    static table* sort(table* table, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static table* sort_pthread(table* table, bool (*cmp)(std::vector<std::string>, std::vector<std::string>));
    static table * connect_multi(table *table0, table *table1, int (*condition)(std::vector<std::string>, std::vector<std::string>));
};


#endif //OPERATORS_MULTIWAY_MERGE_H

//
// Created by Phoenix Wang on 2022/3/19.
//
// index_based.h
// index based algorithm


#ifndef OPERATORS_INDEX_BASED_H
#define OPERATORS_INDEX_BASED_H


#include "one_pass.h"


class index_based {
public:
    static table * connect(table *table0, table *table1,
                           std::vector<std::vector<std::string>>
                           (*find)(std::vector<std::string>));
};

#endif //OPERATORS_INDEX_BASED_H

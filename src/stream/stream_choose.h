//
// Created by Phoenix Wang on 2022/3/24.
//
// stream_choose.h
// choose


#ifndef OPERATORS_STREAM_CHOOSE_H
#define OPERATORS_STREAM_CHOOSE_H


#include "../stream.h"

class stream_choose : public stream{
    int (*cond)(std::vector<std::string>);
public:
    stream_choose(int (*condition)(std::vector<std::string>));
    segment* op(segment *blk);
};


#endif //OPERATORS_STREAM_CHOOSE_H

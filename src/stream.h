//
// Created by Phoenix Wang on 2022/3/23.
//
// stream.h
// one pass algorithm by stream processing


#ifndef OPERATORS_STREAM_H
#define OPERATORS_STREAM_H


#include "table.h"
#include "blk_operators.h"


class stream {
public:
    // op:
    // 0: project
    // 1: choose
    int type;
public:
    virtual segment* op(segment *blk) = 0;
};


#endif //OPERATORS_STREAM_H

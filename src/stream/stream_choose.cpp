//
// Created by Phoenix Wang on 2022/3/24.
//


#include "stream_choose.h"


stream_choose::stream_choose(int (*condition)(std::vector<std::string>))
        : cond(condition){
    type = 1;
}

segment *stream_choose::op(segment *blk) {
    return blk_operators::block_choose(blk, cond);
}

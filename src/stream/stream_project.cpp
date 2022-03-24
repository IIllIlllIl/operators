//
// Created by Phoenix Wang on 2022/3/24.
//


#include "stream_project.h"


stream_project::stream_project(std::vector<std::string> str) : schema(std::move(str)){
    type = 0;
}

segment *stream_project::op(segment *blk) {
    return blk_operators::block_project(blk,  schema);
}

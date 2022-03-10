//
// Created by Phoenix Wang on 2022/3/6.
//

#include "table.h"

table::table(std::string path, int nBlk) : dir_path(std::move(path)), max_blk(nBlk) {
    for(int s = 0; ; s++) {
        if (s >= max_blk) {
            break;
        }
        std::ifstream f(blk(s));
        if(!f.good()) {
            current_seq = s;
            break;
        }
    }

    if (current_seq > 0) {
        segment b0(blk(0));
        default_max = b0.getMax();
        schema = b0.get_schema();
    }
    else {
        default_max = -1;
        max_blk = -1;
    }
}

int table::addBlock(segment* block) {
    if (current_seq >= max_blk) {
        return -1;
    }
    return block->write_node(blk(current_seq++));
}

int table::addBlock(std::string path) {
    segment blk(path);
    return addBlock(&blk);
}

int table::getBlock(int seq, segment &block) {
    if (seq >= current_seq) {
        // out of range
        return -1;
    }
    std::ifstream f(blk(seq));
    if(!f.good()) {
        // not exist
        return -2;
    }

    block = segment(blk(seq));

    return 0;
}

segment* table::getBlock(int seq) {
    return new segment(blk(seq));
}

int table::writeBlock(int seq) {
    if (seq >= current_seq) {
        // out of range
        return -1;
    }
    std::ifstream f(blk(seq));
    if(!f.good()) {
        // not exist
        return -2;
    }

    getBlock(seq)->write_node(blk(seq));

    return 0;
}

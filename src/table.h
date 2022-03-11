//
// Created by Phoenix Wang on 2022/3/6.
//
// table.h
// table of a relation(#seq.blk)

#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include "segment.h"

#ifndef OPERATORS_TABLE_H
#define OPERATORS_TABLE_H
#define DISPLAY_GAP 35


class table {
    std::string dir_path;
    std::vector<std::string> schema;
    int current_seq;
    int default_max;
    int max_blk;

    // get the block path of specified sequence
    inline std::string blk(int seq) {return dir_path + "/" + std::to_string(seq) + ".blk";}
    void showVec(std::vector<std::string> vec) {
        for (int  i = 0; i < vec.size(); i++) {
            for (int j = 0; j < (DISPLAY_GAP - vec[i].length())/2; j++) {
                    std::cout << " ";
            }
            std::cout << vec[i];
            for (int j = 0; j < (DISPLAY_GAP - vec[i].length())/2; j++) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

public:
    table(std::string path, std::vector<std::string> schema_, int max, int blk)
        : dir_path(std::move(path)), schema(std::move(schema_)), default_max(max), max_blk(blk) {
        current_seq = 0;
        mkdir(dir_path.c_str(), 0777);
    }
    table(std::string path, int max_blk);

    // display all info
    int display();

    // set arguments
    inline std::vector<std::string> getSchema() {return schema;}
    inline void setDefaultMax(int val) {default_max = val;}
    inline int getDefaultMax() const {return default_max;}
    inline void setMaxBlk(int val) {max_blk = val;}
    inline int getMaxBlk() const {return max_blk;}
    inline int getCurrentSeq() const {return current_seq;}
    inline std::string getPath() const {return dir_path;}
    std::string getDir();

    // get number of lines of all blocks
    int lines();

    // add block, return seq
    int addBlock(segment* block);
    int addBlock(std::string path);

    // read block
    int getBlock(int seq, segment &block);
    segment* getBlock(int seq);

    // write block
    int writeBlock(int seq);
};


#endif //OPERATORS_TABLE_H

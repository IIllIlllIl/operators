//
// Created by Phoenix Wang on 2022/1/27.
//

#include "segment.h"
#include <iostream>

segment::segment(std::vector<std::string> data) {
    for(int i = 0; i < data.size(); i++){
        seg.push_back(data[i]);
        schema.push_back(data[i]);
    }
}

int segment::display() {
    std::cout << seg << std::endl;
    return 0;
}

int segment::add_row(std::vector<std::string> data){
    if(schema.size() != data.size()){
       // error data length
        return -1;
    }

    return 0;
}
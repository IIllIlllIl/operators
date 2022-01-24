//
// Created by Phoenix Wang on 2022/1/24.
//

#include "file_io.h"

int file_io::writeNode(YAML::Node node, std::string path){
    std::ofstream file(path);
    file << node <<std::endl;
    file.close();
    return 0;
}

int file_io::readNode(YAML::Node &node, std::string path){
    std::ifstream file(path);
    node = YAML::Load(file);//读取来自test.yaml的node文件
    file.close();
    return 0;
}

//
// Created by Phoenix Wang on 2022/1/24.
//

#include "file_io.h"
/*yaml
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
}*/

// json
int file_io::readNode(Json::Value &blk, const std::string& path) {
    std::ifstream file(path);
    Json::Reader reader;

    if (!reader.parse(file, blk, false)) {
        // cannot open file
        file.close();
        return -1;
    }

    file.close();
    return 0;
}

int file_io::writeNode(const Json::Value& blk, const std::string& path) {
    Json::StyledWriter writer;
    std::ofstream file(path);

    file << writer.write(blk) << std::endl;

    file.close();
    return 0;
}

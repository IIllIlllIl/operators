//
// Created by Phoenix Wang on 2022/1/27.
//
// test.h
// tests for models


#ifndef OPERATORS_TEST_H
#define OPERATORS_TEST_H


#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "../test/test_data.h"
#include "../lib/operators.h"


#define c(x) std::cout<<#x<<": "<<x<<std::endl


class test {
public:
    // json part
    // test of stream
    int test_stream() {
        table t("../test/json/stream/t0", 16);
        std::vector<stream*> st;
        stream* p = new stream_choose(testCondition);
        st.push_back(p);
        p = new stream_project({"region", "new"});
        st.push_back(p);
        one_pass::stream_operators(&t, st)->display();

        return 0;
    }
    // test of test
    int test_of_find() {
        table t("../test/json/index/t1", 16);
        std::vector<std::vector<std::string>> res;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 32; j++) {
                res = testFind(t.getBlock(i)->read_row(j));
                for (int k = 0; k < 3; k++) {
                    std::cout << res[0][k] << " ";
                }
                std::cout << std::endl;
            }
        }
        return 0;
    }
    // find
    static std::vector<std::vector<std::string>> testFind(std::vector<std::string> vec) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> row;
        table t("../test/json/index/t2", 16);
        std::stringstream x;
        int num;
        x << vec[2];
        x >> num;

        for (int i = 0 ; i < testIndex.size(); i++) {
            if (testIndex[i][0] == num) {
                row = t.getBlock(testIndex[i][1])->read_row(testIndex[i][2]);
                res.push_back(row);
            }
        }

        return res;
    }
    // test of index based
    int test_index_based() {
        table t1("../test/json/index/t1", 16);
        table t2("../test/json/index/t2", 16);
        t1.display();
        t2.display();
        index_based::connect(&t1, &t2, testFind)->display();
        return 0;
    }
    // test of multiway merge (based on json)
    int test_mm_js() {
        std::string path0 = "../test/json/table/t0";
        std::string path1 = "../test/json/table/t1";
        std::string path2 = "../test/json/table/t2";
        std::string pathp = "../test/json/pthread/t0";
        table t0(path0, 16);
        table t1(path1, 16);
        table t2(path2, 16);
        table tp(pathp, 16);
        // multiway_merge::sort(&t0, one_pass::cmp)->display();
        multiway_merge::sort_pthread(&tp, one_pass::cmp)->display();
        // t0.display();
        // c(t0.getBlock(0)->read_row(0)[0]);
        // c(t0.getBlock(1)->read_row(0)[0]);

        // generate test data of connect
        // one_pass::project(&t0, {"region", "new", "cumulative"});
        // one_pass::project(&t0, {"cumulative", "cured", "death"});
        /*
        multiway_merge::connect(&t1, &t2,
                                      multiway_merge::cmp0, multiway_merge::cmp1, multiway_merge::cmp,
                                      one_pass::equal)->display();*/

        return 0;
    }
    // test of table (based on json)
    int test_table_js() {
        /*
        std::string path = "../test/simples/table/tb1";
        table tb0(path, epidemic_schema, 32, 2);
        segment b0(epidemic_schema, 32);
        segment b1(epidemic_schema, 32);
        b0.add_rows(row64_0);
        b1.add_rows(row64_1);
        c(tb0.addBlock(&b0));
        c(tb0.addBlock(&b1));
         */

        std::string path0 = "../test/json/table/t0";
        table t0(path0, 16);
        table td("../test/json/onepass/td", 16);
        table t1("../test/json/onepass/t1", 16);
        table t2("../test/json/onepass/t2", 256);
        table t3("../test/json/onepass/t3", 256);
        table t4("../test/json/onepass/t4", 16);
        // one_pass::project(&t1, {"cumulative", "cured", "death"})->display();
        // one_pass::choose(&t0, testCondition)->display();
        // one_pass::product(&t2, &t4)->display();
        // one_pass::connect(&t3, &t4, one_pass::equal)->display();
        one_pass::deduplicate(&td)->display();
        return 0;
    }
    // test of table
    int test_table() {
        /*
        std::string path = "../test/simples/table/tb1";
        table tb0(path, epidemic_schema, 32, 2);
        segment b0(epidemic_schema, 32);
        segment b1(epidemic_schema, 32);
        b0.add_rows(row64_0);
        b1.add_rows(row64_1);
        c(tb0.addBlock(&b0));
        c(tb0.addBlock(&b1));
         */

        std::string path0 = "../test/simples/table/tb0";
        std::string path1 = "../test/simples/table/tb1";
        std::string path2 = "../test/simples/table/tb2";
        std::string path3 = "../test/simples/table/tb3";
        std::string path_d = "../test/simples/table/tb_dup";
        table t0(path0, 16);
        table t1(path1, 64);
        table t2(path2, 128);
        table t3(path3, 16);
        table td(path_d, 16);
        // one_pass::project(&t0, {"??????", "??????"})->display();
        // one_pass::project(&t0, {"??????", "a"})->display();
        // one_pass::choose(&t0, testCondition)->display();
        // one_pass::product(&t1, &t3)->display();
        // one_pass::connect(&t2, &t3, one_pass::equal)->display();
        one_pass::deduplicate(&td)->display();

        return 0;
    }
    // test of one pass choose condition
    static int testCondition(std::vector<std::string> row) {
        std::stringstream x;
        double num;
        x << row[4];
        // c(row[4]);
        x >> num;
        // c(num);
        if (num > 300000) {
            return 0;
        }
        else {
            return -1;
        }
     }
    // test of one pass
    int test_op_pro() {
        //segment s("../test/simples/test.yml");
        // one_pass::block_project(&s, {"??????", "??????"}).display();
        // one_pass::block_choose(&s, testCondition).display();
        // one_pass::block_sort(&s, one_pass::cmp).display();

        segment s0(schema0, 16);c(s0.add_rows(row60));
        segment s1(schema1, 16);c(s1.add_rows(row61));
        segment s2(schema2, 32);c(s2.add_rows(row62));
        // blk_operators::block_product(&s0, &s2).display();
        // blk_operators::block_product(&s1, &s2).display();
        // blk_operators::block_connect(&s1, &s2, one_pass::equal).display();

        return 0;
    }
    // data
    int process_data() {
        std::ifstream file("../test/simples/data");
        std::string buffer;
        std::string output;

        while(file >> buffer) {
            output.clear();
            output += "{";

            output += "\"";
            output += buffer;
            output += "\"";
            for (int i = 0; i < 4; i++) {
                file >> buffer;
                output += ", \"";
                output += buffer;
                output += "\"";
            }

            output += "},\n";
            std::cout << output;
        }

        return 0;
    }
    // test fo json
    std::string ConstructJsonString()
    {
        Json::Value rootValue = Json::objectValue;
        rootValue["encoding"] = "UTF-8";
        rootValue["plug-ins"] = Json::arrayValue;
        rootValue["plug-ins"].append("python");
        rootValue["plug-ins"].append("c++");
        rootValue["plug-ins"].append("ruby");
        rootValue["indent"] = Json::objectValue;
        rootValue["indent"]["length"] = 3;
        rootValue["indent"]["use_space"] = true;

        return Json::FastWriter().write(rootValue);
    }

    void ParseJsonString(const std::string& document)
    {
        Json::Reader reader;
        Json::Value rootValue;
        if (!reader.parse(document, rootValue)) {
            return;
        }

        if (!rootValue.isObject()) {
            return;
        }

        if (rootValue.isMember("encoding") && rootValue["encoding"].isString()) {
            printf("encoding is %s \n", rootValue["encoding"].asString().c_str());
        }

        if (rootValue.isMember("plug-ins") && rootValue["plug-ins"].isArray()) {
            for (Json::ArrayIndex i = 0; i < rootValue["plug-ins"].size(); ++i) {
                if (rootValue["plug-ins"][i].isString()) {
                    printf("plug-ins %d : %s \n", i, rootValue["plug-ins"][i].asString().c_str());
                }
            }
        }
        if (rootValue.isMember("indent") && rootValue["indent"].isObject()) {
            if (rootValue["indent"].isMember("length") && rootValue["indent"]["length"].isInt()) {
                printf("indent length is %d \n", rootValue["indent"]["length"].asInt());
            }
            if (rootValue["indent"].isMember("use_space") && rootValue["indent"]["use_space"].isBool()) {
                printf("indent use_space is %s \n", rootValue["indent"]["use_space"].asBool() ? "true":"false");
            }
        }
    }

    int test_of_json() {
        std::string document = ConstructJsonString();
        printf(document.c_str());
        printf("\n");
        ParseJsonString(document);
        return 0;
    }

    int test_of_jsReadFile() {
        Json::Value root;
        file_io::readNode(root, "../test/json/test.json");
        std::string name = root["name"].asString(); // ???????????????????????????, ?????????????????????????????????????????????asString()??????????????????????????????
        int age = root["age"].asInt(); // ????????????????????????????????????
        std::cout << name << ":" << age << "\n";
        return 0;
    }

    int test_of_jsWriteFile() {
        Json::Value root;
        root["$schema"].append("place");
        root["$schema"].append("place");
        root["$schema"].append("place");
        root["$schema"].append("place");
        root["$max"] = "32";
        file_io::writeNode(root, "../test/json/blk.json");
        return 0;
    }

    int create_js_blk() {
        segment b0(epidemic_schema_E, 32);
        segment b1(epidemic_schema_E, 32);
        b0.add_rows(row64_0_E);
        b1.add_rows(row64_1_E);
        b0.write_node("../test/json/table/t0/0.blk");
        b1.write_node("../test/json/table/t0/1.blk");
        segment b2("../test/json/table/t0/0.blk");
        b2.display();
        return 0;
    }

    // test of segment
    int test_segment() {
        segment s0("../test/simples/test.yml");
        segment s1(epidemic_schema, 7);c(s1.add_rows(row6));

        c(s0.read_column("??????")[0]);
        c(s1.read_column("??????")[0]);
        c(s0.read_column("??????")[5]);
        c(s1.read_column("??????")[5]);
        c(s0.read_column("??????")[6]);
        c(s1.read_column("??????")[6]);

        // s0.display();
        // s1.display();

        // std::cout<<seg.lines()<<std::endl;
        //seg.write_node("../test/simples/test.yml");
        return 0;
    }
    // test of add row/rows
    /*
        int test_add_max(){
        segment s0("../test/simples/test.yml");
        segment s1(epidemic_schema, 7);c(s1.add_rows(row6));

        c(s0.seg["??????"].IsSequence());
        c(s1.seg["??????"].IsSequence());

        c(s0.add_rows(row6));
        c(s1.add_rows(row6));
        c(s0.seg["??????"]);
        c(s1.seg["??????"]);

        c(s0.seg["??????"].IsSequence());
        c(s1.seg["??????"].IsSequence());

        // s0.display();
        // s1.display();

        // std::cout<<seg.lines()<<std::endl;
        //seg.write_node("../test/simples/test.yml");
        return 0;
    }*/
    /*
    // test of yaml-cpp/yaml.h
    int test_yaml_cpp(){
        YAML::Node node;
        assert(node.IsNull());  //?????????????????????Null??????
        node["key"] = "value";  //??????????????????????????????????????????Map??????
        //node.force_insert("key", "value");//???????????????????????????????????????????????????????????????"key"?????????????????????
        if(node["mascot"])
            std::cout << node["mascot"].as<std::string>() << "\n";//???????????????????????????????????????key??????????????????if????????????

        node["number"] = 255;
        assert(node.IsMap());   //node?????????Map
        node["seq"].push_back("first element");
        node["seq"].push_back("second element");//node???seq??????Sequence????????????????????????

        YAML::Node node_2;
        node_2.push_back("first item");//???????????????node_2????????????????????????sequence??????
        node_2.push_back("second_item");
        node_2.push_back("third_item");
        std::vector<int> v = {1,3,5,7,9};//???node_2???????????????Sequence
        node_2.push_back(v);
        assert(node_2.IsSequence());//?????????node_2???????????????Sequence

        assert(node_2[0].as<std::string>() == "first item");
        //??????Sequence?????????????????????????????????????????????
        //????????????as<T>????????????????????????node_2[0]???type???NodeType::Scalar

        //auto it = node_2.begin();
        //for(; it != node_2.end(); it++)
        //    std::cout << *(it) << std::endl;
        std::cout<<node_2;

        //??????????????????????????????????????????
        //????????????????????????NodeType::Scalar???NodeType::Scalar???NodeType::Scalar???NodeType::Sequence
        //?????????????????????as??????????????????
        node_2["key"] = "value";
        assert(node_2.IsMap());//??????node_2?????????????????????????????????Map??????
        assert(node_2[0].as<std::string>() == "first item");//?????????Sequence????????????????????????key???
        node["node_2"] = node_2;//???node_2??????node???????????????
        node["pointer_to_first_element"] = node["seq"][0];//????????????????????????node??????????????????????????????????????????
        assert(node["pointer_to_first_element"].as<std::string>() == "first element");//???????????????????????????????????????node

        std::cout<<node;

        node.remove(node["seq"][0]);//???????????????????????????node????????????
        node.remove("pointer_to_first_element");//????????????????????????key????????????

        return 0;
    }
    int test_yaml_cpp2() {
        YAML::Node n;
        for (int i = 0; i < 6; i++) {
            n["a"].push_back(i);
        }
        c(n["a"][1]);
        c(n);
        return 0;
    }
    // test of file_io.h
    int test_file_io(){
        YAML::Node test_node1, test_node2;
        file_io files;
        test_node1["Ran"].push_back("sjtu");
        test_node1["Rann"].push_back("sjtu");
        test_node1["Rannn"].push_back("sjtu");
        test_node1["Rannnn"].push_back("sjtu");

        files.writeNode(test_node1, "../test/test0.yaml");
        files.readNode(test_node2, "../test/test0.yaml");

        std::cout << test_node2 <<std::endl;
        //std::ifstream ifile("simples/test.yml");
        //YAML::Node inode = YAML::Load(ifile);//????????????test.yml???node??????
        //std::cout << inode <<std::endl;
        //YAML::Node inode_2 = YAML::LoadFile("simples/test.yml");//???????????????????????????
        //std::cout << inode_2["node_2"] <<std::endl;//???????????????????????????
        //for(auto it = inode_2.begin(); it != inode_2.end(); it++)
        //    std::cout << it->first << it->second << std::endl;//???????????????????????????

        return 0;
    }
    */
    // test
};


#endif //OPERATORS_TEST_H

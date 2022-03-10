//
// Created by Phoenix Wang on 2022/1/27.
//
// test.h
// tests for models

#include <iostream>
#include <fstream>
#include <cassert>
#include <yaml-cpp/yaml.h>
#include <sstream>
/*
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>
 */

#include "../src/file_io.h"
#include "../src/segment.h"
#include "../test/epidemic.h"
#include "../src/one_pass.h"
#include "../src/table.h"

#ifndef OPERATORS_TEST_H
#define OPERATORS_TEST_H
#define c(x) std::cout<<#x<<": "<<x<<std::endl


class test {
public:
    // test of table
    int test_table() {
        /*
        std::string path = "../test/simples/table/tb0";
        table tb0(path, epidemic_schema, 32, 2);
        segment b0(epidemic_schema, 32);
        segment b1(epidemic_schema, 32);
        b0.add_rows(row64_0);
        b1.add_rows(row64_1);
        c(tb0.addBlock(&b0));
        c(tb0.addBlock(&b1));
        */
        std::string path = "../test/simples/table/tb0";
        table t0(path, 16);
        t0.display();

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
        // one_pass::block_project(&s, {"地区", "死亡"}).display();
        // one_pass::block_choose(&s, testCondition).display();
        // one_pass::block_sort(&s, one_pass::cmp).display();

        segment s0(schema0, 16);c(s0.add_rows(row60));
        segment s1(schema1, 16);c(s1.add_rows(row61));
        segment s2(schema2, 32);c(s2.add_rows(row62));
        // one_pass::block_product(&s0, &s2).display();
        // one_pass::block_product(&s1, &s2).display();
        one_pass::block_connect(&s1, &s2, one_pass::equal).display();

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
    // test of segment
    int test_segment() {
        segment s0("../test/simples/test.yml");
        segment s1(epidemic_schema, 7);c(s1.add_rows(row6));

        c(s0.read_column("地区")[0]);
        c(s1.read_column("地区")[0]);
        c(s0.read_column("地区")[5]);
        c(s1.read_column("地区")[5]);
        c(s0.read_column("地区")[6]);
        c(s1.read_column("地区")[6]);

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

        c(s0.seg["地区"].IsSequence());
        c(s1.seg["地区"].IsSequence());

        c(s0.add_rows(row6));
        c(s1.add_rows(row6));
        c(s0.seg["地区"]);
        c(s1.seg["地区"]);

        c(s0.seg["地区"].IsSequence());
        c(s1.seg["地区"].IsSequence());

        // s0.display();
        // s1.display();

        // std::cout<<seg.lines()<<std::endl;
        //seg.write_node("../test/simples/test.yml");
        return 0;
    }*/
    // test of yaml-cpp/yaml.h
    int test_yaml_cpp(){
        YAML::Node node;
        assert(node.IsNull());  //初始化的节点是Null类型
        node["key"] = "value";  //当你给它赋值键值对，它转变为Map类型
        //node.force_insert("key", "value");//这个操作和上面等价，但是它不会检查是否存在"key"键，不推荐使用
        if(node["mascot"])
            std::cout << node["mascot"].as<std::string>() << "\n";//单纯的查询操作不会增加一个key，当然上面的if不会执行

        node["number"] = 255;
        assert(node.IsMap());   //node是一个Map
        node["seq"].push_back("first element");
        node["seq"].push_back("second element");//node的seq下是Sequence类型，有两个参数

        YAML::Node node_2;
        node_2.push_back("first item");//如果你不给node_2键值对，它是一个sequence类型
        node_2.push_back("second_item");
        node_2.push_back("third_item");
        std::vector<int> v = {1,3,5,7,9};//给node_2插入了一个Sequence
        node_2.push_back(v);
        assert(node_2.IsSequence());//当然，node_2仍然是一个Sequence

        assert(node_2[0].as<std::string>() == "first item");
        //对于Sequence类型，你可以使用它的下标来访问
        //注意这里as<T>是一个模板转换，node_2[0]的type是NodeType::Scalar

        //auto it = node_2.begin();
        //for(; it != node_2.end(); it++)
        //    std::cout << *(it) << std::endl;
        std::cout<<node_2;

        //当然，你也可以用迭代器来访问
        //他们的类型分别是NodeType::Scalar，NodeType::Scalar，NodeType::Scalar，NodeType::Sequence
        //取值时记得使用as进行模板转换
        node_2["key"] = "value";
        assert(node_2.IsMap());//一旦node_2接收到键值对，它转变为Map类型
        assert(node_2[0].as<std::string>() == "first item");//此时，Sequence时的下标变为它的key值
        node["node_2"] = node_2;//将node_2作为node的一个子项
        node["pointer_to_first_element"] = node["seq"][0];//你也可以给已有的node设置一个别名，类似于一个指针
        assert(node["pointer_to_first_element"].as<std::string>() == "first element");//你可以通过这个指针访问那个node

        std::cout<<node;

        node.remove(node["seq"][0]);//你可以通过指定一个node来删除它
        node.remove("pointer_to_first_element");//你也可以通过指定key来删除它

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
        //YAML::Node inode = YAML::Load(ifile);//读取来自test.yml的node文件
        //std::cout << inode <<std::endl;
        //YAML::Node inode_2 = YAML::LoadFile("simples/test.yml");//也可以这样读取文件
        //std::cout << inode_2["node_2"] <<std::endl;//可以直接用下标访问
        //for(auto it = inode_2.begin(); it != inode_2.end(); it++)
        //    std::cout << it->first << it->second << std::endl;//也可以用迭代器访问

        return 0;
    }
    // test
};


#endif //OPERATORS_TEST_H

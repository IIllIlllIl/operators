//
// Created by Phoenix Wang on 2022/4/22.
//
// test.h
// non-functional tests


#ifndef OPERATORS_NON_FUNCTIONAL_H
#define OPERATORS_NON_FUNCTIONAL_H


#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "../test/test_data.h"
#include "../lib/operators.h"
#include "test.h"
#include <ctime>


#define c(x) std::cout<<#x<<": "<<x<<std::endl


// data (index)
std::vector<std::vector<int>> testIndex6 ={
        {11404617, 0, 0},
        {16149319, 0, 1},
        {17730556, 0, 2},
        {24553950, 0, 3},
        {40371500, 0, 4},
        {74176403, 0, 5}
};
std::vector<std::vector<int>> testIndex32 ={
        {2175793, 0, 0},
        {2203208, 0, 1},
        {2359254, 0, 2},
        {2377818, 0, 3},
        {2390397, 0, 4},
        {2407022, 0, 5},
        {2599456, 0, 6},
        {2844969, 0, 7},
        {2888827, 0, 8},
        {2939439, 0, 9},
        {2979643, 0, 10},
        {3070357, 0, 11},
        {3493447, 0, 12},
        {3590399, 0, 13},
        {3946202, 0, 14},
        {4067075, 0, 15},
        {4309270, 0, 16},
        {4695435, 0, 17},
        {4779296, 0, 18},
        {5798799, 0, 19},
        {6279410, 0, 20},
        {8130023, 0, 21},
        {9145274, 0, 22},
        {9529320, 0, 23},
        {10383561, 0, 24},
        {11167927, 0, 25},
        {11404617, 0, 26},
        {16149319, 0, 27},
        {17730556, 0, 28},
        {24553950, 0, 29},
        {40371500, 0, 30},
        {74176403, 0, 31}
};
std::vector<std::vector<int>> testIndex64 ={
        {668209, 0, 0},
        {669860, 0, 1},
        {677214, 0, 2},
        {690244, 0, 3},
        {691898, 0, 4},
        {734078, 0, 5},
        {777497, 0, 6},
        {833201, 0, 7},
        {835170, 0, 8},
        {866445, 0, 9},
        {882783, 0, 10},
        {899174, 0, 11},
        {913592, 0, 12},
        {939267, 0, 13},
        {957633, 0, 14},
        {1031170, 0, 15},
        {1110168, 0, 16},
        {1114527, 0, 17},
        {1159271, 0, 18},
        {1177165, 0, 19},
        {1192211, 0, 20},
        {1393887, 0, 21},
        {1468964, 0, 22},
        {1490489, 0, 23},
        {1598910, 0, 24},
        {1727661, 0, 25},
        {1731524, 0, 26},
        {1848223, 0, 27},
        {1973485, 0, 28},
        {2020082, 0, 29},
        {2037794, 0, 30},
        {2083151, 0, 31},
        {2175793, 1, 0},
        {2203208, 1, 1},
        {2359254, 1, 2},
        {2377818, 1, 3},
        {2390397, 1, 4},
        {2407022, 1, 5},
        {2599456, 1, 6},
        {2844969, 1, 7},
        {2888827, 1, 8},
        {2939439, 1, 9},
        {2979643, 1, 10},
        {3070357, 1, 11},
        {3493447, 1, 12},
        {3590399, 1, 13},
        {3946202, 1, 14},
        {4067075, 1, 15},
        {4309270, 1, 16},
        {4695435, 1, 17},
        {4779296, 1, 18},
        {5798799, 1, 19},
        {6279410, 1, 20},
        {8130023, 1, 21},
        {9145274, 1, 22},
        {9529320, 1, 23},
        {10383561, 1, 24},
        {11167927, 1, 25},
        {11404617, 1, 26},
        {16149319, 1, 27},
        {17730556, 1, 28},
        {24553950, 1, 29},
        {40371500, 1, 30},
        {74176403, 1, 31}
};

// init
void init3() {
    std::string path = "../test/non-functional/3/6";
    table t6(path, epidemic_schema_E, 32, 8);
    segment b0(epidemic_schema_E, 32);
    b0.add_rows(row6_E);
    t6.addBlock(&b0);
}

void init1() {
    std::string path = "../test/non-functional/3/6";
    std::string path1 = "../test/non-functional/3/32";
    std::string path2 = "../test/non-functional/3/64";
    table t6(path, 8);
    table t32(path1, 8);
    table t64(path2, 8);
    // one_pass::project(&t6, {"region", "new", "cumulative"})->display();
    // one_pass::project(&t6, {"cumulative", "cured", "death"})->display();
    // one_pass::project(&t32, {"region", "new", "cumulative"})->display();
    // one_pass::project(&t32, {"cumulative", "cured", "death"})->display();
    // one_pass::project(&t64, {"region", "new", "cumulative"})->display();
    // one_pass::project(&t64, {"cumulative", "cured", "death"})->display();
}

void index() {
    std::string path = "../test/non-functional/1/6-0";
    std::string path1 = "../test/non-functional/1/32-0";
    std::string path2 = "../test/non-functional/1/64-0";
    table t6(path, 8);
    table t32(path1, 8);
    table t64(path2, 8);
    // multiway_merge::sort_pthread(&t6, multiway_merge::cmp0)->display();
    // multiway_merge::sort_pthread(&t32, multiway_merge::cmp0)->display();
    // multiway_merge::sort_pthread(&t64, multiway_merge::cmp0)->display();
}

void indexVec() {
    std::string path = "../test/non-functional/1/6i";
    std::string path1 = "../test/non-functional/1/32i";
    table t6(path, 8);
    table t32(path1, 8);
    std::vector<std::vector<std::string>> i6, i32;
    i6 = t6.dp();
    i32 = t32.dp();
    for (int i = 0; i < 32; i++) {
        std::cout << "{" << i32[i][2] << ", 0, " << i << "}," << std::endl;
    }
}

std::vector<std::vector<std::string>> testFind(std::vector<std::string> vec) {
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

// test
void test1(){
    // init
    double t, ave;
    clock_t begin, end;

    std::string path60 = "../test/non-functional/1/6-0";
    std::string path61 = "../test/non-functional/1/6-1";
    std::string path6i = "../test/non-functional/1/6i";
    std::string path320 = "../test/non-functional/1/32-0";
    std::string path321 = "../test/non-functional/1/32-1";
    std::string path32i = "../test/non-functional/1/32i";
    std::string path640 = "../test/non-functional/1/64-0";
    std::string path641 = "../test/non-functional/1/64-1";
    std::string path64i = "../test/non-functional/1/64i";
    table tb60(path60, 256);
    table tb61(path61, 256);
    table tb6i(path6i, 256);
    table tb320(path320, 256);
    table tb321(path321, 256);
    table tb32i(path32i, 256);
    table tb640(path640, 256);
    table tb641(path641, 256);
    table tb64i(path64i, 256);

    // test
    for (int i = 0; i < 10; i++) {
        begin = clock();
        // one_pass::connect(&tb60, &tb61, one_pass::equal);
        // one_pass::connect(&tb320, &tb321, one_pass::equal);
        // one_pass::connect(&tb640, &tb641, one_pass::equal);

        /*
        multiway_merge::connect(&tb60, &tb61,
                                multiway_merge::cmp0, multiway_merge::cmp1, multiway_merge::cmp,
                                one_pass::equal);*/
        /*
        multiway_merge::connect(&tb320, &tb321,
                                multiway_merge::cmp0, multiway_merge::cmp1, multiway_merge::cmp,
                                one_pass::equal);*/
        /*
        multiway_merge::connect(&tb640, &tb641,
                                multiway_merge::cmp0, multiway_merge::cmp1, multiway_merge::cmp,
                                one_pass::equal);*/

        // index_based::connect(&tb6i, &tb61, testFind);
        // index_based::connect(&tb32i, &tb321, testFind);
        // index_based::connect(&tb64i, &tb641, testFind);
        end = clock();
        t = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        std::cout << t << " ,";
        ave += t/10;
    }
    std::cout << "average: " << ave;
}

void test2(){
    // init
    double t, ave;
    clock_t begin, end;

    std::string path = "../test/non-functional/2/6";
    std::string path1 = "../test/non-functional/2/32";
    std::string path2 = "../test/non-functional/2/64";
    table tb6(path, 8);
    table tb32(path1, 8);
    table tb64(path2, 8);

    // test
    for (int i = 0; i < 10; i++) {
        begin = clock();
        // multiway_merge::sort(&tb6, multiway_merge::cmp0);
        // multiway_merge::sort(&tb32, multiway_merge::cmp0);
        // multiway_merge::sort(&tb64, multiway_merge::cmp0);

        // multiway_merge::sort_pthread(&tb6, multiway_merge::cmp0);
        // multiway_merge::sort_pthread(&tb32, multiway_merge::cmp0);
        // multiway_merge::sort_pthread(&tb64, multiway_merge::cmp0);
        end = clock();
        t = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        std::cout << t << " ,";
        ave += t/10;
    }
    std::cout << "average: " << ave;
}

void test3() {
    // init
    double t, ave;
    clock_t begin, end;

    std::string path = "../test/non-functional/3/6";
    std::string path1 = "../test/non-functional/3/32";
    std::string path2 = "../test/non-functional/3/64";
    table tb6(path, 8);
    table tb32(path1, 8);
    table tb64(path2, 8);

    std::vector<stream*> st;
    test tt;
    stream* p = new stream_choose(tt.testCondition);
    st.push_back(p);
    p = new stream_project({"region", "new"});
    st.push_back(p);

    // test
    for (int i = 0; i < 10; i++) {
        begin = clock();
        // one_pass::choose(&tb6, tt.testCondition);
        // one_pass::project(&tb6, {"region", "new"});
        // one_pass::choose(&tb32, tt.testCondition);
        // one_pass::project(&tb32, {"region", "new"});
        // one_pass::choose(&tb64, tt.testCondition);
        // one_pass::project(&tb64, {"region", "new"});

        // one_pass::stream_operators(&tb6, st);
        // one_pass::stream_operators(&tb32, st);
        // one_pass::stream_operators(&tb64, st);
        end = clock();
        t = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        std::cout << t << " ,";
        ave += t/10;
    }
    std::cout << "average: " << ave;
}


#endif //OPERATORS_NON_FUNCTIONAL_H

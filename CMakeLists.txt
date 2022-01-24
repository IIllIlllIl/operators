cmake_minimum_required(VERSION 3.19)
project(operators)

set(CMAKE_CXX_STANDARD 14)

add_executable(operators main.cpp file_io.cpp file_io.h)

#json
INCLUDE_DIRECTORIES(  /opt/homebrew/Cellar/jsoncpp/1.9.4_1/include )
LINK_DIRECTORIES(  /opt/homebrew/Cellar/jsoncpp/1.9.4_1/lib )

file(GLOB LIBRARIES "/opt/homebrew/Cellar/jsoncpp/1.9.4_1/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(operators ${LIBRARIES})

#yaml
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})
target_link_libraries(operators yaml-cpp)




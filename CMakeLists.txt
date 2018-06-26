cmake_minimum_required(VERSION 2.8.10)
project(libfp C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/libfp/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/output/include/libfp/
    FILES_MATCHING 
    PATTERN "*.h"
    )

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/output/include/
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.h"
    )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/output/bin)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/libfp/")
add_executable(demo "${CMAKE_CURRENT_SOURCE_DIR}/src/demo.cpp")

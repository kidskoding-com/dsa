cmake_minimum_required(VERSION 3.30)
project(dsa_kidskoding_com)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(dsa_kidskoding_com 
    src/main.cpp
    src/algorithms/searching.cpp
)

add_subdirectory(tests)

cmake_minimum_required(VERSION 3.30)
project(dsa_kidskoding_com)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(lib/googletest/googletest/include)

add_subdirectory(lib/googletest)

add_executable(dsa_kidskoding_com src/main.cpp
        src/algorithms/searching.cpp)
target_link_libraries(dsa_kidskoding_com gtest gtest_main)

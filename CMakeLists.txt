cmake_minimum_required(VERSION 3.30)
project(dsa_kidskoding_com)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB TEST_FILES *.cpp)
file(GLOB SRC_FILES
        ${PROJECT_SOURCE_DIR}/src/algorithms/*.cpp
        ${PROJECT_SOURCE_DIR}/src/data_structures/*.cpp
)

add_executable(dsa_kidskoding_com ${SRC_FILES} ${TEST_FILES})

add_subdirectory(tests)

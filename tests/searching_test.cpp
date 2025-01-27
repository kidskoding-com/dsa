#include <gtest/gtest.h>
#include "../include/algorithms/searching.h"

TEST(all_tests, LinearSearchTest) {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = linearSearch(data, std::size(data), 10);
    int result_exist = linearSearch(data, std::size(data), 1);

    EXPECT_EQ(result, -1);
    EXPECT_EQ(result_exist, 0);
}

TEST(all_tests, BinarySearchTest) {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = binarySearch(data, std::size(data), 10);
    int result_exist = binarySearch(data, std::size(data), 1);

    EXPECT_EQ(result, -1);
    EXPECT_EQ(result_exist, 0);
}

#include <gtest/gtest.h>
#include "../include/algorithms/searching.h"

TEST(SearchingTest, LinearSearchTest) {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = linearSearch(data, 10);
    int result_exist = linearSearch(data, 1);

    EXPECT_EQ(result, -1);
    EXPECT_EQ(result_exist, 0);
}

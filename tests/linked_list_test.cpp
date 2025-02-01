#include <gtest/gtest.h>
#include "data_structures/linked_list.h"

TEST(LinkedListTest, PushFront) {
    LinkedList<int> list;
    list.pushFront(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.popFront(), 10);
}

TEST(LinkedListTest, PopFront) {
    LinkedList<int> list;
    list.pushFront(20);
    list.pushFront(30);
    EXPECT_EQ(list.popFront(), 30);
    EXPECT_EQ(list.popFront(), 20);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, IsEmpty) {
    LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    list.pushFront(40);
    EXPECT_FALSE(list.isEmpty());
    list.popFront();
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, PopFrontEmptyList) {
    LinkedList<int> list;
    EXPECT_THROW(list.popFront(), std::runtime_error);
}

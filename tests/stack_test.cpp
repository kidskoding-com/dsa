#include <gtest/gtest.h>
#include "data_structures/stack.hpp"

class StackTest : public testing::Test {
protected:
    Stack<int> stack;
};

TEST_F(StackTest, PushAndGetSize) {
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.getSize(), 3);
}

TEST_F(StackTest, Pop) {
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

TEST_F(StackTest, Peek) {
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.peek(), 2);
    stack.pop();
    EXPECT_EQ(stack.peek(), 1);
}

TEST_F(StackTest, IsEmpty) {
    EXPECT_TRUE(stack.isEmpty());
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(StackTest, StackOverflow) {
    for (int i = 0; i < 100; ++i) {
        stack.push(i);
    }
    EXPECT_THROW(stack.push(101), std::runtime_error);
}
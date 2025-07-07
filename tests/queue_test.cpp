#include <gtest/gtest.h>
#include "data_structures/queue.hpp"

TEST(QueueTest, Enqueue) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.getSize(), 3);
    EXPECT_EQ(q.peek(), 1);
}

TEST(QueueTest, Dequeue) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.getSize(), 2);
    EXPECT_EQ(q.peek(), 2);
}

TEST(QueueTest, Peek) {
    Queue<int> q;
    q.enqueue(1);
    EXPECT_EQ(q.peek(), 1);
    q.enqueue(2);
    EXPECT_EQ(q.peek(), 1);
    q.dequeue();
    EXPECT_EQ(q.peek(), 2);
}

TEST(QueueTest, IsEmpty) {
    Queue<int> q;
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(1);
    EXPECT_FALSE(q.isEmpty());
    q.dequeue();
    EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTest, GetSize) {
    Queue<int> q;
    EXPECT_EQ(q.getSize(), 0);
    q.enqueue(1);
    EXPECT_EQ(q.getSize(), 1);
    q.enqueue(2);
    EXPECT_EQ(q.getSize(), 2);
    q.dequeue();
    EXPECT_EQ(q.getSize(), 1);
}
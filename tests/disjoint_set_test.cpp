#include "gtest/gtest.h"
#include "../include/data_structures/disjoint_set.hpp"
#include <memory>

TEST(DisjointSetTest, MakeFind) {
    DisjointSet<int> ds;

    auto a = std::make_shared<int>(1);
    auto b = std::make_shared<int>(2);
    auto c = std::make_shared<int>(3);

    ds.makeSet(a);
    ds.makeSet(b);
    ds.makeSet(c);

    EXPECT_EQ(ds.find(a), a);
    EXPECT_EQ(ds.find(b), b);
    EXPECT_EQ(ds.find(c), c);
}

TEST(DisjointSetTest, UnionFind) {
    DisjointSet<int> ds;

    auto a = std::make_shared<int>(10);
    auto b = std::make_shared<int>(20);
    auto c = std::make_shared<int>(30);

    ds.makeSet(a);
    ds.makeSet(b);
    ds.makeSet(c);

    ds.unionSet(a, b);
    EXPECT_EQ(ds.find(a), ds.find(b));

    ds.unionSet(b, c);
    EXPECT_EQ(ds.find(a), ds.find(c));
}

TEST(DisjointSetTest, NoDuplicateUnion) {
    DisjointSet<char> ds;

    auto a = std::make_shared<char>('x');
    auto b = std::make_shared<char>('y');

    ds.makeSet(a);
    ds.makeSet(b);

    EXPECT_TRUE(ds.unionSet(a, b));
    EXPECT_FALSE(ds.unionSet(a, b));
    EXPECT_EQ(ds.find(a), ds.find(b));
}

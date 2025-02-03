#include <gtest/gtest.h>
#include "data_structures/tree.h"

TEST(BinaryTreeTest, InsertSingleElement) {
    BinaryTree<int> tree;
    tree.insert(10);
    ASSERT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->value, 10);
}

TEST(BinaryTreeTest, InsertMultipleElements) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_EQ(tree.root->value, 10);
    EXPECT_EQ(tree.left->root->value, 5);
    EXPECT_EQ(tree.right->root->value, 15);
}

TEST(BinaryTreeTest, InsertDuplicateElements) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(10);

    EXPECT_EQ(tree.root->value, 10);
    EXPECT_EQ(tree.right->root->value, 10);
}
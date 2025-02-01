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

    ASSERT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->value, 10);
    ASSERT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->value, 5);
    ASSERT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->value, 15);
}

TEST(BinaryTreeTest, InsertDuplicateElements) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(10);

    ASSERT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->value, 10);
    ASSERT_EQ(tree.root->left, nullptr);
    ASSERT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->value, 10);
}
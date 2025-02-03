#include <gtest/gtest.h>
#include <data_structures/tree.h>
#include <algorithms/tree_traversal.h>

TEST(TreeTraversalTest, LevelOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> result = levelOrderTraversal(&tree);

    EXPECT_EQ(result, expected);
}

TEST(TreeTraversalTest, PreOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> result = preOrderTraversal(&tree);

    EXPECT_EQ(result, expected);
}

TEST(TreeTraversalTest, InOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(12);
    tree.insert(1);
    tree.insert(15);

    std::vector<int> expected = {1, 5, 10, 12, 15};
    std::vector<int> result = inOrderTraversal(&tree);

    EXPECT_EQ(result, expected);
}

TEST(TreeTraversalTest, PostOrderTraversal) {
    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    std::vector<int> expected = {5, 4, 3, 2, 1};
    std::vector<int> result = postOrderTraversal(&tree);

    EXPECT_EQ(result, expected);
}
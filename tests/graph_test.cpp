#include <gtest/gtest.h>
#include "data_structures/graph.h"

TEST(GraphTest, AddNode) {
    Graph<int> graph;
    auto node = new GraphNode<int>(1);
    graph.addNode(node);

    ASSERT_EQ(graph.graph.size(), 1);
    ASSERT_EQ(graph.graph[node].size(), 0);
}

TEST(GraphTest, RemoveNode) {
    Graph<int> graph;
    auto node = new GraphNode<int>(1);
    graph.addNode(node);
    graph.removeNode(node);

    ASSERT_EQ(graph.graph.size(), 0);
}

TEST(GraphTest, AddEdge) {
    Graph<int> graph;
    auto node1 = new GraphNode<int>(1);
    auto node2 = new GraphNode<int>(2);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addEdge(node1, node2, 10);

    ASSERT_EQ(graph.graph[node1].size(), 1);
    ASSERT_EQ(graph.graph[node2].size(), 1);
    ASSERT_EQ(std::get<1>(graph.graph[node1][0]), 10);
    ASSERT_EQ(std::get<1>(graph.graph[node2][0]), 10);
}

TEST(GraphTest, RemoveEdge) {
    Graph<int> graph;
    auto node1 = new GraphNode<int>(1);
    auto node2 = new GraphNode<int>(2);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addEdge(node1, node2, 10);
    graph.removeEdge(node1, node2);

    ASSERT_EQ(graph.graph[node1].size(), 0);
    ASSERT_EQ(graph.graph[node2].size(), 0);
}

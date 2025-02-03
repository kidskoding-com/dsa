#include <gtest/gtest.h>
#include "data_structures/graph.h"
#include "algorithms/graph_traversal.h"

TEST(GraphTraversalTest, BreadthFirstSearch) {
	auto* node1 = new GraphNode<int>(1);
	auto* node2 = new GraphNode<int>(2);
	auto* node3 = new GraphNode<int>(3);
	auto* node4 = new GraphNode<int>(4);
	auto* node5 = new GraphNode<int>(5);

	Graph<int> graph;
	graph.addNode(node1);
	graph.addNode(node2);
	graph.addNode(node3);
	graph.addNode(node4);
	graph.addNode(node5);

	graph.addEdge(node1, node2, 0);
	graph.addEdge(node1, node3, 0);
	graph.addEdge(node2, node4, 0);
	graph.addEdge(node2, node5, 0);

	std::vector<int> result = breadthFirstSearch(graph, node1);
	std::vector<int> expected = {1, 2, 3, 4, 5};

	ASSERT_EQ(result.size(), expected.size());
	for(size_t i = 0; i < result.size(); ++i) {
		EXPECT_EQ(result[i], expected[i]);
	}
}

TEST(GraphTraversalTest, DepthFirstSearch) {
	auto* node1 = new GraphNode<int>(1);
	auto* node2 = new GraphNode<int>(2);
	auto* node3 = new GraphNode<int>(3);
	auto* node4 = new GraphNode<int>(4);
	auto* node5 = new GraphNode<int>(5);

	Graph<int> graph;
	graph.addNode(node1);
	graph.addNode(node2);
	graph.addNode(node3);
	graph.addNode(node4);
	graph.addNode(node5);

	graph.addEdge(node1, node2, 0);
	graph.addEdge(node1, node3, 0);
	graph.addEdge(node2, node4, 0);
	graph.addEdge(node2, node5, 0);

	std::vector<int> result = depthFirstSearch(graph, node1);
	std::vector<int> expected = {1, 3, 2, 5, 4};

	ASSERT_EQ(result.size(), expected.size());
	for(size_t i = 0; i < result.size(); ++i) {
		EXPECT_EQ(result[i], expected[i]);
	}
}

TEST(GraphTraversalTest, Dijkstra) {
	auto* node1 = new GraphNode<int>(1);
	auto* node2 = new GraphNode<int>(2);
	auto* node3 = new GraphNode<int>(3);
	auto* node4 = new GraphNode<int>(4);
	auto* node5 = new GraphNode<int>(5);

	Graph<int> graph;
	graph.addNode(node1);
	graph.addNode(node2);
	graph.addNode(node3);
	graph.addNode(node4);
	graph.addNode(node5);

	graph.addEdge(node1, node2, 1);
	graph.addEdge(node1, node3, 4);
	graph.addEdge(node2, node4, 2);
	graph.addEdge(node2, node5, 5);
	graph.addEdge(node4, node5, 1);

	std::map<GraphNode<int>*, int> result = dijkstra(graph, node1);
	std::map<GraphNode<int>*, int> expected = {
		{node1, 0},
		{node2, 1},
		{node3, 4},
		{node4, 3},
		{node5, 4}
	};

	ASSERT_EQ(result.size(), expected.size());
	for(const auto& [node, distance] : expected) {
		EXPECT_EQ(result[node], distance);
	}	
}
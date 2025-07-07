#include <gtest/gtest.h>
#include <memory>
#include "data_structures/graph.hpp"
#include "algorithms/graph_traversal.hpp"

TEST(GraphTraversalTest, BreadthFirstSearch) {
	auto node1 = std::make_shared<GraphNode<int>>(1);
	auto node2 = std::make_shared<GraphNode<int>>(2);
	auto node3 = std::make_shared<GraphNode<int>>(3);
	auto node4 = std::make_shared<GraphNode<int>>(4);
	auto node5 = std::make_shared<GraphNode<int>>(5);

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
	auto node1 = std::make_shared<GraphNode<int>>(1);
	auto node2 = std::make_shared<GraphNode<int>>(2);
	auto node3 = std::make_shared<GraphNode<int>>(3);
	auto node4 = std::make_shared<GraphNode<int>>(4);
	auto node5 = std::make_shared<GraphNode<int>>(5);

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
	auto node1 = std::make_shared<GraphNode<int>>(1);
	auto node2 = std::make_shared<GraphNode<int>>(2);
	auto node3 = std::make_shared<GraphNode<int>>(3);
	auto node4 = std::make_shared<GraphNode<int>>(4);
	auto node5 = std::make_shared<GraphNode<int>>(5);

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

	std::map<std::shared_ptr<GraphNode<int>>, int> result = dijkstra(graph, node1);
	std::map<std::shared_ptr<GraphNode<int>>, int> expected = {
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

TEST(GraphTraversalTest, BellmanFord) {
    auto node1 = std::make_shared<GraphNode<int>>(1);
    auto node2 = std::make_shared<GraphNode<int>>(2);
    auto node3 = std::make_shared<GraphNode<int>>(3);
    auto node4 = std::make_shared<GraphNode<int>>(4);
    auto node5 = std::make_shared<GraphNode<int>>(5);

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

    std::map<std::shared_ptr<GraphNode<int>>, int> result = bellmanFord(graph, node1);
    std::map<std::shared_ptr<GraphNode<int>>, int> expected = {
        {node1, 0},
        {node2, 1},
        {node3, 4},
        {node4, 3},
        {node5, 4}
    };

    ASSERT_EQ(result.size(), expected.size());
    for (const auto& [node, distance] : expected) {
        EXPECT_EQ(result[node], distance);
    }
}

TEST(GraphTraversalTest, BellmanFordNegativeCycle) {
	auto node1 = std::make_shared<GraphNode<int>>(1);
	auto node2 = std::make_shared<GraphNode<int>>(2);
	auto node3 = std::make_shared<GraphNode<int>>(3);
	auto node4 = std::make_shared<GraphNode<int>>(4);
	auto node5 = std::make_shared<GraphNode<int>>(5);

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
	graph.addEdge(node5, node3, -7);

	try {
		bellmanFord(graph, node1);
		FAIL() << "Expected std::runtime_error";
	} catch (const std::runtime_error& e) {
		EXPECT_STREQ("Graph contains a negative weight cycle! Bellman-Ford will not be accurate for this graph!", e.what());
	} catch (...) {
		FAIL() << "Expected std::runtime_error";
	}
}

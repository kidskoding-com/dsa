#include "gtest/gtest.h"
#include "../include/data_structures/graph.hpp"
#include "../include/algorithms/mst.hpp"
#include <memory>

static bool edgeExists(
    const std::vector<std::tuple<std::shared_ptr<GraphNode<char>>, 
    std::shared_ptr<GraphNode<char>>, int>>& edges, 
    char from, 
    char to, 
    int weight
) {
    return std::any_of(edges.begin(), edges.end(), [&](const auto& edge) {
        auto [u, v, w] = edge;
        char uval = u->value;
        char vval = v->value;
        return ((uval == from && vval == to) || (uval == to && vval == from) ) && w == weight;
    });
}

TEST(KruskalTest, BasicGraph) {
    Graph<char> graph;

    auto A = std::make_shared<GraphNode<char>>('A');
    auto B = std::make_shared<GraphNode<char>>('B');
    auto C = std::make_shared<GraphNode<char>>('C');
    auto D = std::make_shared<GraphNode<char>>('D');

    graph.addNode(A);
    graph.addNode(B);
    graph.addNode(C);
    graph.addNode(D);

    graph.addEdge(A, B, 1);
    graph.addEdge(B, C, 4);
    graph.addEdge(C, D, 2);
    graph.addEdge(A, C, 3);
    graph.addEdge(B, D, 5);

    auto mstEdges = kruskal(graph);
    EXPECT_EQ(mstEdges.size(), 3);

    EXPECT_TRUE(edgeExists(mstEdges, 'A', 'B', 1));
    EXPECT_TRUE(edgeExists(mstEdges, 'C', 'D', 2));
    EXPECT_TRUE(edgeExists(mstEdges, 'A', 'C', 3));
}

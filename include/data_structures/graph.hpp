#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>

template <typename T>
class GraphNode {
public:
    T value;
    std::vector<std::shared_ptr<GraphNode<T>>> neighbors;

    GraphNode(T val) : value(val) {}
};

template <typename T>
class Graph {
public:
    std::map<std::shared_ptr<GraphNode<T>>,
             std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, int>>> graph;

    Graph() {}

    void addNode(std::shared_ptr<GraphNode<T>> node) {
        this->graph[node]
            = std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, int>>();
    }

    void removeNode(std::shared_ptr<GraphNode<T>> node) {
        for(auto& pair : graph) {
            auto& neighbors = pair.second;
            neighbors.erase(
                std::remove_if(neighbors.begin(), neighbors.end(),
                              [node](const std::tuple<std::shared_ptr<GraphNode<T>>, int>& neighbor) {
                                  return std::get<0>(neighbor) == node;
                              }),
                neighbors.end());
        }

        graph.erase(node);
    }

    void addEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b, int weight) {
        this->graph[a].push_back(std::make_tuple(b, weight));
        this->graph[b].push_back(std::make_tuple(a, weight));
    }

    void removeEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b) {
        auto& neighborsA = this->graph[a];
        neighborsA.erase(
            std::remove_if(neighborsA.begin(), neighborsA.end(),
                          [b](const std::tuple<std::shared_ptr<GraphNode<T>>, int>& neighbor) {
                              return std::get<0>(neighbor) == b;
                          }),
            neighborsA.end());

        auto& neighborsB = this->graph[b];
        neighborsB.erase(
            std::remove_if(neighborsB.begin(), neighborsB.end(),
                          [a](const std::tuple<std::shared_ptr<GraphNode<T>>, int>& neighbor) {
                              return std::get<0>(neighbor) == a;
                          }),
            neighborsB.end());
    }
};

#endif // GRAPH_HPP

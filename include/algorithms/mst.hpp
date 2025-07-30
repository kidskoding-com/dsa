#ifndef MST_HPP
#define MST_HPP

#include "./data_structures/graph.hpp"
#include "./data_structures/disjoint_set.hpp"
#include <vector>
#include <tuple>
#include <algorithm>

template <typename T>
std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>, int>> kruskal(Graph<T>& graph) {
    DisjointSet<GraphNode<T>> set;
    std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>, int>> edges;

    for(const auto& pair : graph.graph) {
        set.makeSet(pair.first);
        for(const auto& [neighbor, weight] : pair.second) {
            if(pair.first < neighbor) {
                edges.emplace_back(pair.first, neighbor, weight);
            }
        }
    }

    std::sort(edges.begin(), edges.end(),
              [](const auto& a, const auto& b) {
                  return std::get<2>(a) < std::get<2>(b);
              });

    std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>, int>> mst;
    for(const auto& [u, v, w] : edges) {
        if(set.unionSet(u, v)) {
            mst.emplace_back(u, v, w);
        }
    }

    return mst;
}

#endif // MST_HPP

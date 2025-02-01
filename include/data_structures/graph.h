#ifndef GRAPH_H
#define GRAPH_H

#include <map>

#include "node.h"

template <typename T>
class GraphNode {
public:
	T value;
	std::vector<GraphNode<T>*> neighbors;

	GraphNode(T val) : value(val) {}
	~GraphNode() {
		for(auto neighbor : neighbors) {
			delete neighbor;
		}
	}
};

template <typename T>
class Graph {
public:
	std::map<GraphNode<T>*, std::vector<std::tuple<GraphNode<T>*, int>>> graph;

	Graph() {}
	~Graph() {
		for(auto& pair : graph) {
			delete pair.first;
		}
		graph.clear();
	}

	void addNode(GraphNode<T>* node) {
		this->graph[node] = std::vector<std::tuple<GraphNode<T>*, int>>();
	}
	
	void removeNode(GraphNode<T>* node) {
		for (auto& pair : graph) {
			auto& neighbors = pair.second;
			neighbors.erase(
				std::remove_if(neighbors.begin(), neighbors.end(),
							   [node](const std::tuple<GraphNode<T>*, int>& neighbor) {
								   return std::get<0>(neighbor) == node;
							   }),
				neighbors.end());
		}

		graph.erase(node);
		delete node;
	}

	void addEdge(GraphNode<T>* a, GraphNode<T>* b, int weight) {
		this->graph[a].push_back(std::make_tuple(b, weight));
		this->graph[b].push_back(std::make_tuple(a, weight));
	}

	void removeEdge(GraphNode<T>* a, GraphNode<T>* b) {
		auto& neighborsA = this->graph[a];
		neighborsA.erase(
			std::remove_if(neighborsA.begin(), neighborsA.end(),
						   [b](const std::tuple<GraphNode<T>*, int>& neighbor) {
							   return std::get<0>(neighbor) == b;
						   }),
			neighborsA.end());

		auto& neighborsB = this->graph[b];
		neighborsB.erase(
			std::remove_if(neighborsB.begin(), neighborsB.end(),
						   [a](const std::tuple<GraphNode<T>*, int>& neighbor) {
							   return std::get<0>(neighbor) == a;
						   }),
			neighborsB.end());	
	}
};

#endif //GRAPH_H
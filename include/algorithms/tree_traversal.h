#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#include <deque>
#include <vector>
#include "data_structures/tree.h"

template <typename T>
std::vector<T> levelOrderTraversal(BinaryTree<T>* tree) {
	std::vector<T> visited;
	if(tree && tree->root) {
		std::deque<BinaryTree<T>*> queue;
		queue.push_back(tree);
		while(!queue.empty()) {
			auto current = queue.front();
			queue.pop_front();
			visited.push_back(current->root->value);
			if(current->left && current->left->root) {
				queue.push_back(current->left);
			}
			if(current->right && current->right->root) {
				queue.push_back(current->right);	
			}
		}
	}

	return visited;
}

template <typename T>
std::vector<T> preOrderTraversal(BinaryTree<T>* tree) {
	std::vector<T> visited;
	if(tree) {
		visited.push_back(tree->root->value);
        std::vector<T> leftTraversal = preOrderTraversal(tree->left);
        visited.insert(visited.end(), leftTraversal.begin(), leftTraversal.end());
        std::vector<T> rightTraversal = preOrderTraversal(tree->right);
        visited.insert(visited.end(), rightTraversal.begin(), rightTraversal.end());
	}
	return visited;
}

template <typename T>
std::vector<T> inOrderTraversal(BinaryTree<T>* tree) {
	std::vector<T> visited;
	if(tree) {
        std::vector<T> leftTraversal = inOrderTraversal(tree->left);
        visited.insert(visited.end(), leftTraversal.begin(), leftTraversal.end());
		visited.push_back(tree->root->value);
        std::vector<T> rightTraversal = inOrderTraversal(tree->right);
        visited.insert(visited.end(), rightTraversal.begin(), rightTraversal.end());
	}
	return visited;
}

template <typename T>
std::vector<T> postOrderTraversal(BinaryTree<T>* tree) {
	std::vector<T> visited;
	if(tree) {
		std::vector<T> leftTraversal = postOrderTraversal(tree->left);
        std::vector<T> rightTraversal = postOrderTraversal(tree->right);
        visited.insert(visited.end(), leftTraversal.begin(), leftTraversal.end());
        visited.insert(visited.end(), rightTraversal.begin(), rightTraversal.end());
		visited.push_back(tree->root->value);
	}
	return visited;
}

#endif //TREE_TRAVERSAL_H
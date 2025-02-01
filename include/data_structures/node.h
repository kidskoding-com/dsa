#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
	T value;
	Node<T>* next;
	
	Node(T value) : value(value), next(nullptr) { }
	Node(T value, Node<T>* next) : value(value), next(next) { }
	~Node() = default;
};

#endif //NODE_H
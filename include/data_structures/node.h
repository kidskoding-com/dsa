#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
	T value;
	Node<T>* next;
public:
	Node(T value) : value(value), next(nullptr) { }
	~Node() {
		delete next;
	}
};

#endif //NODE_H
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "data_structures/node.h"

template <typename T>
class LinkedList {
	Node<T>* head;
public:
	LinkedList() : head(nullptr) { }
	~LinkedList() { delete head; }

	void pushFront(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}
	
	T popFront() {
		if(this->isEmpty()) {
			throw std::runtime_error("No such element");
		}
		Node<T>* oldHead = head;
		head = head->next;
		oldHead->next = nullptr;
		T value = oldHead->value;
		delete oldHead;
		return value;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
};

#endif //LINKED_LIST_H

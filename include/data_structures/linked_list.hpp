#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>
#include "node.hpp"

template <typename T>
class LinkedList {
	Node<T>* head;
public:
	LinkedList() : head(nullptr) { }
	
	~LinkedList() {
		while(head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

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
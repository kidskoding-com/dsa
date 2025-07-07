#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>
#include "node.hpp"

template <typename T>
class Queue {
public:
	Node<T>* front;
	Node<T>* rear;
	unsigned int size;

	Queue() : front(nullptr), rear(nullptr), size(0) {}
	~Queue() {
		while(front) {
			Node<T>* temp = front;
			front = front->next;
			delete temp;
		}
		rear = nullptr;
	}

	void enqueue(T value) {
		Node<T>* newNode = new Node<T>(value);
		if(rear == nullptr) {
			front = newNode;
			rear = newNode;
		} else {
			rear->next = newNode;
			rear = newNode;
		}

		size += 1;
	}

	T dequeue() {
		if(front == nullptr) {
			throw std::runtime_error("No such element");
		}

		Node<T>* oldFront = front;
		front = front->next;
		if(front == nullptr) {
			rear = nullptr;
		}

		size -= 1;
		return oldFront->value;
	}

	T peek() {
		if(front == nullptr) {
			throw std::runtime_error("No such element");
		}
		return front->value;
	}

	bool isEmpty() {
		return this->size == 0;
	}
	unsigned int getSize() {
		return this->size;
	}
};

#endif // QUEUE_HPP
#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
class Stack {
public:
	T* data;
	unsigned int top;
	unsigned int capacity;

	Stack() : top(-1), capacity(100) { this->data = new T[this->capacity]; }
	~Stack() { delete[] this->data; }

	void push(T value) {
		if(this->top + 1 >= this->capacity) {
			throw std::runtime_error("Stack overflow");
		}
		this->data[++this->top] = value;
	}

	T peek() {
		if(isEmpty()) {
			throw std::runtime_error("No such element");
		}
		return this->data[this->top];
	}
	
	T pop() {
		if(isEmpty()) {
			throw std::runtime_error("No such element");
		}
		return this->data[this->top--];
	}

	bool isEmpty() {
		return this->top == -1;
	}
	unsigned int getSize() {
		return this->top + 1;
	}
};

#endif // STACK_HPP
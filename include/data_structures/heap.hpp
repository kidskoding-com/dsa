#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

template <typename T>
class Heap {
public:
	std::vector<T> values;
	bool isMaxHeap;

	Heap(bool isMaxHeap) { this->isMaxHeap = isMaxHeap; }
	~Heap() { values.clear(); }

	void insert(T value) {
		values.push_back(value);
		int index = values.size() - 1;
		int parent = (index - 1) / 2;

		while(index > 0 && (isMaxHeap ?
			values[index] > values[parent]
			: values[index] < values[parent])) {

			std::swap(values[index], values[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
	}
	
	void buildHeap() {
		int length = values.size();
		for(int i = (values.size() / 2) - 1; i >= 0; --i) {
            siftDown(i, length);
        }
	}

	void siftDown(unsigned int index, unsigned int length) {
		unsigned int leftChild = (2 * index) + 1;
		unsigned int rightChild = (2 * index) + 2;
		int largestOrSmallest = index;

		if(leftChild < length) {
			bool compareResult = isMaxHeap ? values[leftChild] > values[largestOrSmallest]
				: values[leftChild] < values[largestOrSmallest];
			if(compareResult) {
				largestOrSmallest = leftChild;
			}
		}
		
		if(rightChild < length) {
			bool compareResult = isMaxHeap ? values[rightChild] > values[largestOrSmallest]
                : values[rightChild] < values[largestOrSmallest];
			if(compareResult) {
				largestOrSmallest = rightChild;
			}
        }

		if(largestOrSmallest != index) {
			std::swap(values[index], values[largestOrSmallest]);
			siftDown(largestOrSmallest, length);
		}
	}
};

#endif // HEAP_HPP
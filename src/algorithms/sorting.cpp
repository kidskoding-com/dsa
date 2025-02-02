#include "algorithms/sorting.h"
#include <algorithm>

void bubbleSort(std::vector<int>& array) {
    for(int i = 0; i < array.size() - 1; i++) {
        for(int j = 1; j < array.size() - i; j++) {
            if(array[j] < array[j - 1]) {
                std::swap(array[j], array[j - 1]);
            }
        }
    }
}

void insertionSort(std::vector<int>& array) {
    for(int i = 1; i < array.size(); i++) {
        int j = i;
        while(j > 0 && array[j - 1] > array[j]) {
            std::swap(array[j], array[j - 1]);
            j -= 1;
        }
    }
}

void selectionSort(std::vector<int>& array) {
    for(int i = 0; i < array.size(); i++) {
        int minIndex = i;
        for(int j = i + 1; j < array.size(); j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

void mergeSort(std::vector<int>& array) {
    if(array.size() <= 1) {
        return;
    }
    
    int mid = array.size() / 2;
    std::vector<int> left({array.begin(), array.begin() + mid});
    std::vector<int> right({array.begin() + mid, array.end()});
    
    mergeSort(left);
    mergeSort(right);
    merge(array, left, right);
}
void merge(std::vector<int>& array, std::vector<int>& left, std::vector<int>& right) {
    int i = 0, j = 0, k = 0;

    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i += 1;
        } else {
            array[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    while(i < left.size()) {
        array[k] = left[i];
        i += 1;
        k += 1;
    }

    while(j < right.size()) {
        array[k] = right[j];
        j += 1;
        k += 1;
    }
}

void quickSort(std::vector<int>& array) {
    if(array.size() <= 1) {
        return;
    }

    quickSortHelper(array, 0, array.size() - 1);
}
void quickSortHelper(std::vector<int>& array, int low, int high) {
    if(low < high) {
        int pivotIndex = partition(array, low, high);
        quickSortHelper(array, low, pivotIndex - 1);
        quickSortHelper(array, pivotIndex + 1, high);
    }
}
int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {
            i += 1;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void countingSort(std::vector<int>& array) {
    if(array.empty()) {
        return;
    }

    int max = *std::max_element(array.begin(), array.end());
    std::vector<int> countArr(max + 1, 0);

    for(int num : array) {
        countArr[num]++;
    }

    int index = 0;
    for(int i = 0; i < countArr.size(); i++) {
        while(countArr[i] > 0) {
            array[index++] = i;
            countArr[i]--;
        }
    }
}

void radixSort(std::vector<int>& array) {
    int max = *std::max_element(array.begin(), array.end());
    int exp = 1;
    
    while(max / exp > 0) {
        std::vector<std::vector<int>> radix_array = std::vector(10, std::vector<int>());

        for(int num : array) {
            int digit = (num / exp) % 10;
            radix_array[digit].push_back(num);
        }

        int idx = 0;
        for(std::vector<int>& bucket : radix_array) {
            for(int num : bucket) {
                array[idx] = num;
                idx += 1;
            }
        }
        
        exp *= 10;
    }
}

void heapSort(Heap<int>& heap) {
    heap.buildHeap();
    int length = heap.values.size();

    for(int i = length - 1; i > 0; --i) {
        std::swap(heap.values[0], heap.values[i]);
        heap.siftDown(0, i);
    }
}
#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include "data_structures/heap.hpp"

void bubbleSort(std::vector<int>& array);
void insertionSort(std::vector<int>& array);
void selectionSort(std::vector<int>& array);

void mergeSort(std::vector<int>& array);
void merge(std::vector<int>& array, std::vector<int>& left, std::vector<int>& right);

void quickSort(std::vector<int>& array);
void quickSortHelper(std::vector<int>& array, int low, int high);
int partition(std::vector<int>& array, int low, int high);

void countingSort(std::vector<int>& array);
void radixSort(std::vector<int>& array);

void heapSort(Heap<int>& heap);

#endif // SORTING_H
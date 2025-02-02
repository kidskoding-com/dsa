#include <gtest/gtest.h>
#include "algorithms/sorting.h"

TEST(SortingTest, BubbleSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    bubbleSort(arr);

    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, InsertionSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    insertionSort(arr);

    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, SelectionSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    selectionSort(arr);

    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, MergeSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    mergeSort(arr);

    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, QuickSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    quickSort(arr);

    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, CountingSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    countingSort(arr);
    
    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, RadixSortTest) {
    std::vector arr({5, 3, 8, 1, 2});
    radixSort(arr);
    
    std::vector sorted({1, 2, 3, 5, 8});
    
    EXPECT_EQ(arr, sorted);
}
TEST(SortingTest, MinHeapSortTest) {
    Heap<int> heap(false);
    heap.insert(5);
    heap.insert(10);
    heap.insert(15);
    heap.buildHeap();
    heapSort(heap);

    std::vector<int> sorted({15, 10, 5});

    EXPECT_EQ(heap.values, sorted);
}
TEST(SortingTest, MaxHeapSortTest) {
    Heap<int> heap(true);
    heap.insert(5);
    heap.insert(10);
    heap.insert(15);
    heap.buildHeap();
    heapSort(heap);

    std::vector<int> sorted({5, 10, 15});

    EXPECT_EQ(heap.values, sorted);
}
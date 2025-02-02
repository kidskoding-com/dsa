#include <gtest/gtest.h>
#include "data_structures/heap.h"
#include "algorithms/sorting.h"

TEST(HeapTest, InsertMaxHeap) {
    Heap<int> heap(true);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.buildHeap();
    
    ASSERT_EQ(heap.values[0], 20);
}

TEST(HeapTest, InsertMinHeap) {
    Heap<int> heap(false);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.buildHeap();
    
    ASSERT_EQ(heap.values[0], 5);
}
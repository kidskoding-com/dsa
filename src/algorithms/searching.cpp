#include "algorithms/searching.h"

int linearSearch(int array[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            return i;  
        }
    }
    return -1;
}

int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(target < array[mid]) {
            right = mid - 1;
        } else if(target > array[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

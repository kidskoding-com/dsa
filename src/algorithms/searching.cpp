#include "algorithms/searching.h"

int linearSearch(int array[], int target) {
    for(int i = 0; i < sizeof(array); i++) {
        if(array[i] == target) {
            return i;  
        }
    }
    return -1;
}

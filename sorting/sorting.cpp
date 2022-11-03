#include "sorting.h"
#include <iostream>

void print_array(int*, int);

// O(N*N)
void bubble_sort(int arr[], int length) {
    for(int i = 0; i < length - 1; ++i) {
        for(int j = i + 1; j < length; ++j) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Less steps than bubble sort, but still O(N*N)
void selection_sort(int arr[], int length) {
    for(int i = 0; i < length - 1; ++i) {
        int lowest_idx = i;
        for(int j = i + 1; j < length; ++j) {
            if(arr[j] < arr[i]) {
                lowest_idx = j;
            }
        }
        if(lowest_idx != i) {
            int temp = arr[i];
            arr[i] = arr[lowest_idx];
            arr[lowest_idx] = temp;
        }
    }
}

// O(N*N)
void insertion_sort(int arr[], int length) {
    for(int i = 1; i < length; ++i) {
        int current = arr[i];
        for(int j = i - 1; j > -1; --j) {
            if(arr[j] > current) {
                arr[j + 1] = arr[j];
                arr[j] = current;
            }
            else if(arr[j] < current) {
                break;
            }
        }
    }
} 

void print_array(int arr[], int length) {
    for(int i = 0; i < length; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

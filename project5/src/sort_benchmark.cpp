/**
 * @file sort_benchmark.cpp
 * @brief compare basic sorting algorithms
 */
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"

/**
 * Generate an array of random integers
 * @param n the size of the array
 * @param seed the seed for the random number generator
 * @return a pointer to a new array
 * @note the client is responsible for deleting the array with delete[]
 */
int* makeRandomArray(int n, int seed) {
    srand(seed);
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }
    return a;
}

void printArray(int* a, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::string sep = (i == size-1) ? " " : ", ";
        std::cout << a[i] << sep;
    }
    std::cout << "]" << std::endl;
}

int main() {
    // TODO use your personal seed
    const int seed = 431;

    // Example of running the sort algorithms with the random array.
    // TODO Remove or comment out this code before submission.

    //int n = 10;
    int* a;
	std::cout << "  Array Size   | 10  100  1000  10000 " << std::endl;
	std::cout << "===============|=============================================" << std::endl;
	// do for all 
    std::cout << "Bubble sort    | ";
    a = makeRandomArray(10, seed);
	std::cout << bubblesort(a, 10) << " ";
	delete[] a;
	a = makeRandomArray(100, seed);
	std::cout << bubblesort(a, 100) << " ";
	delete[] a;
	a = makeRandomArray(1000, seed);
	std::cout << bubblesort(a, 1000) << " ";
	delete[] a;
	a = makeRandomArray(10000, seed);
	std::cout << bubblesort(a, 10000) << std::endl;
	delete[] a;

    std::cout << "Selection sort | ";
    a = makeRandomArray(10, seed);
	std::cout << selectionsort(a, 10) << " ";
	delete[] a;
	a = makeRandomArray(100, seed);
	std::cout << selectionsort(a, 100) << " ";
	delete[] a;
	a = makeRandomArray(1000, seed);
	std::cout << selectionsort(a, 1000) << " ";
	delete[] a;
	a = makeRandomArray(10000, seed);
	std::cout << selectionsort(a, 10000) << std::endl;
	delete[] a;

    std::cout << "Insertion sort | ";
    a = makeRandomArray(10, seed);
	std::cout << insertionsort(a, 10) << " ";
	delete[] a;
	a = makeRandomArray(100, seed);
	std::cout << insertionsort(a, 100) << " ";
	delete[] a;
	a = makeRandomArray(1000, seed);
	std::cout << insertionsort(a, 1000) << " ";
	delete[] a;
	a = makeRandomArray(10000, seed);
	std::cout << insertionsort(a, 10000) << std::endl;
	delete[] a;

    std::cout << "Merge sort     | ";
    a = makeRandomArray(10, seed);
	std::cout << mergesort(a, 0, 10) << " ";
	delete[] a;
	a = makeRandomArray(100, seed);
	std::cout << mergesort(a, 0, 100) << " ";
	delete[] a;
	a = makeRandomArray(1000, seed);
	std::cout << mergesort(a, 0, 1000) << " ";
	delete[] a;
	a = makeRandomArray(10000, seed);
	std::cout << mergesort(a, 0, 10000) << std::endl;
	delete[] a;

    std::cout << "Quick sort     | ";
    a = makeRandomArray(10, seed);
	std::cout << quicksort(a, 0, 10) << " ";
	delete[] a;
	a = makeRandomArray(100, seed);
	std::cout << quicksort(a, 0, 100) << " ";
	delete[] a;
	a = makeRandomArray(1000, seed);
	std::cout << quicksort(a, 0, 1000) << " ";
	delete[] a;
	a = makeRandomArray(10000, seed);
	std::cout << quicksort(a, 0, 10000) << std::endl;
	delete[] a;

    return 0;
}

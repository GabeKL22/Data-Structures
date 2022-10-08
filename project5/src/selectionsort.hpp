/**
 * @file selectionsort.hpp
 */
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

int cnt = 0;
/**
 * Finds the largest item in an array.
 * @pre  The size of the array is >= 1.
 * @post  The arguments are unchanged.
 * @param theArray  The given array.
 * @param size  The number of elements in theArray.
 * @return  The index of the largest entry in the array.
 */
template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size);

/**
 * Sorts the items in an array into ascending order.
 * @pre  None.
 * @post  The array is sorted into ascending order; the size of the array
 *   is unchanged.
 * @param theArray  The array to sort.
 * @param n  The size of theArray.
 * @return the number of comparisons
 */
template<class ItemType>
int selectionsort(ItemType theArray[], int n) {
	cnt = 0;
    for (int last = n - 1; last >= 1; last--) {
        int largest = findIndexOfLargest(theArray, last+1);
        std::swap(theArray[largest], theArray[last]);
    }
    return cnt; // this return value is not correct.
}

template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size) {
    int indexSoFar = 0;
    for (int currentIndex = 1; currentIndex < size; currentIndex++) {
		cnt++;
        if (theArray[currentIndex] > theArray[indexSoFar]) {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}

#endif


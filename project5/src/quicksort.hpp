/**
 * @file quicksort.hpp
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

static const int MIN_SIZE  = 10; // Smallest size of an array that quicksort will sort
/**
 * Sorts the items in an array into ascending order.
 * @pre  None.
 * @post  theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @return the number of comparisons
 */
template<class ItemType>
void insertionSort(ItemType theArray[], int first, int last, int& cnt_21) {
    for (int unsorted = first + 1; unsorted <= last; unsorted++) {
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > first) && (cnt_21++, (theArray[loc - 1] > nextItem))) {
            theArray[loc] = theArray[loc - 1];
            loc--;
        }
        theArray[loc] = nextItem;
    }
}

/**
 * Arranges two specified array entries into sorted order by
 * exchanging them, if necessary.
 * @param theArray  The given array.
 * @param i  The index of the first entry to consider in theArray.
 * @param j  The index of the second entry to consider in theArray.
 * */
template<class ItemType>
void order(ItemType theArray[], int i, int j, int& cnt_2) {
	cnt_2++;
    if (theArray[i] > theArray[j]) {
        std::swap(theArray[i], theArray[j]);
    }
}

/** 
 * Arranges the first, middle, and last entry in an array in sorted order.
 * @pre  theArray[first..last] is an array; first <= last.
 * @post  theArray[first..last] is is arranged so that its
 * first, middle, and last entries are in sorted order.
 * @param theArray  The given array.
 * @param first  The first entry to consider in theArray.
 * @param last  The last entry to consider in theArray.
 * @return  The index of the middle entry.
 */
template<class ItemType>
int sortFirstMiddleLast(ItemType theArray[], int first, int last, int& cnt_21) {
    int mid = first + (last - first) / 2;
    order(theArray, first, mid, cnt_21); // Make theArray[first] <= theArray[mid]
    order(theArray, mid, last, cnt_21);  // Make theArray[mid] <= theArray[last]
    order(theArray, first, mid, cnt_21); // Make theArray[first] <= theArray[mid]

    return mid;
}

/**
 * Partitions the entries in an array about a pivot entry for quicksort.
 * @pre  theArray[first..last] is an array; first <= last.
 * @post  theArray[first..last] is partitioned such that:
 * S1 = theArray[first..pivotIndex-1] <= pivot * theArray[pivotIndex] == pivot
 * S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first entry to consider in theArray.
 * @param last  The last entry to consider in theArray.
 * @return  The index of the pivot.
 */
template<class ItemType>
int partition(ItemType theArray[], int first, int last, int& cnt_21) {
    // Choose pivot using median-of-three selection
    int pivotIndex = sortFirstMiddleLast(theArray, first, last, cnt_21);

    // Reposition pivot so it is last in the array
    std::swap(theArray[pivotIndex], theArray[last - 1]);
    pivotIndex = last - 1;
    ItemType pivot = theArray[pivotIndex];

    // Determine the regions S1 and S2
    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;

    bool done = false;
    while (!done) {
        // Locate first entry on left that is >= pivot
        while ((cnt_21++, theArray[indexFromLeft]) < pivot) {
            indexFromLeft = indexFromLeft + 1;
        }

        // Locate first entry on right that is <= pivot
        while ((cnt_21++, theArray[indexFromRight]) > pivot) {
            indexFromRight = indexFromRight - 1;
        }
		
        if (indexFromLeft < indexFromRight) {
            std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
            indexFromLeft = indexFromLeft + 1;
            indexFromRight = indexFromRight - 1;
        }
        else {
            done = true;
        }
    }

    // Place pivot in proper position between S1 and S2, and mark its new location
    std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
    pivotIndex = indexFromLeft;

    return pivotIndex;
}

/**
 * Sorts an array into ascending order. Uses the quick sort with
 * median-of-three pivot selection for arrays of at least MIN_SIZE
 * entries, and uses the insertion sort for other arrays.
 * @pre  theArray[first..last] is an array.
 * @post  theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @return the number of comparisons
 */
template<class ItemType>
int quicksort(ItemType theArray[], int first, int last) {
    int result = 0;
    if (last - first + 1 < MIN_SIZE) {
        insertionSort(theArray, first, last, result);
    }
    else {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last, result);

        // Sort subarrays S1 and S2
        result += quicksort(theArray, first, pivotIndex - 1);
        result += quicksort(theArray, pivotIndex + 1, last);
    }
    return result; // this return value is not correct
}

#endif

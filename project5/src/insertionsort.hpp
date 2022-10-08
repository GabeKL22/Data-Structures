/**
 * @file insertionsort.hpp
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

/**
 * Sorts the items in an array into ascending order.
 * @pre  None.
 * @post  theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray.
 * @return The number of comparison operations.
 */
template<class ItemType>
int insertionsort(ItemType theArray[], int n) {
	int cnt = 0;
    for (int unsorted = 1; unsorted < n; unsorted++) {
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (cnt++, (theArray[loc - 1] > nextItem))) {
            theArray[loc] = theArray[loc - 1];
            loc--;
        }
        theArray[loc] = nextItem;
    }
    return cnt; // this return value is not correct
}

#endif

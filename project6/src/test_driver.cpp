// CSC 237, Spring 2021, Assignment 6

#include <iostream>
#include "CompleteBinaryTree.h"

using namespace std;

int main() {
    CompleteBinaryTree<int> cbt;
	vector<int> traversal;

    /* do the following
       1. display the height
       2. add 17 numbers (from 0 to 16) to the tree
       3. display the height again
       4. remove the number 0
       5. display the pre-order, in-order, post-order traveral of the tree 

     sample output:
     -bash-4.1$ make test
     ./build/test_driver
     Height: 0
     Height: 5
     capacity: 24
     16, 1, 3, 7, 15, 8, 4, 9, 10, 2, 5, 11, 12, 6, 13, 14,
     15, 7, 3, 8, 1, 9, 4, 10, 16, 11, 5, 12, 2, 13, 6, 14,
     15, 7, 8, 3, 9, 10, 4, 1, 11, 12, 5, 13, 14, 6, 2, 16,

     */ 
	
	cout << "Height: " << cbt.getHeight() << endl;
	for (int i = 0; i < 17; i++) {
		cbt.add(i);
	}
	cout << "Height: " << cbt.getHeight() << endl;
	cbt.remove(0);
	cout << "Capacity: " << cbt.getCapacity() << endl;
	traversal = cbt.preorderTraverse();
	cout << "Pre-order: ";
	for (int i: traversal) {
		cout << i << ", ";
	}
	cout << endl;
	traversal = cbt.inorderTraverse();
	cout << "In-order: ";
	for (int i: traversal) {
		cout << i << ", ";
	}
	cout << endl;
	traversal = cbt.postorderTraverse();
	cout << "Post-order: ";
	for (int i: traversal) {
		cout << i << ", ";
	}
	cout << endl; 
	
	
	


    return 0;
}

/**
 * @file Node.hpp
 * CSC 237, Spring 2021, Assignment 1
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>

/**
 * @class Node
 * @brief A node in a linked list
 */
template <class T>
struct Node {
    /** The data element **/
    T data;
    /** A pointer to the next Node **/
    Node<T>* next;
};


/**
 * Insert an element into a linked list at a given position
 * @pre The position is within the bound of the list, that is,
 *      1 <= position <= length(head)+1
 * @param head the head of the linked list.
 * @param position the list position at which to insert element.
 * @param element the element to insert into the list.
 * @return the head of the modified list
 */
template <class T>
Node<T>* insert(Node<T>* head, int position, T element) {
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node<T>* previousNode = head;
        for (int p = 1; p < position-1; p++) {
            previousNode = previousNode->next;
        }
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    return head;
}

/**
 * Display a string representation of the list to standard out.
 * @param head the head of the linked list.
 */
template <class T>
void show(Node<T>* head) {
    Node<T>* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << currentNode->data;
        std::cout << " -> ";
        currentNode = currentNode->next;
    }
    std::cout << "NULL" << std::endl;
}

/**
 * Checks whether the list is empty.
 * @param head the head of the linked list.
 * @return True if the list is empty, otherwise false.
 */
template <class T>
bool isEmpty(Node<T>* head) {
    return head == nullptr;
}

/**
 * Checks the length of the list.
 * @param head the head of the linked list.
 * @return the length of the list
 */
template <class T>
int length(Node<T>* head) {
	if (!isEmpty(head)) {
		return length(head->next)+ 1;
	}	
    return 0;
}

/**
 * Checks to see if the element is contained within the list.
 * @param head the head of the linked list.
 * @param element the element we are looking for.
 * @return true or false.
 */
template <class T>
bool contains(Node<T>* head, T element) {
	if (!isEmpty(head)) {
		if (head->data == element) {
			return true;
		}
		else {
			return contains(head->next, element);		
		}
	}
    return false;
}

/**
 * Gets the element in the postion we give it.
 * @param head the head of the linked list.
 * @param position the postion of the element in the linked list.
 * @return head->data the head of the linked list.
 */
template <class T>
T getElement(Node<T>* head, int position) {
	if (position != 1) {
		position -= 1;
		return getElement(head->next, position);
	}
    return head->data;
}

/** 
 * Returns the postions of the first instance of the element passed in.
 * @param head the head of the linked list.
 * @param element the element that we are passing in. 
 * @return -1 if not found, postion if element is found. 
 */
template <class T>
int getPosition(Node<T>* head, T element) {
	Node<T>* current = head; 
	int position = 1;
	while (!isEmpty(current)) {
		if (current->data == element) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1;
}

/**
 * Replaces an element in a certain potions with a new element.
 * @param head the head of the linked list. 
 * @param position the position of the element in the linked list that is being replaced.
 * @param element the new element being put into a certain position.
 * @return the head of the linked list. 
 */
template <class T>
Node<T>* replace(Node<T>* head, int position, T element) {
	if (position != 1) {
		position -= 1;
		replace(head->next, position, element);
	}
	else {
		head->data = element;
	}
    return head;
}

/** 
 * Remove an element at a certain position within the linked list.
 * @param head the head of the linked list. 
 * @param position the position of the element being removed/
 * @return head of the new linked list
 */ 
template <class T>
Node<T>* remove(Node<T>* head, int position) {
	Node<T>* current = head;
	Node<T>* pre = head;
	int curPOS = 1;
	while(!isEmpty(current)) {
		if (position == 1) {
			head = head->next;
			break;
		}
		else {
			if(curPOS == position) {
				pre->next = current->next;
				break;
			}
		}
		pre = current;
		current = current->next;
		curPOS++;
		
	}
    return head;
} 

#endif

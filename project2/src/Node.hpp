/**
 * @file Node.hpp
 * CSC 237, Fall 2021, Assignment 2
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

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
Node<T>* insert(Node<T>* head, int position, T element) throw(std::logic_error){
    // Error check
    if (head == nullptr && position > 1) {
        throw (std::logic_error("Invalid insert position"));
    }

    // Base case
    if (position == 1) {
        Node<T>* newNode = new Node<T>();
        newNode->data = element;
        newNode->next = head;
        return newNode;
    }
    // Recursive case
    else {
        head->next = insert(head->next, position-1, element);
        return head;
    }
}

/**
 * Display a string representation of the list to standard out.
 * @param head the head of the linked list.
 */
template <class T>
void show(Node<T>* head) {
    // Base case
    if (head == nullptr) {
        std::cout << "NULL" << std::endl;
    }
    // Recursive case
    else {
        std::cout << head->data << " -> ";
        show(head->next);
    }
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
 * Gets the number of elements in the list.
 * @param head the head of the linked list.
 * @return The length of the entries currently in the list.
 */
template <class T>
int length(Node<T>* head) {
    // TODO implement this function using recursion.
	if (!isEmpty(head)) {
		return length(head->next) + 1;
	}
    return 0;
}

/**
 * Checks whether a element is contained in the list.
 * @param head the head of the linked list.
 * @param element the element to test.
 * @return True if the element is in the list, otherwise false.
 */
template <class T>
bool contains(Node<T>* head, T element) {
    // TODO implement this function using recursion.
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
 * Gets the element at the given position in the list
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list
 * @param position the list position of the desired element.
 * @return the element at the desired list position.
 */
template <class T>
T getElement(Node<T>* head, int position) {
    // TODO implement this function using recursion.
	if (position > length(head)) {
		throw std::logic_error("Position is greater than the length of the list.");
	}
	else if (position != 1) {
		position -= 1;
		return getElement(head->next, position);
	}
    return head->data;
}

/**
 * Gets the position of the first occurrence of the desired element.
 * @param head the head of the linked list
 * @param element the desired element.
 * @return The integer position of the desired element if it occurs in the list,
 *         otherwise -1.
 */
template <class T>
int getPosition(Node<T>* head, T element) {
    // TODO implement this function using recursion.
	if (head == NULL) {
		return -1;
	}
	if (element == head->data) {
		return 1;
	}
	else {
		int var = getPosition(head->next, element);
		if (var == -1) {
			return -1;
		}
		else {
			return var + 1;
		}
	}
    return -1;
}

/**
 * Replaces the element at the given position in the list.
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list.
 * @param position the list position of the element to replace.
 * @param element the replacement element
 * @return the head of the modified list.
 */
template <class T>
Node<T>* replace(Node<T>* head, int position, T element) {
    // TODO implement this function using recursion.
	if (position > length(head)) {
		throw std::logic_error("Position is greater than the length of the list.");
	}
	else if (position != 1) {
		position -= 1;
		replace(head->next, position, element);
	}
	else {
		head->data = element;
	}
    return head;
}

/**
 * Removes the element at a given position from the list.
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list.
 * @param position the list position of the entry to remove.
 * @return the head of the modified list.
 */
template <class T>
Node<T>* remove(Node<T>* head, int position) {
    // TODO implement this function using recursion.
	if (position > length(head)) {
		throw std::logic_error("Position is greater than the length of the list.");
	}
	if (position == 1) {
		head = head->next;
		return head;
	}
	else {
		Node<T>* var = head->next;
		Node<T>* var1 = remove(var, (position - 1));	
		head->next = var1;
	}
    return head;
}

#endif

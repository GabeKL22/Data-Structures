/**
 * @file string_test_driver.cpp
 * CSC 237, Spring 2021, Assignment 1
 */
 
/************************************************************************************************************/
/*             Author:     Gabriel Leffew                            
/*      Creation Date:     February, 2nd 2021                       
/*           Due Date:     February, 8th 2021                      
/*             Course:     CSC 237                               
/*     Professor Name:     Dr. Yong Zhang                             
/*         Assignment:     #1                                        
/*          File Name:     string_test_driver.cpp                          
/*            Purpose:     Tests the Node functions using std::string as the actual template parameter                 
/************************************************************************************************************/

#include <string>
#include "Node.hpp"

/**
 * Tests the Node functions using string as the actual template parameter
 * @return the exit code
 */
int main() {
    // TODO write tests for the Node functions using std::string as the actual
    // parameter type.
	//print boolean strings instead of ints
	std::cout << std::boolalpha;
	
	std::cout << "Creating an empty list containing type string" << std::endl;
	Node<std::string>* head = nullptr;
	std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
	std::cout << "show(head) " << std::endl;
	show(head);
	std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
	//add words to list
	std::cout << "Add the strings to the list. " << std::endl;
	head = insert(head, 1, std::string("one"));
	head = insert(head, 2, std::string("two"));
	head = insert(head, 3, std::string("three"));
	head = insert(head, 4, std::string("four"));
	head = insert(head, 5, std::string("five"));

	// re - check the list
	std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
	std::cout << "show(head) " << std::endl;
	show(head);
	std::cout << std::endl;
	
	std::cout << "head = insert(head, 3, std::string(\"Bob\")" << std::endl;
	head = insert(head, 3, std::string("Bob"));
	std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): ";
    std::cout << length(head) << std::endl;
    std::cout << std::endl;
	
	//test the contains function
	std::cout << "contains(head, std::string(\"one\")): " << contains(head, std::string("one")) << std::endl;
    std::cout << "contains(head, std::string(\"Alice\")): " << contains(head, std::string("Alice")) << std::endl;
    std::cout << std::endl;
	
	//test the getElement function
	std::cout << "getElement(head, 3): ";
    std::cout << getElement(head, 3) << std::endl;
    std::cout << std::endl;
	
	// Test the getPosition function
    std::cout << "getPosition(head, std::string(\"five\")): ";
    std::cout << getPosition(head, std::string("five")) << std::endl;
    std::cout << "getPosition(head, std::string(\"Alice\")): ";
    std::cout << getPosition(head, std::string("Alice")) << std::endl;
    std::cout << std::endl;
	
	// Test the replace function
    std::cout << "replace(head, 3, std::string(\"Eve\"))" << std::endl;
    head = replace(head, 3, std::string("Eve"));
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << std::endl;
	
	// Test the remove function
    std::cout << "head = remove(head, 3)" << std::endl;
    head = remove(head, 3);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
	
	std::cout << "head = remove(head, 1)" << std::endl;
    head = remove(head, 1);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
	
    return 0;
}

/**
 * @file exception_test_driver.cpp
 * CSC 237, Fall 2021, Assignment 2
 */

/************************************************************************************************************/
/*             Author:     Gabriel Leffew                            
/*      Creation Date:     February, 17th 2021                       
/*           Due Date:     February, 24th 2021                      
/*             Course:     CSC 237                               
/*     Professor Name:     Dr. Yong Zhang                             
/*         Assignment:     #2                                        
/*          File Name:     exception_test_driver.cpp                          
/*            Purpose:     tests the node functions with paramters outside of the length.                 
/************************************************************************************************************/
#include "Node.hpp"

/**
 * Tests the error cases of the Node functions that rely on position.
 * @return the exit code
 */
int main() {

	// this sets cout to print booleans as strings
	std::cout << std::boolalpha;

	// TODO write tests that use invalid positions for the Node functions that
	// rely on position.
	
    // create a list of the integers 1 to 10
    std::cout << "Create an empty list containing type int" << std::endl;
    Node<int>* head = nullptr;
    std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
	
	// Test the push function
    std::cout << "Add the integers from 1 to 10 to the list" << std::endl;
    try{for (int i = 10; i > 0; i--) {
        head = insert(head, 25, i);
    }
	}
	catch(std::logic_error) {std::cout << "ERROR: invalid insert position" << std::endl;}
    std::cout << std::endl;
	
	// Test the getElement function
    std::cout << "getElement(head, 25): ";
    try {std::cout << getElement(head, 25) << std::endl;
		std::cout << "show(head)" << std::endl;
		show(head);
	}
	catch(std::logic_error) {std::cout << "ERROR: invalid getElement position" << std::endl;}
    std::cout << std::endl;
  
    // Test the replace function
    std::cout << "replace(head, 25, 9000)" << std::endl;
    try{head = replace(head, 25, 9000);
		std::cout << "show(head)" << std::endl;
		show(head);
	}
    catch(std::logic_error) {std::cout << "ERROR: invalid replace position" << std::endl;}
    std::cout << std::endl;

    // Test the remove function
    std::cout << "head = remove(head, 25)" << std::endl;
    try{head = remove(head, 25);
		std::cout << "show(head)" << std::endl;
		show(head);
	}
	catch(std::logic_error) {std::cout << "ERROR: invalid remove position" << std::endl;}
    std::cout << std::endl;

    std::cout << "head = remove(head, 25)" << std::endl;
    try{head = remove(head, 25);
		std::cout << "show(head)" << std::endl;
		show(head);
	}
	catch(std::logic_error) {std::cout << "ERROR: invalid remove position" << std::endl;}
    std::cout << std::endl;
	return 0;
}

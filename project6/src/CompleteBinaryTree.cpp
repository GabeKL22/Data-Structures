// CSC 237, Spring 2021, Assignment 6

/************************************************************************************************************/
/*             Author:     Gabriel Leffew                            
/*      Creation Date:     April 27th, 2021                       
/*           Due Date:     May 5th, 2021                      
/*             Course:     CSC 237                               
/*     Professor Name:     Dr. Yong Zhang                             
/*         Assignment:     #6                                        
/*          File Name:     CompleteBinaryTree.cpp                          
/*            Purpose:     to construct and manipulate a complete binary tree.                 
/************************************************************************************************************/
/************************************************************************************************************************/
/*  Function Name:   CompleteBinaryTree                                    
/*  Description:     constructor for the complete binary tree
/*  Parameters:      none                      
/*  Return Value:    none constuctor
/************************************************************************************************************************/
template<class ItemType>
CompleteBinaryTree<ItemType>::CompleteBinaryTree() {
	items = new ItemType[DEFAULT_CAPACITY];
	capacity = DEFAULT_CAPACITY;
	itemCount = 0;
}

/************************************************************************************************************************/
/*  Function Name:   ~CompleteBinaryTree                                    
/*  Description:     deconstructor for the complete binary tree
/*  Parameters:      none                      
/*  Return Value:    none constuctor
/************************************************************************************************************************/
template<class ItemType>
CompleteBinaryTree<ItemType>::~CompleteBinaryTree() {
	delete[] items;
}

/************************************************************************************************************************/
/*  Function Name:   CompleteBinaryTree(const CompleteBinaryTree & other)                                   
/*  Description:     constructor for the complete binary tree
/*  Parameters:      const CompleteBinaryTree & other           
/*  Return Value:    none constuctor
/************************************************************************************************************************/
template<class ItemType>
CompleteBinaryTree<ItemType>::CompleteBinaryTree(const CompleteBinaryTree & other) {
	capacity = other.capacity;
	itemCount = other.itemCount;
	items = new ItemType[capacity];
	for (int i = 0; i < itemCount; i++) {
		items[i] = other.items[i];
	}
}
/************************************************************************************************************************/
/*  Function Name:   CompleteBinaryTree<ItemType>::operator=(const CompleteBinaryTree & other)                                   
/*  Description:     assignment operator constuct
/*  Parameters:      const CompleteBinaryTree & other           
/*  Return Value:    this* 
/************************************************************************************************************************/

template<class ItemType>
CompleteBinaryTree<ItemType>& CompleteBinaryTree<ItemType>::operator=(const CompleteBinaryTree & other) {
	capacity = other.capacity;
	itemCount = other.itemCount;
	items = new ItemType[capacity];
	for (int i = 0; i < itemCount; i++) {
		items[i] = other.items[i];
	}
    return *this; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   isEmpty                           
/*  Description:     boolean to determine if empty.
/*  Parameters:      none        
/*  Return Value:    itemCount == 0;
/************************************************************************************************************************/
template<class ItemType>
bool CompleteBinaryTree<ItemType>::isEmpty() {
    return itemCount == 0; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   getHeight                             
/*  Description:     gets the height of the CompleteBinaryTree
/*  Parameters:      none           
/*  Return Value:    std::ceil(std::log2(this->getNumberOfNodes() + 1)) - 1 (rows of tree)
/************************************************************************************************************************/
template<class ItemType>
int CompleteBinaryTree<ItemType>::getHeight() {
    return std::ceil(std::log2(this->getNumberOfNodes() + 1)) - 1; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   getNumberOfNodes                           
/*  Description:     gets the number of nodes in the CompleteBinaryTree
/*  Parameters:      none           
/*  Return Value:    itemCount
/************************************************************************************************************************/
template<class ItemType>
int CompleteBinaryTree<ItemType>::getNumberOfNodes() {
    return itemCount; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   getCapacity                          
/*  Description:     gets the capacity of the CompleteBinaryTree
/*  Parameters:      none           
/*  Return Value:    capacity 
/************************************************************************************************************************/
template<class ItemType>
int CompleteBinaryTree<ItemType>::getCapacity() {
    return capacity; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   add                          
/*  Description:     adds (newData) to the CompleteBinaryTree
/*  Parameters:      const ItemType& newData           
/*  Return Value:    true, until NULL 
/************************************************************************************************************************/
template<class ItemType>
bool CompleteBinaryTree<ItemType>::add(const ItemType& newData) {
	if (items == NULL) {
		return false;
	}
	if (itemCount < capacity) {
		items[itemCount] = newData;
		//std::cout << items[itemCount + 1];
		itemCount++;
	}
	else {
		int newCapacity = capacity + 1;
		ItemType *newItems = new ItemType[newCapacity];
		std::copy(items, items + std::min(capacity, newCapacity), newItems);
		delete [] items;
		items = newItems;
		items[itemCount] = newData;
		capacity = capacity + 1;
		//std::cout << items[itemCount + 1];
		itemCount++;
	}
	return true; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   remove                          
/*  Description:     removes data from the CompleteBinaryTree
/*  Parameters:      const ItemType& data           
/*  Return Value:    new CompleteBinaryTree
/************************************************************************************************************************/
template<class ItemType>
bool CompleteBinaryTree<ItemType>::remove(const ItemType& data) {
    return false; // this is not a correct return value
}
/************************************************************************************************************************/
/*  Function Name:   clear                          
/*  Description:     clears the CompleteBinaryTree
/*  Parameters:      none          
/*  Return Value:    none (VOID function) 
/************************************************************************************************************************/
template<class ItemType>
void CompleteBinaryTree<ItemType>::clear() {
	delete [] items;
}
/************************************************************************************************************************/
/*  Function Name:   contains                          
/*  Description:     searches for an instance of "anEntry" in the CompleteBinaryTree
/*  Parameters:      const ItemType& anEntry           
/*  Return Value:    true if found, false if not.
/************************************************************************************************************************/
template<class ItemType>
bool CompleteBinaryTree<ItemType>::contains(const ItemType& anEntry) {
	if (items == NULL ){
		return false;
	}
	while (items != NULL){
		for (int i = 1; i < 0; i++) {
			if (items[i] == anEntry) {
				return true;
			}
		}
	}
    return false; // this is not a correct return value
}
    /************************************************************************************************************************/
/*  Function Name:   preorderTraverse                          
/*  Description:     prints the leaves on the tree in Pre-Order.
/*  Parameters:      none          
/*  Return Value:    result 
/************************************************************************************************************************/
template<class ItemType>
std::vector<ItemType> CompleteBinaryTree<ItemType>::preorderTraverse() {
    std::vector<ItemType> result;
    return result; // this is not a correct return value
}
 /************************************************************************************************************************/
/*  Function Name:   inorderTraverse                          
/*  Description:     prints the leaves on the tree In-Order.
/*  Parameters:      none          
/*  Return Value:    result 
/************************************************************************************************************************/
template<class ItemType>
std::vector<ItemType> CompleteBinaryTree<ItemType>::inorderTraverse() {
    std::vector<ItemType> result;
    return result; // this is not a correct return value
}
 /************************************************************************************************************************/
/*  Function Name:   postorderTraverse                          
/*  Description:     prints the leaves on the tree in Post-Order.
/*  Parameters:      none          
/*  Return Value:    result 
/************************************************************************************************************************/
template<class ItemType>
std::vector<ItemType> CompleteBinaryTree<ItemType>::postorderTraverse() {
    std::vector<ItemType> result;
    return result; // this is not a correct return value
}


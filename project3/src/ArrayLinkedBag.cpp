/** Implementation file for the class ArrayLinkedBag.
  @file ArrayLinkedBag.cpp */

#include "ArrayLinkedBag.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
ArrayLinkedBag<ItemType>::ArrayLinkedBag(): head(0), free(0), cnt(0)
{
	for (int i = 0; i < DEFAULT_CAPACITY; i++) {
		cells[i].next = -2;
	}
	
}

template<class ItemType>
int ArrayLinkedBag<ItemType>::getCurrentSize() const
{
	return cnt;
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::isEmpty() const
{
	if(cnt == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::add(const ItemType& newEntry)
{
	
	bool hasRoomToAdd = (cnt < DEFAULT_CAPACITY);
	if(hasRoomToAdd)
	{
		cells[free].item = newEntry;
		cells[free].next = -1;
		int h = head;
		while(cells[h].next != -1 && cells[h].next != -2) {	
			h = cells[h].next;
		}
		if(h != free) {
			cells[h].next = free;
		}
		for (int i = 0; i < DEFAULT_CAPACITY; i++) 
		{
			if(cells[i].next == -2) {
				free = i;
				break;
			}
		} 
		cnt++;
		return true;
	}
	else {
		return false;
	}
	
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	
}

template<class ItemType>
void ArrayLinkedBag<ItemType>::clear()
{
	
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	
}

template<class ItemType>
int ArrayLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	
}

template<class ItemType>
std::vector<ItemType> ArrayLinkedBag<ItemType>::toVector() const
{
	int h = head;
	std::vector<ItemType> bagContents;
	std::cout << cells[h].next << std::endl;
	while(cells[h].next != -1 && cells[h].next != -2) {
		bagContents.push_back(cells[h].item);
		h = cells[h].next;
	}
	if (cells[h].next != -2) {
		bagContents.push_back(cells[h].item);
	}		
	return bagContents;
}

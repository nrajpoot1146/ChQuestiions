#include<iostream>
#include<cstdlib>
#include "LinkedListSingle.h"
using namespace std;

LinkedListSingle::LinkedListSingle()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void LinkedListSingle::buildListForward(int addData)
{
    nodePtr n = new node;
    n->data = rand() % 100 + 1;

    if (addData < 0)
    {
        cout << "The list must be a positive set of integers" << endl;
        return;
    }
    else
    {

        n->next = NULL;
    }

    if (head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

void LinkedListSingle::PrintListForward()
{
    curr = head;
    while (curr != NULL)

    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << "NULL" << endl;
    }
}

void LinkedListSingle::SortLinkedList()
{
    int tempvar;
    curr = NULL;
    while (head != curr)
    {
        temp = head;
        while (temp->next != curr)
        {
            if (temp->data > temp->next->data)
            {
                tempvar = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempvar;
            }
            temp = temp->next;
        }
        curr = temp;
    }
}

int LinkedListSingle::middle(nodePtr start , nodePtr end)
{	
	if(start == NULL){
		start = head; // start == NULL set the start pointer to its head position
    	end = NULL;
    }
    nodePtr temp = start;
    int elementCount = 0;
    
    // find the number of elements between start and end node;
    while(temp != end){
    	elementCount++;
    	temp = temp->next;
	}
	
	int mid = elementCount/2; // mid element index;
	return mid;
}

int LinkedListSingle::binarySearch(int key)
{
    nodePtr start = head;
    nodePtr end = NULL;
    
    do
    {
    	int m = this->middle(start, end);
        nodePtr mid = start;
        
        for (int i=0; i<m; i++){
        	mid = mid->next; // get the mid node of linked list
		}
        
        if (mid == NULL)
        {
            return NULL; // return null if mid node does not exist
        }
        if (mid->data == key)
        {
            return mid->data; // return data of mid note if key == data of mid node
        }
        else if (mid->data < key)
        {
            start = mid->next;
        }
        else
        {
            end = mid;
        }
    } while (end == NULL || end != start);

    return NULL;
}

int LinkedListSingle::location(int key)
{
    int count = 1;
    nodePtr temp = head;
    while (temp->data != key)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

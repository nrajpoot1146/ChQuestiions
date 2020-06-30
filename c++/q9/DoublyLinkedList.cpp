//DoubleLinkedList.ccp

#include <bits/stdc++.h>

#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::~DoublyLinkedList() {
  //Deallocate
  Node * p;
  while (!IsEmpty()) {
    p = head -> next;
    delete head;
    head = p;
  }
}

/* Insert new node at beginning of list:
First, a new node is initialized:
The info member of the node is set
The next member is initialized to point to the current head
Head is then updated to point to the new node
If tail is null (list is empty) set point to the head
Time complexity of AddToHead() is O(1) as it does constant amount of work.
*/
void DoublyLinkedList::AddToHead(int data) {
  // O(1)
  Node * newNode = new Node(data, head, NULL);
  if (head != NULL) {
    head -> prev = newNode;
  }
  head = newNode;

  // If tail is null (list is empty) set point to the head
  if (tail == NULL) {
    tail = head;
  }
}

/* Add tail to list. Cases to consider:
 * When List is empty
 */
void DoublyLinkedList::AddToTail(int data) {
  // TODO: Implement AddToTail
  // O(1)
  Node* newNode = new Node(data,NULL,tail);
  if(tail != NULL){
  	tail->next = newNode;
  }
  tail = newNode;
  if(head == NULL){
  	head = tail;
  }
}

/* Insert after nth node in list. Cases to consider:
 * When List is empty or there is no nth element (outprint a message if these states occur)
 * Can you call InsertAfterNode once you identify the node to insert after?
 */
void DoublyLinkedList::InsertAfterNthNode(int n, int data) {
  // TODO: Implement InsertAfterNthNode
  // O(n)
  if(IsEmpty()){
  	return;
  }
  Node *temp = head;
  int i = 1;
  while(i < n){
  	if(temp == NULL){
  		return;
	}
	
	temp = temp->next;
  	i++;
  }
  InsertAfterNode(temp,data);
}

/* Insert after node in list. Cases to consider:
 * When provided prevNode is null (outprint a message if this state occurs)
 */
void DoublyLinkedList::InsertAfterNode(Node * prevNode, int data) {
  // TODO: Implement InsertAfterNode
  //O(1)
  if(IsEmpty()){
  	return;
  }  
  Node *newNode = new Node(data,prevNode->next,prevNode);
  prevNode->next = newNode;
}

/* Delete tail for list. Cases to consider:
 * Only one item in list
 * When List is empty
 * Remember to deallocate memory of the deleted node
 */
void DoublyLinkedList::DeleteHead() {
  // TODO: Implement DeleteHead
  //O(1)
  if(IsEmpty()){
  	return;
  }
  head = head->next;
  head->prev = NULL;
}

/* Delete tail for list. Cases to consider:
 * Only one item in list
 * When List is empty (outprint a message for this state)
 * Remember to deallocate memory of the deleted node
 */
void DoublyLinkedList::DeleteTail() {
  // TODO: Implement DeleteTail
  //O(1)
  if(IsEmpty()){
  	return;
  }
  
  if(head == tail){
  	head = NULL;
  	tail = NULL;
  }
  
  tail = tail->prev;
  tail->next = NULL;
}

/* Delete node in list. Cases to consider:
 * Only one item in list
 * If more than one node in the list, and node to delete is head
 * When List is empty or there is no nth element (outprint a message if these states occur)
 * Remember to deallocate memory of the deleted node
 */
void DoublyLinkedList::DeleteNthNode(int n) {
  // TODO: Implement DeleteNode
  //O(n)
  if(IsEmpty()){
  	return;
  }
  
  if(head == tail && n == 1){
  	head = NULL;
  	tail = NULL;
  }
  
  int i = 2;
  Node *temp = head->next;
  while(i<n){
  	if(temp == NULL){
  		return;
	}
  	temp = temp->next;
  	i++;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
}

/* Delete node in list. Cases to consider:
 * Only one item in list
 * If more than one node in the list, and node to delete is head
 * When List is empty
 * Remember to deallocate memory of the deleted node
 */
void DoublyLinkedList::DeleteNode(Node * nodeToDelete) {
  // TODO: Implement DeleteNode
  //O(1)
  if(IsEmpty()){
  	return;
  }
  if(head == tail){
  	head = NULL;
  	tail = NULL;
  }
  nodeToDelete->prev->next = nodeToDelete->next;
  nodeToDelete->next->prev = nodeToDelete->prev;
}

// Returns Head of list
Node * DoublyLinkedList::GetHead() {
  return head;
}

// Returns Tail of list
Node * DoublyLinkedList::GetTail() {
  return tail;
}

// Returns Nth Node of list
Node * DoublyLinkedList::GetNthNode(int n) {
  Node * node = head;
  for (int i = 1; i < n; i++) {
    if (node -> next != NULL) {
      node = node -> next;
    } else {
      return NULL;
    }
  }
  return node;
}

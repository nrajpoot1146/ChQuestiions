/*
 * LinkedList.cpp
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#include "LinkedList.h"

LinkedList::LinkedList() {
	this->head = NULL;
	this->tail = NULL;
}

void LinkedList::add(int data){
	// if list is empty create new node and initialize head and tail to newNode
	if(isEmpty()){
		Node *newNode = new Node(data);
		this->head = newNode;
		this->tail = newNode;
		return;
	}

	// if data is equal to head data return do nothing
	if(this->head->data == data){
		return;
	}

	Node *curr = this->head->next;
	Node *pre = curr;
	while(curr != NULL){
		if(curr->data == data){
			// swap current node data to previous node data
			curr->data = pre->data;
			pre->data = data;
			return;
		}
		pre = curr;
		curr = curr->next;
	}

	// if node is not exist then add newNode as last node of current linked list
	Node *newNode = new Node(data);
	this->tail->next = newNode;
	this->tail = newNode;
}

void LinkedList::add(Node *newNode){
	this->add(newNode->data);
}


void LinkedList::print(){
	if(this->isEmpty()){
		cout<<"Linked list is empty: "<<endl; // show message if list is empty
		return;
	}

	Node *curr = this->head;
	while(curr != NULL){
		cout<<curr->data<<"->"; // print data of node
		curr = curr->next;
	}

	cout<<"NULL"<<endl;
}

bool LinkedList::isEmpty(){
	if(this->head == NULL){
		return true; // return true if list is empty
	}
	return false; // return false if list is not empty
}

LinkedList::~LinkedList() {
	// free all occupy memory
	delete this->head;
	delete this->tail;
}


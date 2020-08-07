/*
 * p025.cpp
 *
 *  Created on: 17-Jul-2020
 *      Author:
 */

#include "p025.h"

MyList::MyList(){
	this->next = NULL;
	this->last = NULL;
	this->length = 0;
	this->value = -1;
}

void MyList::prepend(int val){
	MyList *newNode = new MyList();
	this->length++;
	newNode->length = this->length;
	newNode->value = val;
	if (this->next == NULL){
		this->next = newNode;
		this->last = newNode;
		newNode->last = this->last;
		return;
	}
	newNode->next = this->next;
	this->next = newNode;
	newNode->last = this->last;
}

void MyList::append(int val){
	MyList *newNode = new MyList();
	this->length++;
	newNode->length = this->length;
	newNode->value = val;
	if (this->next == NULL){
		this->next = newNode;
		this->last = newNode;
		newNode->last = this->last;
		return;
	}
	this->last->next = newNode;
	this->last = newNode;
	newNode->last = this->last;
}

int MyList::get(int ind){
	if (ind >= this->length || ind < 0){
		return -1;
	}

	MyList *curr = this->next;
	for (int i=0; i<this->length; i++){
		if (i == ind){
			break;
		}
		curr = curr->next;
	}
	return curr->value;
}

int MyList::give(int ind, int val){
	if (ind >= this->length || ind < 0){
		return -1;
	}

	MyList *curr = this->next;
	for (int i=0; i<this->length; i++){
		if (i == ind){
			break;
		}
		curr = curr->next;
	}
	curr->value = val;
	return curr->value;
}

MyList::~MyList(){
	delete this->next;
	delete this->last;
}


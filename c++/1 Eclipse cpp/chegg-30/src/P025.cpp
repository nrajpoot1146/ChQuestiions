/*
 * P025.cpp
 *
 *  Created on: 24-Jul-2020
 *      Author:
 */

#include "P026.h"

MyList::MyList(){
	this->next = 0;
	this->last = 0;
	this->length = 0;
}

void MyList::prepend(int val){
	MyList *newNode = new MyList();
	newNode->value = val;
	if (this->length == 0){
		this->next = newNode;
		this->last = newNode;
		newNode->last = this->last;
		this->length++;
		return;
	}

	newNode->last = this->last;
	newNode->next = this->next;
	this->length++;
	this->next = newNode;
}

void MyList::append(int val){
	MyList *newNode = new MyList();
	newNode->value = val;
	if (this->length == 0){
		this->next = newNode;
		this->last = newNode;
		newNode->last = this->last;
		this->length++;
		return;
	}
	newNode->last = newNode;
	this->last->next = newNode;
	this->last = newNode;
	this->length++;
}

int MyList::get(int ind){
	if (ind >= this->length || ind<0){
		return -1;
	}

	int  i=0;
	MyList *curr = this->next;
	while (curr != 0){
		if (i == ind){
			return curr->value;
		}
		i++;
		curr = curr->next;
	}
}

int MyList::give(int ind, int val){
	if (ind >= this->length){
		return -1;
	}
	int  i=0;
	MyList *curr = this->next;
	while (curr->next == 0){
		if (i == ind){
			curr->value = val;
		}
		i++;
		curr->next = curr;
	}
}

int MyList::del(int ind){
	if (ind >= this->length || ind < 0){
		return -1;
	}

	if (ind == 0){
		this->next = this->next->next;
		this->length--;
		return 0;
	}

	int i = 1;
	MyList *prev = this->next;
	MyList *curr = prev->next;
	while (curr != 0){
		if (i == ind){
			prev->next = curr->next;
			break;
		}
		i++;
		curr = curr->next;
	}
	if (ind == this->length - 1){
		this->last = prev;
	}
	this->length--;
	return 0;
}

MyList::~MyList(){}



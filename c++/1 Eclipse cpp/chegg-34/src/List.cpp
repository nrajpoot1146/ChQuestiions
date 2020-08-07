/*
 * List.cpp
 *
 *  Created on: 26-Jul-2020
 *      Author:
 */

#include "List.h"

List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

void List::concatenate(const List &l2){
	ListNode *curr = l2.head;

	while (curr != NULL){
		this->append(curr->element);
		curr = curr->next;
	}
}

void List::append(const int &value){
	ListNode *newNode = new ListNode(value);
	this->size++;
	if (this->head == NULL){
		this->head = newNode;
		this->tail = newNode;
		return;
	}

	this->tail->next = newNode;
	this->tail = newNode;
}

void List::insert(const int &value){
	this->insertith(value, 0);
}

void List::insertith(const int &value, const size_t &i){
	ListNode *newNode = new ListNode(value);
	this->size++;
	if (this->head == NULL){
		this->head = newNode;
		this->tail = newNode;
		return;
	}

	if (i == 0){
		newNode->next = this->head;
		this->head = newNode;
		return;
	}

	ListNode *prev = this->head;
	ListNode *curr = prev->next;
	int j=1;
	while (curr != NULL){
		if (j == 1){
			prev->next = newNode;
			newNode->next = curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	this->tail->next = newNode;
	this->tail = newNode;
}

void List::remove(const int &value){

	while (this->head != NULL && this->head->element == value){
		this->head = this->head->next;
		this->size--;
	}

	if (this->head == NULL){
		return;
	}

	ListNode *prev = this->head;
	ListNode *curr = this->head->next;

	while (curr != NULL){
		if (curr->element == value){
			prev->next = curr->next;
			if (curr->next == NULL){
				this->tail = prev;
			}
			this->size--;
		} else {
			prev = curr;
		}
		curr = curr->next;
	}
}

void List::removeDups(){
	if (this->head == NULL){
		return;
	}
	List temp;
	temp.append(this->head->element);

	ListNode *prev = this->head;
	ListNode *curr = prev->next;

	while (curr != NULL){
		if (temp.search(curr->element)){
			prev->next = curr->next;
			if (curr->next == NULL){
				this->tail = prev;
			}
			this->size--;
		} else {
			temp.append(curr->element);
			prev = curr;
		}
		curr = curr->next;
	}
}

bool List::search(const int &value){
	ListNode *curr = this->head;

	while (curr != NULL){
		if (curr->element == value){
			return true;
		}
		curr = curr->next;
	}

	return false;
}

void List::makeEmpty(){
	delete this->head;
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

List::~List() {
	this->makeEmpty();
}

stringstream &operator<< (stringstream &ss, List &l){
	ListNode *curr = l.head;
	while (curr != NULL){
		ss<<curr->element;
		ss<<" -> ";
		curr = curr->next;
	}

	ss<<"NULL (size: "<<l.size<<")";
	return ss;
}


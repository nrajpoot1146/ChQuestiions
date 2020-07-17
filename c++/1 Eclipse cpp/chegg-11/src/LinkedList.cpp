/*
 * LinkedList.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include "LinkedList.h"
#include <iostream>

template<class Type>
LinkedList<Type>::LinkedList() {
	this->head = NULL;
	this->tail = NULL;
}

template<class Type>
void LinkedList<Type>::add(nodeType<Type> *node){
	if (this->isEmpty()){
		this->head = node;
		this->tail = node;
		return;
	}
	this->tail->setLink(node);
	this->tail = node;
}

template<class Type>
void LinkedList<Type>::add(const Type ele){
	nodeType<Type> *newNode = new nodeType<int>();
	newNode->setInfo(ele);
	this->add(newNode);
}

template<class Type>
void LinkedList<Type>::addFirst(nodeType<Type> *node){
	if(this->isEmpty()){
		this->head = node;
		this->tail = node;
		return;
	}

	node->setLink(this->head);
	this->head = node;
}

template<class Type>
void LinkedList<Type>::addFirst(const Type ele){
	nodeType<Type> *newNode = new nodeType<int>();
	newNode->setInfo(ele);
	this->addFirst(newNode);
}

template<class Type>
nodeType<Type>* LinkedList<Type>::getHead() const{
	return this->head;
}

template<class Type>
nodeType<Type>* LinkedList<Type>::getTail() const{
	return this->tail;
}

template<class Type>
nodeType<Type>* LinkedList<Type>::getNthNode(int n) const{
	nodeType<Type> *curr = this->head;
	while(--n>=0 && curr != NULL){
		curr = curr->getLink();
	}

	return curr;
}

template<class Type>
void LinkedList<Type>::print(){
	nodeType<Type> *curr = this->head;
	while (curr != NULL){
		std::cout<<curr->getInfo()<<" ";
		curr = curr->getLink();
	}
	std::cout<<std::endl;
}

template<class Type>
bool LinkedList<Type>::isEmpty(){
	return this->head == NULL;
}

template<class Type>
LinkedList<Type>::~LinkedList() {
	delete this->head;
	delete this->tail;
}


/*
 * nodeType.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include "nodeType.h"
#include <string>

template<class Type>
const nodeType<Type>& nodeType<Type>::operator =(const nodeType<Type> &otherNode){
	this->info = otherNode.info;
	this->link = otherNode.link;
}

template<class Type>
void nodeType<Type>::setInfo(const Type& ele){
	this->info = ele;
}

template<class Type>
Type nodeType<Type>::getInfo() const{
	return this->info;
}

template<class Type>
void nodeType<Type>::setLink(nodeType<Type> *ptr){
	this->link = ptr;
}

template<class Type>
nodeType<Type>* nodeType<Type>::getLink() const{
	return this->link;
}

template<class Type>
nodeType<Type>::nodeType() {
	this->link = NULL;
}

template<class Type>
nodeType<Type>::nodeType(const Type &elem, nodeType<Type> *ptr){
	this->info = elem;
	this->link = ptr;
}

template<class Type>
nodeType<Type>::nodeType(const nodeType<Type> &otherNode){
	this->info = otherNode.info;
	this->link = otherNode.link;
}

template <class Type>
nodeType<Type>::~nodeType() {
}


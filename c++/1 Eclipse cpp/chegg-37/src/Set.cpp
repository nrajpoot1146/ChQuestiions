/*
 * Set.cpp
 *
 *  Created on: 05-Aug-2020
 *      Author:
 */

#include "Set.h"

// default constructor
template <class T>
Set<T>::Set(){}

// function to add an item to items vector
template <class T>
void Set<T>::add(T item){
	cout<<"Adding: "<<item<<"\n";
	// check this class already has an item or not
	if (find(items.begin(), items.end(), item) != items.end()){
		// if yes do noothing
		return;
	}
	// if no add item into vector
	items.push_back(item);
}

// get number of items
template <class T>
int Set<T>::getNumberOfItems(){
	return this->items.size();
}

// get pointer to an array that contains each items of set
template <class T>
T *Set<T>::getPointerOfArray(){
	T *temp = new T[this->getNumberOfItems()];
	for (int i=0; i<this->getNumberOfItems(); i++){
		temp[i] = this->items[i];
	}
	return temp;
}


template <class T>
Set<T>::~Set() {}


/*
 * IntArr.cpp
 *
 *  Created on: 20-Jul-2020
 *      Author:
 */

#include "IntArr.h"

IntArr::IntArr(){
	this->capacity = 0;
	this->size = 0;
	this->array = NULL;
}

IntArr::IntArr(int capacity){
	this->capacity = capacity;
	this->size = 0;
	this->array = new int[this->capacity];
}

int IntArr::operator[](int index){
	if (index < this->size){
		return this->array[index];
	}
	throw "Index Out of Bound!";
}

IntArr::IntArr(const IntArr &o){
	this->capacity = o.capacity;
	this->size = o.size;
	this->array = new int[this->capacity];
	for (int i=0; i<o.size; i++){
		this->array[i] = o.array[i];
	}
}

void IntArr::operator=(const IntArr &o){
	this->capacity = o.capacity;
	this->size = o.size;
	this->array = new int[this->capacity];
	for (int i=0; i<o.size; i++){
		this->array[i] = o.array[i];
	}
}

void IntArr::grow(){
	int *newArray = new int[this->capacity * 2];
	for (int i=0; i<this->size; i++){
		newArray[i] = this->array[i];
	}
	this->capacity *= 2;
	delete[] this->array;
	this->array = newArray;
}

void IntArr::push_back(int i){
	if (this->size == this->capacity){
		grow();
	}
	this->array[this->size] = i;
	this->size++;
}

int IntArr::pop_back(){
	if (this->size != 0){
		this->size--;
		return this->array[this->size];
	}
	throw "Array is empty!";
}

int IntArr::getSize(){
	return this->size;
}

IntArr::~IntArr() {
	delete[] this->array;
}


/*
 * lab4-LabArray.cpp
 *
 *  Created on: 21-Jul-2020
 *      Author:
 */

#include "lab4-LabArray.h"

IntArr::IntArr(){
	this->capacity = 0;
	this->size = 0;
	this->data = 0;
}

IntArr::IntArr(int capacity){
	this->capacity = capacity;
	this->data = new int[this->capacity];
	this->size = 0;
}

int IntArr::getVal(int index){
	if(index < 0 || index >= this->size){
		throw "Error: Index out Of bound!";
	}
	return this->data[index];
}

int IntArr::getCapacity(){
	return this->capacity;
}

int IntArr::getSize(){
	return this->size;
}

void IntArr::insertVal(int val){
	if (this->size == this->capacity){
		throw "Error: Array is overflow!";
	}
	this->data[this->size] = val;
	this->size++;
}

int IntArr::removeVal(){
	if(this->size > 0){
		this->size--;
		return this->data[this->size+1];
	}
	throw "Error: array is underflow!";
}

IntArr::~IntArr(){
	delete[] this->data;
}


/*
 * Stack.cpp
 *
 *  Created on: 29-Jun-2020
 *      Author: naren
 */

#include "Stack.h"

template <class T, const int CAPACITY>
Stack<T, CAPACITY>::Stack() {
	this->nelement = 0;
	this->capaity = CAPACITY;
}

template <class T, const int CAPACITY>
void Stack<T, CAPACITY>::push(T e){
	this->list.setpos(this->nelement);
	this->list.insertafter(e);
	this->nelement++;
}

template <class T, const int CAPACITY>
T Stack<T, CAPACITY>::pop(){
	if (!this->isEmpty()){
		this->list.setpos(this->nelement - 1);
		this->nelement--;
		return this->list.getelement();
	}
	throw "stack is empty!";
}

template <class T, const int CAPACITY>
T Stack<T, CAPACITY>::top(){
	if (!this->isEmpty()){
		this->list.setpos(this->nelement - 1);
		return this->list.getelement();
	}
	throw "stack is empty!";
}

template <class T, const int CAPACITY>
bool Stack<T, CAPACITY>::isEmpty(){
	return this->nelement == 0;
}

template <class T, const int CAPACITY>
bool Stack<T, CAPACITY>::isFull(){
	return this->nelement == CAPACITY;
}

template <class T, const int CAPACITY>
Stack<T, CAPACITY>::~Stack(){

}


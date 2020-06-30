/*
 * Stack.h
 *
 *  Created on: 29-Jun-2020
 *      Author: naren
 */

#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include "List.h"

template <class T, const int CAPACITY>
class Stack {
	List<T, CAPACITY> list;
	int capaity;
	int nelement;
public:
	/**
	 * default constructor
	 * set nelement to 0;
	 * set capacity to CAPACITY
	 */
	Stack();

	/**
	 * push an element into stack
	 * @param e element to be push
	 */
	void push(T e);

	/**
	 * pop an element from stack
	 * @return popped from stack
	 */
	T pop();

	/**
	 * get element from top of the stack
	 */
	T top();

	/**
	 * check whether stack is empty or not
	 * @return true if stack is empty otherwise return false
	 */
	bool isEmpty();

	/**
	 * check whether stack is full or not
	 * @return true if stack is full otherwise return false
	 */
	bool isFull();
	virtual ~Stack();
};

#endif /* SRC_STACK_H_ */

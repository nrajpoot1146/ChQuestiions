/*
 * IntArr.h
 *
 *  Created on: 20-Jul-2020
 *      Author:
 */

#ifndef SRC_INTARR_H_
#define SRC_INTARR_H_
#include <iostream>

class IntArr{
	int capacity; // maximum number of elements in the array
	int size; // current number of elements in the array
	int *array; // a pointer to a dynamic array of integers
public:

	/**
	 * default constructor
	 * sets capacity 0
	 * sets size 0;
	 * sets array NULL
	 */
	IntArr();

	/**
	 * user constructor
	 * sets capacity to given capacity
	 * sets size to 0
	 * create a dynamic array of given capacity
	 * @param capacity size of an array
	 */
	IntArr(int capacity);

	/**
	 * overloaded subscript operator
	 * return an element or exits if illegal index
	 */
	int operator[](int index);

	/**
	 * copy constructor
	 * @param o another object of IntArray
	 */
	IntArr(const IntArr &o);

	/**
	 * overloaded assignment operator
	 * @param o another object
	 */
	void operator=(const IntArr &o);

	/**
	 * grow array to twise of it's capacity
	 */
	void grow();

	/**
	 * push an element end of the array
	 * @param e element to be push
	 */
	void push_back(int e);

	/**
	 * remove the last element in the array
	 */
	int pop_back();

	/**
	 * @return the current size of the array (not capacity)
	 */
	int getSize();

	virtual ~IntArr();
};

#endif /* SRC_INTARR_H_ */

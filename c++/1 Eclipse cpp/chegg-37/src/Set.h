/*
 * Set.h
 *
 *  Created on: 05-Aug-2020
 *      Author:
 */

#ifndef SRC_SET_H_
#define SRC_SET_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class template that represent a set of items
// set has no common items
template <class T>
class Set{
	vector<T> items; // vector to store items
	public:
		Set();
		// function to add an item to items vector
		void add(T item);

		// get number of items
		int getNumberOfItems();

		// get pointer to an array that contains each items of set
		T *getPointerOfArray();

		virtual ~Set();
};

#endif /* SRC_SET_H_ */

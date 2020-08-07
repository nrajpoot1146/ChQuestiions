/*
 * List.h
 *
 *  Created on: 26-Jul-2020
 *      Author:
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <sstream>
#include "ListNode.h"
using namespace std;

class List {
	ListNode *head;
	ListNode *tail;
	int size;
public:
	/**
	 * default constructor
	 * set head to null
	 * set tail to null
	 * set size to 0
	 */
	List();

	/**
	 * concatenate other list with this list
	 * Precondition: l1and 12are linked lists. The lists may be empty or non-empty.
	 * Postcondition: A copy of list l2is concatenated (added to the end) of list l1.
	 * 				List l2should be unchanged by the function.
	 */
	void concatenate(const List &l2);

	/**
	 * append a value at the end of the list
	 * @param value to be append
	 */
	void append(const int &value);

	/**
	 * insert a value at the beginning of the list
	 * @param value to be insert
	 */
	void insert(const int &value);

	/**
	 * insert a velue at ith position
	 * Precondition: The list may be empty or non-empty.
	 * Postcondition: The number value is inserted as the ith member of the list. If the list has fewer than i-1nodes in it,
	 * 				then value is inserted as the last node in the list.
	 */
	void insertith(const int &value, const size_t &i);

	/**
	 * remove a value from list
	 * @param value to be remove
	 */
	void remove(const int &value);

	/**
	 * remove all duplicates of each elements from the list
	 * Precondition: The list may be empty or non-empty.
	 * Postcondition: Each node in the list must have a unique element value.
	 */
	void removeDups();

	/**
	 * search whether given value exist or not
	 * @return true if exist otherwise return false
	 */
	bool search(const int &value);

	/**
	 * make this list empty
	 */
	void makeEmpty();

	/**
	 * friend function
	 * overloaded insertion operator
	 * for string stream
	 */
	friend stringstream &operator<< (stringstream &ss, List &l);

	/**
	 * default destructor
	 * make this list empty
	 */
	virtual ~List();
};


#endif /* LIST_H_ */

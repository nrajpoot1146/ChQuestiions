/*
 * LinkedList.h
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
	Node *head;
	Node *tail;
public:

	/**
	 * default constructor
	 * set head = NULL
	 * set tail = NULL
	 */
	LinkedList();

	/**
	 * add an element to LinkedList
	 * if list is empty create new node and set head ant tail node to new node
	 * if head.data is equal to data then do nothing return
	 * if anyNode.data is equal to data swap current node data with previous node return
	 * if data is not exist in linked list add it to next node of tail
	 * @param data to be insert
	 */
	void add(int data);

	/**
	 * add an newNode to LinkedList
	 * if list is empty create new node and set head ant tail node to new node
	 * if head.data is equal to newNode.data then do nothing return
	 * if anyNode.data is equal to newNode.data swap current node data with previous node return
	 * if newNode.data is not exist in linked list add it to next node of tail
	 * @param  newNode to be insert
	 */
	void add(Node* newNode);

	/**
	 * print data of all node of linked list;
	 */
	void print();

	/**
	 * check current list is empty or not
	 * @return if list is empty return true otherwise return false
	 */
	bool isEmpty();
	virtual ~LinkedList();
};

#endif /* SRC_LINKEDLIST_H_ */

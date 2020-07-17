/*
 * LinkedList.h
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_
#include "nodeType.cpp"

template<class Type>
class LinkedList {
public:
	/**
	 * default constructor
	 */
	LinkedList();

	/**
	 * append a node
	 * @param node to be append
	 */
	void add(nodeType<Type> *node);

	/**
	 * append new element
	 * @param ele element to be append
	 */
	void add(const Type ele);

	/**
	 * prepend new node
	 * @param node to be prepend
	 */
	void addFirst(nodeType<Type> *node);

	/**
	 * prepend new element
	 * @param ele element to be prepend
	 */
	void addFirst(const Type ele);

	/**
	 * get pointer to head node
	 * @return pointer to head node
	 */
	nodeType<Type> *getHead() const;

	/**
	 * get pointer to tail node
	 * @return pointer to tail node
	 */
	nodeType<Type> *getTail() const;

	/**
	 * get nth node from head node
	 * @return nth node from head node
	 */
	nodeType<Type> *getNthNode(int n) const;

	/**
	 * print info of all node
	 */
	void print();

	/**
	 * check linked list is empty or not
	 * @return true if linked list is empty otherwise return false
	 */
	bool isEmpty();
	virtual ~LinkedList();

private:
	nodeType<Type> *head;
	nodeType<Type> *tail;
};

#endif /* SRC_LINKEDLIST_H_ */

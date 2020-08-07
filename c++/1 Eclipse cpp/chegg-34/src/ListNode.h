/*
 * ListNode.h
 *
 *  Created on: 26-Jul-2020
 *      Author:
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_
#include <iostream>

struct ListNode {
	int element;
	ListNode *next;
public:
	/**
	 * default constructor
	 * set next to null
	 * set element to value
	 */
	ListNode(int value);

	/**
	 * default destructor
	 * free next node memory
	 */
	virtual ~ListNode();
};

#endif /* LISTNODE_H_ */

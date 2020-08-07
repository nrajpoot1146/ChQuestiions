/*
 * ListNode.cpp
 *
 *  Created on: 26-Jul-2020
 *      Author:
 */

#include "ListNode.h"

ListNode::ListNode(int value) {
	this->element = value;
	this->next = NULL;
}

ListNode::~ListNode() {
	delete this->next;
}


/*
 * Node.h
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_
#include<string>
struct Node{
	int data;
	Node *next;

	/**
	 * @param data of current node
	 * @param link of next node
	 */
	Node(int data, Node *next){
		this->data = data;
		this->next = next;
	}

	/**
	 * @param data of current node
	 * set next to NULL
	 */
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

#endif /* SRC_NODE_H_ */

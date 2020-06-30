/*
 * Node.h
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

/**
 * template Node class
 * this class have two attributes
 * T data to store data on current node
 * Node<T> *next to store link to next address
 */
template<typename T>
class Node{
public:
	T data;
	Node<T> *next;

	/**
	 * parameterized constructor to create a node;
	 */
	Node(const T &data, Node<T> *next){
		this->data = data;
		this->next = next;
	}
};


#endif /* SRC_NODE_H_ */

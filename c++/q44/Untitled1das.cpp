/*
 * LinkedList.h
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_
//#include "Node.h"

template <typename T>
class LinkedList{
private:
//	Node<T> *head;
//	Node<T> *tail;
public:
	LinkedList(){
//		this->tail = NULL;
//		this->head = NULL;
	}

	void printList() const;
	void append(const T data);
	void prepand(const T data);
	bool insert(const T data);
	bool remove(const T data);
	bool find(const T data);
	bool isEmpty() const;
	T getFirst() const;
	T getLast() const;

	~LinkedList(){

	}
};

//void LinkedList::printList(){
//
//}
template<typename T>
void LinkedList::prepand(const T data){
	
}

#endif /* SRC_LINKEDLIST_H_ */


/*
 * LinkedList.h
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

template <typename T>
class LinkedList{
private:
	Node<T> *head;
	Node<T> *tail;
public:
	/**
	 * default constructor
	 * set head to null
	 * set tail to null
	 */
	LinkedList(){
		this->tail = NULL;
		this->head = NULL;
	}

	/**
	 * print each element of link list
	 * if list is empty print nothing
	 */
	void printList() const;

	/**
	 * function to append an element at the end of the list
	 * @param data to be append
	 *
	 */
	void append(const T data);

	/**
	 * function to insert an element before head node
	 * @param data to be prepand
	 */
	void prepand(const T data);

	/**
	 * function to insert an element in sorted order
	 * @param data to be insert
	 * @return true if element is successfully insert otherwise return false
	 */
	bool insert(const T data);

	/**
	 * function to remove an element from the list
	 *  @param data to be removed
	 *  @return true if element is successfully removed otherwise return false
	 */
	bool remove(const T data);

	/**
	 * fucntion to find an element in current list
	 * @param data to be find from the list
	 * @retrun true if data is successfully find otherwise return false
	 */
	bool find(const T data);

	/**
	 * check current list is empty or not
	 * @return true if list is empty otherwise return false
	 */
	bool isEmpty() const;

	/**
	 * function to get first element from the list
	 * @return first element of the list
	 */
	T getFirst() const;

	/**
	 * function to get last element of the list
	 * @return last element of the list
	 */
	T getLast() const;

	/**
	 * Destructor of class
	 */
	~LinkedList(){
		delete this->head;
	}
};

template <typename T>
void LinkedList<T>::printList() const{
	Node<T> *curr = this->head;

	while(curr != NULL){
		cout<<curr->data<<endl;
		curr = curr->next;
	}
}

template <typename T>
void LinkedList<T>::append(const T data){
	Node<T> *newNode = new Node<T>(data, NULL);
	if(this->head == NULL){
		this->head = newNode;
		this->tail = newNode;
		return;
	}

	this->tail->next = newNode;
	this->tail = newNode;
}

template <typename T>
void LinkedList<T>::prepand(const T data){
	Node<T> *newNode = new Node<T>(data, NULL);
	if(this->head == NULL){
		this->head = newNode;
		this->tail = newNode;
		return;
	}

	newNode->next = this->head;
	this->head = newNode;
}

template <typename T>
bool LinkedList<T>::insert(const T data){
	if(this->head == NULL){
		this->append(data);
		return true;
	}

	if(data <= this->head->data){
		this->prepand(data);
		return true;
	}

	if(data >= this->tail->data){
		this->append(data);
		return true;
	}

	if(data > this->head->data && data < this->tail->data){
		Node<T> *curr = this->head;

		while( curr != NULL){
			if(data > curr->data && data < curr->next->data){
				break;
			}
			curr = curr->next;
		}

		Node<T> *newNode = new Node<T>(data, curr->next);
		curr->next = newNode;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::remove(const T data){
	if(isEmpty()){
		return false;
	}

	if(this->head->data.equals(data)){
		this->head = this->head->next;
		return true;
	}

	Node<T> *curr = this->head->next;
	Node<T> *pre = this->head;
	while(curr != NULL){
		if( curr->data.equals(data)){
			pre->next = curr->next;
			return true;
		}
		pre = curr;
		curr = curr->next;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::find(const T data){
	if(isEmpty()){
		return false;
	}

	Node<T> *curr = this->head;
	while(curr != NULL){
		if( curr->data.equals(data)){
			return true;
		}
		curr = curr->next;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::isEmpty() const{
	if(this->head == NULL){
		return true;
	}
	return false;
}

template <typename T>
T LinkedList<T>::getFirst() const{
	if(!this->isEmpty()){
		return this->head->data;
	}
	return NULL;
}

template <typename T>
T LinkedList<T>::getLast() const{
	if(!this->isEmpty()){
		return this->tail->data;
	}
	return NULL;
}

#endif /* SRC_LINKEDLIST_H_ */

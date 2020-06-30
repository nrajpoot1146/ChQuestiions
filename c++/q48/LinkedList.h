/*
 * LinkedList.h
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print data of all node of linked list;
 */
void print(struct Node *head){
    if(head == NULL){
		printf("Linked list is empty: \n"); // show message if list is empty
		return;
	}

	while(head != NULL){
		printf("%d->", head->data); // print data of node
		head = head->next;
	}

	printf("NULL\n");
}

/**
 * add an element to LinkedList
 * if list is empty create new node and set head ant tail node to new node
 * if head.data is equal to data then do nothing return
 * if anyNode.data is equal to data swap current node data with previous node return
 * if data is not exist in linked list add it to next node of tail
 * @param data to be insert
 */
void add(int data, struct Node **head){
    // if list is empty create new node and initialize head and tail to newNode

	if(*head == NULL){
		struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		*head = newNode;
		return;
	}

	// if data is equal to head data return do nothing
	if((*head)->data == data){
		return;
	}

	struct Node *curr = *head;
	struct Node *pre = curr;
	while(curr != NULL){
		if(curr->data == data){
			// swap current node data to previous node data
			curr->data = pre->data;
			pre->data = data;
			return;
		}
		pre = curr;
		curr = curr->next;
	}

	// if node is not exist then add newNode as last node of current linked list
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	pre->next = newNode;
}

#endif // SRC_LINKEDLIST_H_

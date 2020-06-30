/*
 * main.c
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#include "LinkedList.h"
#include "Node.h"

struct Node *head = NULL;

int main(){
	add(11, &head);
	add(22, &head);
	add(44, &head);
	add(33, &head);
	add(55, &head);

	// element of current linked list
	printf("element of current linked list: \n");
	print(head);

	printf("\n");
	// add 44 to current linked list
	add(44, &head);
	printf("after adding 44: \n");
	print(head);

	printf("\n");
	// add 11 to current linked list
	add(11, &head);
	printf("after adding 11 to current linked list: \n");
	print(head);

	printf("\n");
	// add 56 to current linked list
	add(56, &head);
	printf("after adding 56 to current linked list: \n");
	print(head);

}



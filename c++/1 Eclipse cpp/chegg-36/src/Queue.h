/*
 * Queue.h
 *
 *  Created on: 28-Jul-2020
 *      Author: naren
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * structure for queue
 * *array to store items
 * capacity maxSize of queue
 */
struct queue{
	int *array;
	int capacity;
	int front;
	int rear;
};


typedef struct queue *Queue;

/**
 * function to create queue of given size
 */
Queue queueCreate(int maxSize);

/**
 * function to enqueue an item into queue
 */
void enqueue(Queue q, int item);

/**
 * function to get an item from front of the queue
 */
int queueFront(Queue q);

/**
 * function to dequeue an item from the queue
 */
int dequeue(Queue q);

/**
 * function to get size of the given queue
 */
int queueSize(Queue q);

/**
 * function to destroy given queue
 */
void queueDestroy(Queue q);



#endif /* SRC_QUEUE_H_ */

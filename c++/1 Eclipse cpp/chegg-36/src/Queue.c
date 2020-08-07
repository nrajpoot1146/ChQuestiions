/*
 * Queue.cpp
 *
 *  Created on: 28-Jul-2020
 *      Author: naren
 */

#include "Queue.h"


Queue queueCreate(int maxSize){
	Queue q = (Queue) malloc(sizeof(struct queue));
	q->array = (int *) malloc(sizeof(int) * maxSize);
	q->front = -1;
	q->rear = -1;
	q->capacity = maxSize;
	return q;
}

void enqueue(Queue q, int item){
	if (q->rear +1 != q->capacity){
		if (q->rear == -1){
			q->front++;
		}
		q->rear++;
		q->array[q->rear] = item;
	}
}

int queueFront(Queue q){
	if (q->front == -1){
		return -1;
	}
	return q->array[q->front];
}

int dequeue(Queue q){
	int front = q->array[q->front];
	q->front++;
	if (q->front > q->rear){
		q->front = -1;
		q->rear = -1;
	}
	return front;
}

int queueSize(Queue q){
	if(q->front == -1){
		return 0;
	}

	return (q->rear - q->front + 1);
}
void queueDestroy(Queue q){
	free(q);
}

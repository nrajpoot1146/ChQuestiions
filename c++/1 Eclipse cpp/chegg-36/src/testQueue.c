/*
 * testQueue.c
 *
 * this is my testQueue file. you can use your own
 *
 *  Created on: 28-Jul-2020
 *      Author: naren
 */
#include "Queue.h"

int main(){
	// create a queue
	Queue q = queueCreate(5);
	enqueue(q, 23);
	enqueue(q, 20);
	enqueue(q, 34);

	// test for function queueSize
	if (queueSize(q) == 3){
		printf("test Queue size passed.\n");
	} else {
		printf("test Queue size failed.\n");
	}

	// test for function queueFront
	if (queueFront(q) == 23){
		printf("test Queue front passed.\n");
	} else{
		printf("test Queue front failed.\n");
	}

	// test for function dequeue;
	dequeue(q);
	if (queueFront(q) == 20){
		printf("test deQueue passed.\n");
	} else{
		printf("test deQueue front failed.\n");
	}

	queueDestroy(q);
}


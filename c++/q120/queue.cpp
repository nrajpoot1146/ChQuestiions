#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;  

node *initQueue()
{
	node *p = (node *)malloc(sizeof(node));
	p->next = NULL;
	// p->data = 0;
	return p;
}

node *enQueue(int data, node *rear)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	// printf("IN: %d\n", temp->data);
	rear->next = temp;
	rear = temp;
	return rear;
}

// when you use signle rear pointer and update rear it does not change the value of rear pointer in main function.
void *deQueue(node *top, node **rear) // old: void *deQueue(node *top, node *rear)
{
	if(top->next == NULL)
	{
		printf("Queue empty!\n");
	}
	else
	{
		node *del = top->next;
		printf("%d\n", del->data);
		//printf("%d\n", top->next->data);
		top->next = del->next;
		if(top->next == *rear) // old: top->next == rear
		{
			*rear = top; // old: rear = top
		}
		free(del);
	}
}

int main()
{
	node *top, *rear;
	top = rear = initQueue();
	deQueue(top, &rear); // old: deQueue(top, rear)
	rear = enQueue(100, rear);  
	rear = enQueue(20, rear);
	rear = enQueue(30, rear);
	deQueue(top, &rear); // old: deQueue(top, rear)
	deQueue(top, &rear); // old: deQueue(top, rear)
	deQueue(top, &rear); // old: deQueue(top, rear)
	deQueue(top, &rear); // old: deQueue(top, rear)
	rear = enQueue(200, rear);
	rear = enQueue(300, rear);
	
	deQueue(top, &rear); // old: deQueue(top, rear)
	return 0;
}

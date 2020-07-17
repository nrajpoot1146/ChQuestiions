#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Node to store data and address of next next
struct Node{
	int data;
	struct Node *next;
} ;

// Stack type
typedef struct Stack
{
	int nelements;
	struct Node* top;
	struct Node* back;
} Stack;

// Stack Operations
struct Stack* createStack()
{
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	
	if (!stack) return NULL;
	
	stack->top = NULL;
	stack->nelements = 0;
	
	return stack;
}

/**
* check stack is empty or not
*/
int isEmpty(Stack* stack)
{
	return stack->top == NULL;
}

/*
* return peek of stack
*/
int peek(Stack* stack)
{
	return stack->top->data;
}

/**
* return top of stack and pop element from top of stack
*/
int pop(Stack* stack)
{
	if (!isEmpty(stack)){
		char top = stack->top->data;
		stack->top = stack->top->next;
		stack->nelements--;
		return top;
	}
	return '$';
}

/*
* push an element into stack
*/
void push(Stack* stack, char op)
{
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node*));
	newNode->next = NULL;
	newNode->data = op;
	if (isEmpty(stack)){
		stack->top = newNode;
		stack->nelements++;
		return;
	}
	
	newNode->next = stack->top;
	stack->top = newNode;
}


// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	Stack* stack = createStack();
	int i;
	
	// See if stack was created successfully
	if (!stack) return -1;
	
	// Scan all characters one by one
	for (i = 0; i<strlen(exp); ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.

		if (isdigit(exp[i])){
			push(stack, exp[i] - '0');
		}
		
		
		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else if(exp[i] != ' ')
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			
			switch (exp[i])
			{
				case '+': push(stack, val2 + val1); break;
				case '-': push(stack, val2 - val1); break;
				case '*': push(stack, val2 * val1); break;
				case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions
int main()
{
	char exp [20] ;
	Stack* stack = createStack();
	printf("Enter a postfix expression: (i.e. 2 3 + 4 *)\n");
	gets(exp); // read an expression
	
	printf ("postfix evaluation: %d", evaluatePostfix(exp));
	return 0;
}

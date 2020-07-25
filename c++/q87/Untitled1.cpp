
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// structure of stack
struct stack{
	int *array;
	int top;
	int capacity;
};

typedef struct stack Stack;

// create an stack of given size
// return pointer to stack
Stack *createStack(int size){
	int *array = (int *) malloc(sizeof (int) * size);
	Stack *s = (Stack *) malloc(sizeof(Stack));
	s->array = array;
	s->top = -1;
	s->capacity = size;
}

// check given stack is empty or not
// return 1 if stack is empty
// return 0 otherwise
int isEmpty(const Stack *s){
	if (s->top < 0){
		return 1;
	}
	return 0;
}

// set top of the stack to -1
// this mean stack is empty
void clear(Stack *s){
	s->top = -1;
}

// check given stack is full or not
// return 1 if stack is full
// return 0 otherwise
int isFull(const Stack *s){
	if (s->top+1 == s->capacity){
		return 1;
	}
	return 0;
}

// push given element into stack
void push(Stack *s, int val){
	if (!isFull(s)){
		s->top++;
		s->array[s->top] = val;
	}
}

// pop an element from stack
// return popped element
// otherwise throw empty stack error
int pop(Stack *s){
	if (!isEmpty(s)){
		int top = s->array[s->top];
		s->top--;
		return top;
	}
}

// solve given postfix expression
// return result of expression
// if given expression is malformed then throw an exception
int solvePostfixExp(Stack *s, char exp[], char error[]){
	int i=0;
	while(exp[i] != '\0'){
		if (isspace(exp[i])){

		}else if(exp[i] >= '0' && exp[i] <= '9'){
			int num = exp[i] - '0';
			push(s, num);
		} else {
			char op = exp[i];
			int first = 0;
			int second = 0;
			int result = 0;

			if (!isEmpty(s)){
				first = pop(s);
			}else{
				strcpy(error, "expression is malformed!");
			}

			if(!isEmpty(s)){
				second = pop(s);
			}else{
				strcpy(error, "expression is malformed!");
			}

			if (op == '+'){
				result = first + second;
			} else if(op == '-'){
				result = second - first;
			} else if(op == '*'){
				result = first * second;
			} else if(op == '/'){
				result = second / first;
			} else{
				strcpy(error, "Invalid character in input expression!");
			}

			push(s, result);

		}
		i++;
	}

	int result = pop(s);
	if (!isEmpty(s)){
		strcpy(error, "Invalid expression!");
	}

	return result;
}

// main driver function
int main(){
	Stack *s = createStack(200);
	char filename[20];
	char exp[200];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE *fp = fopen(filename, "r");

	if (fp == NULL){
		puts("Invalid filename!");
		exit(0);
	}

	while (fgets(exp, 200, fp) != NULL){
		char error[20];
		strcpy(error, "");
        int result = solvePostfixExp(s, exp, error);
        if (strlen(error)== 0)
            printf("The value of the expression %s is %d\n", exp, result);
        else
			printf("%s\n", error);

//		printf("More expressions (Y or N)? ");
//		char c;
//		c = getc(stdin);
//		getc(stdin);
//		if (c == 'N' || c == 'n') {
//			break;
//		}
	}

}


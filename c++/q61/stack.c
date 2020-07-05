
#include "stack.h"
#include <stdlib.h>

// return peek of stack
void *peek(Stack * stack){
    if (isempty(stack)){
        return NULL;
    }
    return stack->elements[stack->num_elements - 1];
}

// pop and return popped element from stack
void *pop(Stack * stack){
    if (isempty(stack)){
        return NULL;
    }
    void *top = stack->elements[stack->num_elements - 1];
    stack->num_elements--;
    return top;
}

// push back an element into stack
void *push(Stack * stack, void *element){

    stack->elements[stack->num_elements] = element;
    stack->num_elements++;
}

// return true if stack is empty otherwise return false
int isempty(Stack * stack){
    return stack->num_elements == 0;
}

// return number of elements in stack
int numelements(Stack * stack){
    return stack->num_elements;
}

// create new stack and return its pointer
Stack *create(int size){
    Stack *stk = (Stack *) malloc(sizeof(Stack));
    stk->elements = malloc(sizeof(void*) * size);
    stk->top = &(stk->elements[0]);
    stk->num_elements = 0;
    return stk;
}

// free all memory allocate to stack
void destroy(Stack * stack){
    free(stack);
}

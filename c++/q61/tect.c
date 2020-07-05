
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(int argc, char *argv[]){
    Stack *stack = create(9);
    int a = sizeof(stack->elements); /// sizeof(void*);
    printf("%d",a);
}

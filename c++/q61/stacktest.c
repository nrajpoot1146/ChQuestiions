#include <stdio.h>
#include "stack.c"

int main (int argc, char *argv[]) {
    Stack *the_stack;
    char *test_data[] = {"first", "second", "third", "fourth", "fifth"};
    int size = atoi(argv[1]);

    // Create a stack to hold our test data
    the_stack = create(size);

    printf ("sizeof(test_data)) == %ld\n", sizeof(test_data));


    for (int i = 0; i < (sizeof(test_data) / sizeof(char *)); i++) {
        #ifdef DEBUG_TEST

        printf("pushing element \"%s\"\n", test_data[i]);
        #endif
        push(the_stack, test_data[i]);
        #ifdef DEBUG_TEST
        printf("top of stack now \"%s\"\n", (char *) peek(the_stack));
        #endif
    }

    // Now pop the elements off the stack
    while (!isempty(the_stack)) {
        char *element = (char *) pop(the_stack);

        /* code to only compile when SOME_SYMBOL is defined */

        printf("popped element \"%s\"\n", element);

    }

    return 0;
}

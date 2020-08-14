#include <string.h>
#include <stdlib.h>

struct juice_case {
    char name[128];
    int num_bottles;
};

struct juice_case* create_case(char *new_name, int new_number) {
    // allocate memory for new case
    struct juice_case *newCase = (struct juice_case *) malloc(sizeof (struct juice_case));
    strcpy(newCase->name, new_name); // copy name of case
    newCase->num_bottles = new_number; // assign number of bottles

    return newCase;
}

void main() {
    struct juice_case *jCase = create_case("Mango", 5); // call create_case method

    printf("Case name: %s\n", jCase->name); // print name of case
    printf("Number of bottles: %d\n", jCase->num_bottles); // print number of bottles
}

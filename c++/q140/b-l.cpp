#include <stdio.h>
#include <inttypes.h>
int main(){
    uint32_t dt = 1; // declare and initialize variable of size 32bit
    uint8_t *p; // declare a pointer
    p = (uint8_t *)&dt; //type cast and assign address of variable dt to pointerr p
    if (*p == 1){ // condition for little endiann
        printf("little endiann system");
    }
    else if (*p == 0){ // consdition for big endiann
        printf("big endiann system");
    }
    return 0; // return 0 for successfull execution
}
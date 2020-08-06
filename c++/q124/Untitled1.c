#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // old: #define SIZE = 10

// function prototype
// this is function prototype so remove "{}"
void ShowFunction(const int b[], size_t startSubscript, size_t size); // old: void ShowFunction(const int b[], size_t startSubscript, size_t size){}

int main(void){
    int arr[SIZE] = { 5, 4, 2, 6, 8, 0, 9, 5, 4, 3}; // initialize arr
    puts("Answer is: ");
    ShowFunction(arr, 0, SIZE);
    puts("");
} // end main

// swap size and startSubscript variable for correct output
void ShowFunction (const int b[], size_t startSubscript,  size_t size){ // old: void ShowFunction (const int b[], size_t size, size_t startSubscript)
    if (startSubscript < size){
        ShowFunction(b, startSubscript + 1, size);
        // put space to identify difference between two numbers+
        printf("%d ", b[startSubscript] + b[startSubscript] / 3);
    } // end if
} // end function someFunction

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Number of lines in the input text
#define SIZE 4
// Maximum number of distinct words in the text
#define WORDS 100

// Prototype of the function that will print out the array of char pointers (String), line by line
void printText(char *lines[]);

// Prototype of the function that will capitalize all the letters inside its parameter (String)
void toUpperString(char *st);

int main(void) {

        // The text content is stored in an array of pointers to characters (String)
        char *lines[SIZE] = {"Hello dear. My name is c. What is your my name?",
                             "This is a test to check your capability programming in C.",
                             "Please try to write a C program to extract the frequency of distinct words in a text.",
                             "Then, try it on this text. Good luck!"};

        // Declaration of the array word, to keep distinct words from the text above
        char *word[WORDS];
        // Declaration and initialization of the array count, to keep the distinct words' frequencies
        int count[WORDS] = {0};
        // Declaration and initialization of a variable currentIndex, to record the current number of words inside the arrays word and count
        int currentIndex = 0;

        // COMPLETE THIS PART
        // ******************
        // Print out the text by calling printText function
		

        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // Declaration of a one dimensional array of characters, called line
        // You can figure out the length of the array from variable lines above, and using strlen function


        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // Store the text from the array lines to array line using strcpy and strcat






        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // Start tokenizing the array line using delimiters space, period, comma, question mark, and exclamation mark.


        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // In a while loop, for each token, which is actually a word:
        //              Capitalize the token
        //              Compare the token with the current words in array word
        //              If the token already exists inside the array word, update the frequency of the corresponding word inside the array count
        //              If the token does not exist inside the array word, add it and update its frequency
        //              Then get the next token
        // Until there is no more token






















        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // Print out the word frequency table











        // ^^^^^^^^^^^^^^^^^^

}

void printText(char *lines[]) {

        puts("The text is:");
        puts("============");

        // COMPLETE THIS PART
        // ******************
        // Print out the text, line by line, using a for loop





        // ^^^^^^^^^^^^^^^^^^

        puts("=======================");

}

void toUpperString(char *st) {

        // COMPLETE THIS PART
        // ******************
        // In a loop, capitalize every character inside the parameter st






        // ^^^^^^^^^^^^^^^^^^

}

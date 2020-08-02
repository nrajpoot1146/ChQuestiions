#include <stdio.h>
#include <string.h>

void main(){
    char word1[50], word2[50]; // declare two character array of length 50
    char commonWord[50]; // character array to store result
    // infinite loop
    while (1){
        int i=0;
        printf("Enter two words:\n");
        scanf("%s%s", word1, word2); // read two words from stdin

        while (i < strlen(word1) && i < strlen(word2)){
            if (word1[i] != word2[i]){ // compare character of two words
                break;
            }
            commonWord[i] = word1[i];
            i++;
        }

        commonWord[i] = '\0';

        // print result
        if(strlen(commonWord) == 0){ // if word length == 0
            printf("No common start\n"); // print no common starting
        } else {
            printf("%s\n", commonWord); // otherwise print common starting word
        }

    }
}

#include <stdio.h>

/**
* function to remove characters 'A','a','E','e'
* removed character replaced by space ' '
* @param s1 a pointer to character array
* @return number of removed characters
*/
int remove_characters(char *s1){
    int i = 0;
    // variable to store number of removed character
    int count = 0;
    while (s1[i] != '\0'){
        if (s1[i] == 'A' || s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'E'){
            // if character is matched then replaced by space
            s1[i] = ' ';
            count++;
        }
        i++;
    }
    // print new String
    printf("\n%s\n", s1);
    return count;
}

void main(){
    char str[30];
    printf("Enter a string without space: ");
    // read character string from console
    scanf("%s", str);

    int count = remove_characters(str);

    // print number of removed characters
    printf("%d\n",count);
}

#include<stdio.h>

int main() {
    // array initialization
    char A[50][50]={"aa","bb","cc","dd","ee","ff","gg","hh","ii","jj","kk","ll"};
    int i=0;
    char c;
    // print first three string
    printf("%d.%s\n",i,A[i]);
    i++;
    printf("%d.%s\n",i,A[i]);
    i++;
    printf("%d.%s\n",i,A[i]);

    do {
        c = getch(); // read single character
        if (c == 'N' || c == 'n') {
            i++;
            printf("%d.%s\n",i,A[i]);
            i++;
            printf("%d.%s\n",i,A[i]);
            i++;
            printf("%d.%s\n",i,A[i]);
        } else if (c == 'P' || c == 'p') {
            i-=5;
            i = i < 0? 0: i;
            printf("%d.%s\n",i,A[i]);
            i++;
            printf("%d.%s\n",i,A[i]);
            i++;
            printf("%d.%s\n",i,A[i]);
        }
    } while (c != 'Q' && c != 'q'); // termination condition

}

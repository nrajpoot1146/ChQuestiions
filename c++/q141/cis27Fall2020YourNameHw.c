#include <stdio.h>
#include <stdlib.h>

// structure to store key value pair
struct pair{
    int num;
    int freq;
};
typedef struct pair Pair;

// information display function
void displayClassInfoYourName(){
    printf("CIS 27 - Data Structures\n");
    printf("Lanely College\n");
    printf("YourName\n");

    printf("Information -- \n");
    printf(" Assignment:                        HW #2 Exercise #1\n");
    printf(" Implemented by:                    YourName\n");
    printf(" Submitted Date:                    2020/09/22\n");
    printf(" Current Number of LEB available:   ?\n");
    printf(" Allowed Number of LEB Used:        ?\n");
    printf(" Remaining Number of LEB:           ?\n");
}

// display and calculate odd numbers
void displayOddDigitForArrayYourName() {
    int nint, i;
    printf("How many int's? ");
    scanf("%d", &nint);
    int *arr = (int *) malloc(sizeof(int) * nint);
    for (i=0; i<nint; i++) {
        printf("Enter value #%d ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Calling displayOddDigitForArrayYourName with array of size %d -\n", nint);
    Pair *ptr = 0;
    int  *odddigits = 0;
    int size = 0;
    int nodd = 0;

    for(i=0; i<nint; i++) {
        int temp = arr[i] < 0? -1 * arr[i] : arr[i];
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit % 2 == 1) {
                nodd++;
                if(odddigits == 0)
                    odddigits = (int *) malloc(sizeof(int) * nodd);
                else
                    odddigits = (int *) realloc(odddigits, sizeof(int) * nodd);
                odddigits[nodd-1] = digit;

                if (ptr == 0) {
                    ptr = (Pair *) malloc (sizeof(Pair) * size+1);
                    ptr[size].num = digit;
                    ptr[size].freq = 1;
                    size++;
                } else {
                    int j=0;

                    for (j=0; j<size; j++) {
                        if (ptr[j].num == digit) {
                            ptr[j].freq++;
                            break;
                        }
                    }
                    
                    if (j == size) {
                        ptr = (Pair *) realloc(ptr, sizeof(Pair) * size+1);
                        ptr[size].num = digit;
                        ptr[size].freq = 1;
                        size++;
                    }
                }
            }
            temp /= 10;
        } 
    }

    Pair largest;
    printf(" There is/are %d odd digis of\n", nodd);
    for ( i = 0; i < nodd; i++)
    {   
        printf("   %d\n", odddigits[i]);
    }

    for (i=0; i<size; i++) {
        if (i == 0) {
            largest.num = ptr[i].num;
            largest.freq = ptr[i].freq;
        }else if (ptr[i].num > largest.num)
        {
            largest.num = ptr[i].num;
            largest.freq = ptr[i].freq;
        }
    }
    
    for ( i = 0; i < size-1; i++)
	{
        int j;
        for ( j = 0; j < size-i-1; j++)
        {
            if (ptr[j].num > ptr[j+1].num) {
                Pair temp;
                temp.num = ptr[j].num;
                temp.freq = ptr[j].freq;

                ptr[j].num = ptr[j+1].num;
                ptr[j].freq = ptr[j+1].freq;

                ptr[j+1].num = temp.num;
                ptr[j+1].freq = temp.freq;

            }
   		}
    
	}


    printf(" The largest odd digit is %d, which is seen %d time(s).\n", largest.num, largest.freq);
    printf(" There is/are %d other unique odd digit(s) as follows,\n", size-1);

    for ( i = 0; i < size; i++)
    {
        if (ptr[i].num == largest.num)
        {
            continue;
        }
        
        printf("    Digit %d seen %d time(s)\n", ptr[i].num, ptr[i].freq);
    }
    
    free(ptr);
    free(odddigits);
}

// function to display menu
int menu() {
    printf("**********************************************\n");
    printf("*               MENU - HW #2                 *\n");
    printf("* (1) Calling displayOddDigitForArrayName()  *\n");
    printf("* (2) Quit                                   *\n");
    printf("**********************************************\n");
    printf("Enter an integer for option * ENTER: ");
    int op;
    scanf("%d", &op);
    return op;
}

// main function
void main() {
    displayClassInfoYourName();
    int op;
    do {
        op = menu();
        if (op == 1) {
            displayOddDigitForArrayYourName();
        } else if (op != 2) {
            printf("Wrong Option!\n");
        }
    } while (op != 2);
    
}

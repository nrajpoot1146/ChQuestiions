#include <stdio.h>
#define MAX_LEN 20

/**
* read data from user
* store in array
*/
int array_read(int data[], int max_len){
    int data_len;
    printf("Enter number of elements (should be less than %d) : ", max_len);
    scanf("%d", &data_len);

    printf("Enter elements : \n");
    // read array elements
    for (int i = 0; i < data_len; i++){
        scanf("%d", &data[i]);
    }
    return data_len;
}

/**
* print data of array
*/
void print(int *data, int data_len){
    printf("[");
    for (int i = 0; i < data_len; i++){
        printf("%d", data[i]);
        if (i != data_len-1){
            printf(", ");
        }
    }
    printf("]");
}

/**
* perform cocktail sort
* print each step
*
*/
void cocktailshaker_sort(int *data, const int data_len){
    int isSorted = 1;
    int s = 0;
    int e = data_len - 1;
    int i, k;
    while (isSorted){

        isSorted = 0;

        // step 1 :
        // forward traversing
        for(i = s; i < e; i++){
            if(data[i] > data[i+1]){
                int temp  = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                isSorted = 1;
            }
        }

        // check is already sorted
        if (!isSorted)
            break;

        isSorted = 0;

        // print array data
        print(data, data_len);
        printf("\n");

        e--;

        // step 2 :
        // backward traversing
        for (k = e - 1; k >= s; k--){
            if(data[k] > data[k+1]){
                int temp = data[k];
                data[k] = data[k+1];
                data[k+1] = temp;
                isSorted = 1;
            }
        }

        // check is already sorted
        if (!isSorted)
            break;

        // print array data
        print(data, data_len);
        printf("\n");
        s++;
    }
}

int main(){
    // declare an array of max size
    int data[MAX_LEN] = {0};
    int data_len = array_read(data, MAX_LEN);
    // print array data
    print(data, data_len);
    printf("\n");
    cocktailshaker_sort(data, data_len);
}

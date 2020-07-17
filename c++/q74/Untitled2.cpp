/**
* 2. main.cpp
*/

#include <stdio.h>
#include <stdlib.h>

/**
* read n imtegers and store in array
* @param array, empty array of interger
* @param size, size of array
*/
void readInts(int array[], int size){
	printf("Enter %d integer numbers: \n", size);
	int i=0;
	while(i < size){
		scanf("%d", &array[i]);
		i++;
	}
}

/**
* calculate sum of integers stored in array array
* @param array, integer array
* @param size of integer array
* @return sum of integers stored in array
*/
int arrayTotal(int array[], int size){
	int i=0;
	int sum=0;
	for (int i=0; i<size; i++){
		sum+=array[i];
	}
	return sum;
}

/**
* calculate average of integer stored in arrray
* @param array, integer array
* @param size of integer array
* @return average of integers stored in array
*/
int arrayAverage(int array[], int size){
	int total = arrayTotal(array, size);
	return total / size;
}

int main(){
	int n;
	printf("Enter value of n: ");
	scanf("%d", &n); 								// read number of integer or array size
	int *array = (int*) malloc(sizeof(int) * n);	// create an array of given size
	readInts(array, n);								// call readInt function and read integer value for array
	int sum = arrayTotal(array, n);					// call arrayTotal function to calculate sum of integers
	printf("sum = %d\n", sum);						// print sum of integers
	int avg = arrayAverage(array, n);				// call arrayAverage function to calculate average of integers
	printf("average = %d", avg);					// print average of integers
}

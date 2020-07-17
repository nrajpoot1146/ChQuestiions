/**
* 3. main.cpp
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter number of terms: ");
	scanf("%d", &n); // read number of integers
	
	int *array = (int*) malloc(sizeof(int) * n); // create an array of given size n
	int i=0;
	
	// generate Fibonacci series
	// store element of series in an array
	for (i = 0; i<n; i++){
		if(i<2){
			array[i] = i;
			continue;
		}
		array[i] = array[i-1] + array[i-2];
	}
	
	// print elements of arrry
	for(i=0; i<n; i++){
		printf("%d",array[i]);
		if(i != n-1){
			printf(", ");
		}
	}
}

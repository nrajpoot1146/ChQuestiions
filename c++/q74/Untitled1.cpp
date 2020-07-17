/**
* 1. main.cpp
*/

#include <stdio.h>

int main(){
	int n;
	int sum = 0;
	printf("Enter value of n: ");
	scanf("%d", &n); // read value of n
	printf("Enter %d integer numbers: \n", n);
	
	// read n integer numbers
	// calculate sum of n integers
	while(n-- > 0){
		int num;
		scanf("%d", &num);
		sum += num;
	}
	
	// print sum of n integers
	printf("Sum = %d", sum);
}

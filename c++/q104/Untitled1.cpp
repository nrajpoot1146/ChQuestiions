#include <stdio.h>

// structure to declare fraction
struct FractionType{
	int numerator;		// numerator of fraction number
	int denominator;	// Denominator of fraction number
};

int main(){
	struct FractionType ar[20]; // array of fraction number of length 20
	
	// initialize first fraction number with 1/3
	ar[0].numerator = 1; 		 
	ar[0].denominator = 3;
	
	// print first fraction number
	printf("First fraction number is: %d/%d",	ar[0].numerator, ar[0].denominator);
}

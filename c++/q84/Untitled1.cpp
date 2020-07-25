#include <cmath>
#include <cstdio>
using namespace std;

/**
* function to calculate factorial of given number
* use simple method
*/
double factSimple(double n){
	double fact = 1.0;
	while (n>0){
		fact *= n;
		n -= 1;
	}
	return fact;
}

/**
* function to calculate factorial of given number
* use Stirking's Formula
*/
double factStirlingFormula(double n){
	double fact = 0.0;
	fact = exp(-n) * pow(n, n) * sqrt(2 * M_PI * n);
	return fact;
}

// main function
int main(){
	double fact1 = factSimple(15);			// factorial using simple method
	double fact2 = factStirlingFormula(15); // factorial using Stirling`s Formula
	
	// print factorial calculated using both method
	printf("Factorial of number 15 using simple methode:     %lf\n", fact1);
	printf("Facotrial of number 15 using Stirling`s Formula: %lf\n", fact2);
}

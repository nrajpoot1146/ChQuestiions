#include<iostream>
#include<math.h>

using namespace std;

int main(){
	long double sum = 0.0; // declare varible to store sum of given series
	
	// loop to compute sum of given series
	for(int i=1; i<625; i++){
		sum = sum + 1.0 / (sqrt(i) + sqrt(i+1));	
	}
	
	cout<<"sum = "<<sum; // print sum
}

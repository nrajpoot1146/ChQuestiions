#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;

// required function
// return value of pi
// used formula pi = 2.0 asin(1.0)
long double pi(){
	double vOfPi = 0.0;
	vOfPi = 2.0 * asin(1.0);
	return vOfPi;
}

// driver function
// call pi() method
// get value of pi and store it in vOfPi
// print value of pi with macimum accurate decimal point supported by system
int main(){ 	
	long double vOfPi = pi();
	cout.precision( LDBL_MAX_EXP );
	cout<<vOfPi<<endl;
}

#include <iostream>

using namespace std;

int main() {
	int nResistor; // variable to store number of resistance
	
	cout<<"Enter number of resistor: ";
	cin>>nResistor; // read number of resistance

	float resistors[nResistor];
	cout<<"Enter resistance value of "<<nResistor<<" different resistors:\n";
	
	// read value of n different resistor
	for (int i=0; i<nResistor; i++) {
		cin>>resistors[i];
	}
	
	double num = 1;
	// calculate numerator
	for (int i=0; i<nResistor; i++) {
		num *= resistors[i];
	}
	
	double denom = 0;
	// calculate denominator
	for (int i=0; i<nResistor; i++) {
		denom += num/resistors[i];
	}
	
	denom = num == 0? 1 : denom;
	
	double equResistance = 0.0;
	// calculate equivalent resistance
	equResistance = num / denom;
	cout<<"Equivalent parallel resistance is: "<<equResistance;
}

/*
 * test.cpp
 *
 *  Created on: 10-Jul-2020
 *      Author:
 */
#include <iostream>
#include "Rational.h"
using namespace std;

int main(){

	// create two rational number
	Rational r1(1, 3), r2(7, 8);

	Rational radd = r1.add(r2); // add two rational number
	Rational rsub = r1.sub(r2); // subtract two rational number
	Rational rmul = r1.mult(r2);// multiply two rational number
	Rational rdiv = r1.divi(r2);// divide two rational number

	cout<<r1.toRationalString()<<" + "<<r2.toRationalString()<<" = "<<radd.toRationalString()<<" = "<<radd.toDouble()<<endl; // print addition
	cout<<r1.toRationalString()<<" - "<<r2.toRationalString()<<" = "<<rsub.toRationalString()<<" = "<<rsub.toDouble()<<endl; // print subtraction
	cout<<r1.toRationalString()<<" * "<<r2.toRationalString()<<" = "<<rmul.toRationalString()<<" = "<<rmul.toDouble()<<endl; // print multiplication
	cout<<r1.toRationalString()<<" % "<<r2.toRationalString()<<" = "<<rdiv.toRationalString()<<" = "<<rdiv.toDouble()<<endl; // print division
}



/*
 * Rational.cpp
 *
 *  Created on: 07-Aug-2020
 *      Author: naren
 */


#include <iostream>
#include "RationalNumber.h"//rational class definition

//constructor
RationalNumber::RationalNumber(int num, int den) {
   numerator = num;
   denominator = den;
}


//add two rational number by create a new object “result” of class Rational.
//denominator and numerator is calculated for the new object "result"
RationalNumber RationalNumber::addRationalNumber(const RationalNumber&a) {//pass by reference
   int newden {0}, newnum{0};
   newden=a.denominator*denominator;
   newnum=a.numerator*denominator+numerator*a.denominator;
   RationalNumber result(newnum, newden);//create an rational object called result
   result.reduce();//reduce result to simple form.
   return result;//return a RationalNumber object

}

RationalNumber RationalNumber::operator+(const RationalNumber &r){
	return this->addRationalNumber(r);
}

//subtract two rational number
//same prograRationalNumberhod with adding two rational number, but different caculation
RationalNumber RationalNumber::subRationalNumber(const RationalNumber &b) {
   int newden{ 0 }, newnum{ 0 };
   newden = b.denominator * denominator;
   newnum = b.numerator * denominator - numerator * b.denominator;
   RationalNumber result(newnum, newden);
   result.reduce();
   return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber &r){
	return this->subRationalNumber(r);
}

//multiply two rational number
//same programing method with adding two rational number, but different caculation
RationalNumber RationalNumber::mulRationalNumber(const RationalNumber& d) {
   int newden{ 0 }, newnum{ 0 };
   newden = d.denominator * denominator;
   newnum = d.numerator * numerator;
   RationalNumber result(newnum, newden);
   result.reduce();
   return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber &r){
	return this->mulRationalNumber(r);
}

//multiply two rational number
//same programing method with adding two rational number, but different caculation
RationalNumber RationalNumber::divRationalNumber(const RationalNumber& f) {
   int newden{ 0 }, newnum{ 0 };
   newden = denominator * f.numerator;
   newnum = numerator * f.denominator;
   RationalNumber result(newnum, newden);
   result.reduce();
   return result;

}

RationalNumber RationalNumber::operator/(const RationalNumber &r){
	return this->divRationalNumber(r);
}

bool RationalNumber::operator <(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d < 0;
}

bool RationalNumber::operator >(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d > 0;
}

bool RationalNumber::operator <=(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d <= 0;
}

bool RationalNumber::operator >=(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d >= 0;
}

bool RationalNumber::operator ==(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d == 0;
}

bool RationalNumber::operator !=(const RationalNumber &r){
	RationalNumber temp = *this - r;
	double d = ((double)temp.numerator) / temp.denominator;
	return d != 0;
}

//rational number reduction
void RationalNumber::reduce() {
   int n = numerator;
   int d = denominator;
   int largest = (n > d) ? n : d;//find the bigger number among numerator and denominator
   int greatest{ 0 }; //greatest common divisor
   for (int i = largest; i >= 2; i--) { //find greatest common divisor
       if (n% i == 0 && d % i == 0) {
           greatest = i;
           break;
       }
   }

   if (greatest == 0){
	   return;
   }
   numerator /= greatest;
   denominator /= greatest;

}

//output rational number
void RationalNumber::printRationalNumber() {
   std::cout << numerator << "/" << denominator ;
}

//output rational number in double form
void RationalNumber::printDoubleNumber() {
   double a;
   a = ((double)numerator) / denominator;
   std::cout << " = " << a;
}

RationalNumber::~RationalNumber() {

}


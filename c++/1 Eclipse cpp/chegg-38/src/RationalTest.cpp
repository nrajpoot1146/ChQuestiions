/*
 * RationalTest.cpp
 *
 *  Created on: 07-Aug-2020
 *      Author: naren
 */

#include <iostream>

#include "RationalNumber.h" // rational class definition
using namespace std;

int main() {
   //rational constructor called
   RationalNumber n1(4, 5);
   RationalNumber n2(5, 7);
   RationalNumber n3(4, 5);
   RationalNumber a;//a has default value

   //add two rational number and print the calculation
   a = n1 + n2;//add n1 and n2,then set value to a
   n1.printRationalNumber();//print n1
   cout << " + ";
   n2.printRationalNumber();//print n2
   cout << " = ";
   a.printRationalNumber();//print a
   a.printDoubleNumber();//print a in double form
   cout << endl;

   //subtract two rational number and print the calculation
   a = n1 - n2;//subtract n1 and n2,then set value to a
   n1.printRationalNumber();//print n1
   cout << " - ";
   n2.printRationalNumber();//print n2
   cout << " = ";
   a.printRationalNumber();//print a
   a.printDoubleNumber();//print a in double form
   cout << endl;

   //multiply two rational number and print the calculation
   a = n1 * n2;//multiply n1 and n2, then set value to a
   n1.printRationalNumber();//print n1
   cout << " * ";
   n2.printRationalNumber();//print n2
   cout << " = ";
   a.printRationalNumber();//print a
   a.printDoubleNumber();//print a in double form
   cout << endl;

   //divide two rational number and print the calculation
   a = n1 / n2;//divide n1 and n2, then set value to a
   n1.printRationalNumber();//print n1
   cout << " / ";
   n2.printRationalNumber();//print n2
   cout << " = ";
   a.printRationalNumber();//print a
   a.printDoubleNumber();//print a in double form
   cout << endl;

   // test < operator
   n1.printRationalNumber();
   cout<<" < ";
   n2.printRationalNumber();
   cout<<" = "<< (n1 < n2);
   cout<<endl;

   // test > operator
   n1.printRationalNumber();
   cout<<" > ";
   n3.printRationalNumber();
   cout<<" = "<< (n1 > n2);
   cout<<endl;

   // test <= operator
   n1.printRationalNumber();
   cout<<" <= ";
   n2.printRationalNumber();
   cout<<" = "<< (n1 <= n2);
   cout<<endl;

   // test >= operator
   n1.printRationalNumber();
   cout<<" >= ";
   n2.printRationalNumber();
   cout<<" = "<< (n1 >= n2);
   cout<<endl;

   // test == operator
   n1.printRationalNumber();
   cout<<" == ";
   n2.printRationalNumber();
   cout<<" = "<< (n1 == n2);
   cout<<endl;

   // test != operator
   n1.printRationalNumber();
   cout<<" != ";
   n2.printRationalNumber();
   cout<<" = "<< (n1 != n2);
   cout<<endl;

}



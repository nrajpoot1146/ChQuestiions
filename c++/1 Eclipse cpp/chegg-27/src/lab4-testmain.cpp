/*
 * lab4-testmain.cpp
 *
 *  Created on: 21-Jul-2020
 *      Author:
 */

#include <iostream>
#include "lab4-LabArray.h"
using namespace std;

void print(IntArr &a){
	for(int i=0; i<a.getSize(); i++){
		cout<<a.getVal(i)<<" ";
	}
}

int main(){
	IntArr a(20), b(20);

	// fill a with 10 itegers
	for(int i=1; i<11; i++){
		a.insertVal(i * 4);
	}

	// print a info
	cout<<"Array A capacity: "<<a.getCapacity()<<endl;
	cout<<"Array A size: "<<a.getSize()<<endl;
	cout<<"Array A: ";
	print(a);
	cout<<endl<<endl;

	b=a; // initialize IntArr b to IntArr a

	// remove to element
	a.insertVal(23);
	a.insertVal(42);
	// print a info
	cout<<"Array A capacity: "<<a.getCapacity()<<endl;
	cout<<"Array A size: "<<a.getSize()<<endl;
	cout<<"Array A: ";
	print(a);
	cout<<endl<<endl;

	// print array b
	cout<<"Array B capacity: "<<b.getCapacity()<<endl;
	cout<<"Array B size: "<<b.getSize()<<endl;
	cout<<"Array B: ";
	print(b);
	cout<<endl<<endl;

	b=a;

	cout<<"Array B capacity: "<<b.getCapacity()<<endl;
	cout<<"Array B size: "<<b.getSize()<<endl;
	cout<<"Array B: ";
	print(b);
	cout<<endl<<endl;

}



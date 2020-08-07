/*
 * main.cpp
 *
 *  Created on: 20-Jul-2020
 *      Author:
 */


#include <iostream>
#include "IntArr.cpp"
using namespace std;

int main(){
	cout<<endl;

	IntArr a(5);
	for (int i=0; i<5; i++){ a.push_back((i+1)*5); }
	cout<<"Array size: "<<a.getSize()<<endl;

	cout<<"Array A: ";
	for (int i=0; i<a.getSize(); i++){ cout <<a[i]<<" "; }
	cout<<endl<<endl;


	a.push_back(30);
	a.push_back(35);
	cout<<"Array size: "<<a.getSize()<<endl;

	IntArr b = a;
	cout<<"Array A: ";
	for (int i=0; i<a.getSize(); i++){ cout <<a[i]<<" "; };
	cout<<"\nPArray B: ";
	for (int i=0; i<b.getSize(); i++){ cout <<b[i]<<" "; }
	cout<<endl<<endl;

	a.pop_back();
	cout<<"Array size: "<<a.getSize()<<endl;
	b=a;
	cout<<"Array A: ";
	for (int i=0; i<a.getSize(); i++){ cout <<a[i]<<" "; };
	cout<<"\nArray B: ";
	for (int i=0; i<b.getSize(); i++){ cout <<b[i]<<" "; }
	cout<<endl<<endl;

	cout<<endl;
	return 0;
}


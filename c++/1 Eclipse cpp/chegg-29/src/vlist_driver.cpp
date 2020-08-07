/*
 * vlist_driver.cpp
 *
 *  Created on: 24-Jul-2020
 *      Author:
 */

#include <iostream>
#include "vlist.h"
using namespace std;

int main(){
	vlist vl;

	cout<<"Insert Hello: "<<endl;
	vl.insert("Hello");
	cout<<"Insert Bye: "<<endl;
	vl.insert("Bye");
	cout<<"Insert Good: "<<endl;
	vl.insert("Good");
	cout<<"vlist is: \n";
	vl.print();
	cout<<endl;

	cout<<"Remove Good: "<<endl;
	vl.remove("Good");
	vl.insert("Good");
	vl.print();
	cout<<endl;

	cout<<"Search Good: \n";
	vl.search("Good");
	cout<<endl;

	vlist v2 = vl;
	cout<<"vlist v2: \n";
	v2.print();
}



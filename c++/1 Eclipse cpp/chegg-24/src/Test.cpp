/*
 * Test.cpp
 *
 *  Created on: 16-Jul-2020
 *      Author:
 */

#include <iostream>
#include "Reminder.h"

using namespace std;
int main(){

	// create reminder objects
	Reminder r1(7, 16, "Test is due");
	Reminder r2(7, 4, "Independence Day Holiday");
	Reminder r3(1, 1, "Start of the New Year");
	Reminder r4(7, 30, "My Birthday");

	// print reminder info
	cout<<r1.toString()<<endl;
	cout<<r2.toString()<<endl;
	cout<<r3.toString()<<endl;
	cout<<r4.toString()<<endl;

	cout<<endl;

	// test is before function
	if (r2.isBefore(r1)){
		cout<<"first is before test passed\n";
	}else {
		cout<<"first is before test failed\n";
	}

	if (r4.isBefore(r3)){
		cout<<"second is before test failed\n";
	}else {
		cout<<"second is before test passed\n";
	}
}




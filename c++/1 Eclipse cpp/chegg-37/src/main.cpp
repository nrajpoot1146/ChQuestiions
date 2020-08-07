/*
 * main.cpp
 *
 *  Created on: 05-Aug-2020
 *      Author:
 */

// template function to print an given array
#include "Name.h"
#include "Set.cpp"

template <class T>
void printArray(const T *array, const int &size) {
	for (int i=0; i<size; i++){
		cout<<"\t"<<array[i]<<"\n";
	}
	cout<<endl;
}

ostream &operator<<(ostream &os, const Name &c){
	cout<<c.fname<<" "<<c.lname;
	return os;
}

int main(){

	// Items object for integer, point 5.a
	Set<int> intSet;
	cout<<"---------------------------------\n";
	cout<<"---Example 1: sets of integers---\n";
	cout<<"---------------------------------\n";
	intSet.add(10);
	intSet.add(5);
	intSet.add(15);
	intSet.add(25);
	intSet.add(15);
	cout<<"---------------------------------\n";

	int *intArray = intSet.getPointerOfArray();
	cout<<"The first set has "<<intSet.getNumberOfItems()<<" Set\n";
	cout<<"They are: \n";
	printArray(intArray, intSet.getNumberOfItems());
	delete[] intArray;

	// Set object for double, point 5.b
	Set<double> doubleSet;
	cout<<"--------------------------------\n";
	cout<<"---Example 2: sets of doubles---\n";
	cout<<"--------------------------------\n";
	doubleSet.add(1.5);
	doubleSet.add(5.6);
	doubleSet.add(12.8);
	doubleSet.add(1.5);
	doubleSet.add(12.8);
	cout<<"---------------------------------\n";

	double *doubleArray = doubleSet.getPointerOfArray();
	cout<<"The second set has "<<doubleSet.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(doubleArray, doubleSet.getNumberOfItems());
	delete[] doubleArray;

	// Items object for string, point 5.c
	Set<string> stringSet;
	cout<<"--------------------------------\n";
	cout<<"---Example 3: sets of strings---\n";
	cout<<"--------------------------------\n";
	stringSet.add("John Smith");
	stringSet.add("Jane doe");
	stringSet.add("John Smith");
	stringSet.add("Jack black");
	cout<<"--------------------------------\n";

	string *stringArray = stringSet.getPointerOfArray();
	cout<<"The third set has "<<stringSet.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(stringArray, stringSet.getNumberOfItems());
	delete[] stringArray;

	// Items object for Customer, point 5.d
	Set<Name> nameSet;
	cout<<"----------------------------------------\n";
	cout<<"---Example 4: sets of Name names---\n";
	cout<<"----------------------------------------\n";
	Name c1("John", "Rick");
	nameSet.add(c1);
	Name c2("Ram", "Singh");
	nameSet.add(c2);
	Name c3("Rohan", "Kumar");
	nameSet.add(c3);
	cout<<"---------------------------------------\n";

	Name *nameArray = nameSet.getPointerOfArray();
	cout<<"The fourth set has "<<nameSet.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(nameArray, nameSet.getNumberOfItems());
	delete[] nameArray;
}



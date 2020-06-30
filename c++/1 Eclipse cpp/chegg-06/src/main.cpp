/*
 * main.cpp
 *
 *  Created on: 22-Jun-2020
 *      Author: naren
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
	LinkedList li;
	li.add(11);
	li.add(22);
	li.add(44);
	li.add(33);
	li.add(55);

	// element of current linked list
	cout<<"element of current linked list: \n";
	li.print();

	cout<<endl;
	// add 44 to current linked list
	li.add(44);
	cout<<"after adding 44: \n";
	li.print();

	cout<<endl;
	// add 11 to current linked list
	li.add(11);
	cout<<"after adding 11 to current linked list: \n";
	li.print();

	cout<<endl;
	// add 56 to current linked list
	li.add(56);
	cout<<"after adding 56 to current linked list: \n";
	li.print();
}



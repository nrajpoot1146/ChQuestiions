/*
 * Driver.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main(){
	LinkedList<int> linkedList;
	linkedList.add(45);
	linkedList.add(34);
	linkedList.add(20);
	linkedList.add(50);

	cout<<"after append four elements: "<<endl;
	linkedList.print();

	cout<<endl;
	cout<<"after prepend 100: "<<endl;
	linkedList.addFirst(100);

	linkedList.print();

	cout<<endl;
	cout<<"third element: "<<endl;
	cout<<linkedList.getNthNode(3)->getInfo();
}


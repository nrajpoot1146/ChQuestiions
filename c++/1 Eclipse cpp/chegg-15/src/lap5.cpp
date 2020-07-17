/*
 * lap5.cpp
 *
 *  Created on: 08-Jul-2020
 *      Author:
 */

#include "Employee.cpp"
#include "DoublyLinkedQueue.cpp"
#include <iostream>
using namespace std;

int main(){
	// declare integer queue
	Queue<int> queueInteger;

	cout<<"Enter integer value to enqueue (Enter -1 to stop): \n";
	// read integer value to enqueue
	do{
		int intVal;
		cin>>intVal;
		if (intVal == -1){
			break;
		}

		queueInteger.enqueue(intVal);
	}while(true);

	cout<<"Elements in queue: ";
	queueInteger.print(); // print elements of integer queue

	int k;
	cout<<"Enter number of value you want to dequeue from queue : ";
	// enter number of element to dequeue
	cin>>k;
	// dequeue k elements
	while(k-->0 && !queueInteger.empty()){
		queueInteger.dequeue();
	}

	cout<<"After dequeue "<<k<<" elements: ";
	queueInteger.print(); // print element after dequeue k elements
	cout<<endl<<endl;


	// declare string queue
	Queue<string> queueString;

	cout<<"Enter string value to enqueue (Enter exit to stop): \n";
	// read string value and enqueue in string queue
	do{
		string stringVal;
		cin>>stringVal;
		if (stringVal == "exit"){
			break;
		}

		queueString.enqueue(stringVal);
	}while(true);

	cout<<"Elements in queue: ";
	queueString.print(); // print element of string queue

	cout<<"Enter number of value you want to dequeue from queue : ";
	cin>>k;
	// dequeue k elements
	while(k-->0 && !queueString.empty()){
		queueString.dequeue();
	}
	cout<<"After dequeue "<<k<<" elements: ";
	queueString.print(); // print element after dequeue k elements
	cout<<endl<<endl;


	// declare employee queue
	Queue<Employee> queueEmployee;

	cout<<"Enter employee details to enqueue (Enter employee id 0 to stop): \n";
	// read and enqueue employee into queue
	do{
		string employeeName;
		int employeeId;
		string employeeDept;
		cout<<"Enter Employee name: ";
		cin>>employeeName;
		cout<<"Enter employee Id: ";
		cin>>employeeId;
		if (employeeId == 0){
			break;
		}
		cout<<"Enter employee department: ";
		cin>>employeeDept;

		Employee employeeVal(employeeName, employeeId, employeeDept);

		queueEmployee.enqueue(employeeVal);
	}while(true);

	cout<<"Elements in queue: ";
	queueEmployee.print(); // print employee queue

	cout<<"Enter number of value you want to dequeue from queue : ";
	cin>>k;
	// dequeue k employee from queue
	while(k-->0 && !queueString.empty()){
		queueEmployee.dequeue();
	}

	cout<<"After dequeue "<<k<<" elements: ";
	queueEmployee.print(); // print employee details after dequeue of k employee
}

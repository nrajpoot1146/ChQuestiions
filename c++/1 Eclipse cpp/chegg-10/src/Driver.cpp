/*
 * Driver.cpp
 *
 *  Created on: 29-Jun-2020
 *      Author: naren
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.cpp"

using namespace std;

/**
 * print element of stack
 */
void print(Stack<int, 100> s){
	while (!s.isEmpty()){
		cout<<s.pop()<<" ";
	}
}

int main(){
	Stack<int, 150> stack1, stack2;

	ifstream fin;
	fin.open("input.txt"); // file for input

	cout<<"max value in stack are: "<<endl;
	while(fin){

		string line = "";
		getline(fin,line); // read line from file
		if (line == ""){
			break;
		}

		string op = line.substr(0,line.find(" ")); // fetch operation from file
		if (op == "Push"){
			line = line.substr(line.find(" ")+1);
			stringstream ss(line);
			int ele;
			ss>>ele;
			stack1.push(ele);

			if(stack2.isEmpty() || stack2.top() <= ele){
				stack2.push(ele);
			}else{
				stack2.push(stack2.top());
			}

		}else{
			stack1.pop();
			stack2.pop();
		}
		cout<<stack2.top()<<",";
	}
	fin.close();

}


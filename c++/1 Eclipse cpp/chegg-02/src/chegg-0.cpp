/*
 * main.cpp
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#include<iostream>
#include "Composer.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
	ifstream fin;
	fin.open("composers.txt");
	LinkedList<Composer> linklist;


	while(fin){
		string line;
		getline(fin, line);
		if(line==""){
			break;
		}
		string name = line.substr(0,line.find(","));
		string dt = line.substr(line.find(",")+2);
		stringstream ss(dt);
		int date;
		ss>>date;
		Composer composer(name, date);
		linklist.insert(composer);
	}

	while(true){
		cout<<"\nEnter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: ";
	    string op;
		getline(cin, op);
		if(op == "s"){
			string name;
			cout<<"\nEnter name of composer: ";
			getline(cin, name);
			if(linklist.find(Composer(name)) == true){
				cout<<"Composer with name "<<name<<" Successfully found."<<endl;
			}else{
				cout<<"No composer found with name "<<name<<endl;
			}
		}else if(op == "r"){
			string name;
			cout<<"\nEnter name of composer: ";
			getline(cin, name);
			if(linklist.remove(Composer(name)) == true){
				cout<<"Composer with name "<<name<<" Successfully removed."<<endl;
			}else{
				cout<<"No composer found with name "<<name<<endl;
			}
		}else if(op == "d"){
			cout<<endl;
			linklist.printList();
		}else if(op == "e"){
			break;
		}
	}

	cout<<endl<<"Press any key to continue...";
	getchar();
}



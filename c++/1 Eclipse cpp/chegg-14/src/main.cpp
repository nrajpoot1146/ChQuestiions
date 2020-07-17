/*
 * main.cpp
 *
 *  Created on: 06-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include "Inventory.h"
#include "Items.h"
using namespace std;

/**
 * print system command menu
 */
void menu(){
	cout<<endl;
	cout<< "SYSTEM COMMAND MENU"<<endl;
	cout<< "walk - Walk down the path\n";
	cout<< "show - Show all items\n";
	cout<< "drop - Drop an item\n";
	cout<< "exit - Exit program\n";
	cout<< "System command: ";
}

int main(){
	Items items;
	Inventory inventory;

	// loop to proocess system command
	while (true){
		menu();
		string command;
		cin>>command;

		// condition to walk down
		if (command == "walk"){
			string item = items.getItem();
			cout<<"While walking down a path, you see a "<<item<<endl;
			cout<<"Do you want to grab it? (y/n): ";
			char cmd;
			cin>>cmd;
			if (cmd == 'y'){
				if (inventory.grab(item))
					cout<<"You picked up "<<item<<endl;
			}
		}else if(command == "show"){ // condition to show items
			inventory.print();
		}else if(command == "drop"){ // condition to drop items
			cout<<"Item number: ";
			int num;
			cin>>num;
			string droppeditem;
			droppeditem = inventory.drop(num);
			if (droppeditem == ""){
				cout<<"Invalid item number. try again!\n";
			}else{
				cout<<"you dropped a "<<droppeditem<<endl;
			}
		}else if(command == "exit"){ // condition to exit program
			cout<<"Thank you for using my app!\n";
			break;
		}else{
			cout<< "Invalid command. Try again!\n";
		}
	}
}



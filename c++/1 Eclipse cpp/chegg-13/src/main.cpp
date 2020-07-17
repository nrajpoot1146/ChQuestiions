/*
 * main.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include "Car.h"
#include <vector>
using namespace std;

class CarList {
public:
	CarList();
	/**
	 * add new car to car list
	 * read car make
	 * read year
	 * create new object
	 */
	void add();

	/**
	 * remove a car from car list
	 * read caNo
	 * remove car
	 */
	void remove();

	/**
	 * accelerate car from car list
	 * read car no
	 */
	void accelerateCar();

	/**
	 * brake a car from car list
	 * read carNo
	 */
	void breakCar();

	/**
	 * print car inventory
	 */
	void print();

	/**
	 * check car list is empty or not
	 * if empty return true otherwise return false
	 */
	bool isEmpty();

	/**
	 * print car inventory with car no
	 */
	void printWithCarNo();
	virtual ~CarList();

private:
	vector<Car> carVec;
};

/**
 * print menu
 */
void menu(){
	cout<<endl;
	cout<<"MAIN MENU ** Enter:"<<endl;
	cout<<"\t> 1 | Print complete car collection"<<endl;
	cout<<"\t> 2 | Add a car to the collection"<<endl;
	cout<<"\t> 3 | Remove a car from the collection"<<endl;
	cout<<"\t> 4 | Accelerate a car"<<endl;
	cout<<"\t> 5 | Brake a car"<<endl;
	cout<<"\t> 6 | Quit"<<endl;
	cout<<"\t> Choice: ";
}

int main(){
	CarList carList;
	while (true){
		menu();
		int op;
		cin>>op;
		if (op == 6){
			cout<<"Program ending.";
			break;
		}

		switch(op){
		case 1:
			carList.print();
			break;
		case 2:
			carList.add();
			break;
		case 3:
			carList.remove();
			break;
		case 4:
			carList.accelerateCar();
			break;
		case 5:
			carList.breakCar();
			break;
		}

	}

}

CarList::CarList() {}

void CarList::add(){
	cout<<"Adding a car to the collection..."<<endl;
	string make;
	int year;
	cout<<"\t> Enter make: ";
	cin>>make;
	cout<<"\t> Enter year: ";
	cin>>year;
	Car car(make, year);
	this->carVec.push_back(car);
	cout<<"\t> Done. Car added."<<endl;
}

void CarList::remove(){
	if (this->isEmpty()){
		cout<<"\t> Error: There are no cars in the collection.\n";
		return;
	}
	cout<<"Removing a car from the collection...\n";
	int i = 0;
	this->printWithCarNo();
	cout<<"\t> Enter the number of the car to remove:\n";
	int carNo;
	cin>>carNo;
	for (vector<Car>::iterator it = this->carVec.begin(); it != this->carVec.end(); i++, ++it){
		if (i+1 == carNo){
			this->carVec.erase(it);
			cout<<"\t> Done. Car removed.\n";
			return;
		}
	}

}

void CarList::accelerateCar(){
	if (this->isEmpty()){
		cout<<"\t> Error: There are no cars in the collection.\n";
		return;
	}
	cout<<"Accelerating a car...\n";
	this->printWithCarNo();
	cout<<"\t> Enter the number of the car to accelerate:\n";
	cout<<"\t> Choice: ";
	unsigned int carNo;
	cin>>carNo;
	for (unsigned int i = 0; i<this->carVec.size(); i++){
		if (i+1 == carNo){
			this->carVec[i].accelerate();
			cout<<"\t> Done. Car accelerated. New speed "<<this->carVec[i].getSpeed()<<" mph.\n";
			return;
		}
	}

}

void CarList::breakCar(){
	if (this->isEmpty()){
		cout<<"\t> Error: There are no cars in the collection.\n";
		return;
	}
	cout<<"Braking a car...\n";
	this->printWithCarNo();
	cout<<"\t> Enter the number of the car to brake:\n";
	cout<<"\t> Choice: ";
	unsigned int carNo;
	cin>>carNo;
	for (unsigned int i = 0; i<this->carVec.size(); i++){
		if (i+1 == carNo){
			if(this->carVec[i].brek())
				cout<<"\t> Done. Car braked. New speed "<<this->carVec[i].getSpeed()<<" mph.\n";
			else{
				cout<<"\t> Error: can't brake a car that's standing still.\n";
			}
		}
	}
}

void CarList::print(){
	if (this->isEmpty()){
		cout<<"\t> Error: There are no cars in the collection.\n";
		return;
	}
	cout<<"Car inventory:"<<endl;
	for (unsigned int i = 0; i<this->carVec.size(); i++){
		cout<<"\t> ";
		carVec[i].print();
		cout<<endl;
	}
}

void CarList::printWithCarNo(){
	for (unsigned int i = 0; i<this->carVec.size(); i++){
		cout<<"\t> "<< i+1 <<" |\t > ";
		carVec[i].print();
		cout<<endl;
	}
}

bool CarList::isEmpty(){
	return this->carVec.size() == 0;
}


CarList::~CarList() {}





/*
 * Truck.cpp
 *
 *  Created on: 12-Jul-2020
 *      Author: naren
 */

#include "Truck.h"

Truck::Truck(char licPlateNo[], int year, double capacity, char *currAddress) : MotorVehicle(licPlateNo, year) {
	this->maxWeight = capacity;
	this->currentWeight = 0;
	MotorVehicle::moveTo(currAddress);
}

bool Truck::addCargo(double cargo){
	if (this->currentWeight != this->maxWeight){
		this->currentWeight  = this->currentWeight + cargo <= this->maxWeight ? this->currentWeight + cargo : this->maxWeight;
		return true;
	}
	return false;
}

bool Truck::unloadCargo(){
	if (this->currentWeight != 0){
		this->currentWeight = 0;
		return true;
	}
	return false;
}

ostream& Truck::write(ostream &os){
	MotorVehicle::write(os);
	cout<<" | "<<this->currentWeight<<"/"<<this->maxWeight;
	return os;
}

istream& Truck::read(istream &is){
	MotorVehicle::read(is);
	cout<<"Capacity: ";
	is>>this->maxWeight;
	cout<<"Cargo: ";
	cin>>this->currentWeight;
	return is;
}

ostream& operator<<(ostream &os, Truck &t){
	t.write(os);
	return os;
}

istream& operator>>(istream &is, Truck &t){
	t.read(is);
	return is;
}

Truck::~Truck() {}


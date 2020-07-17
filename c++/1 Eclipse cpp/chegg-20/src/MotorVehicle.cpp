/*
 * MotorVehicle.cpp
 *
 *  Created on: 12-Jul-2020
 *      Author: naren
 */

#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(char licPlateNo[], int year) {
	strcpy(this->license, licPlateNo);
	this->year = year;
	this->address = new string("factory")->c_str();
}

void MotorVehicle::moveTo(const char *address){
	if(strcmp(this->address, address) != 0){
		cout<<"| "<<this->license <<" | "<<this->address<<"--->---"<<address<<" |"<<endl;
		this->address = (char *) address;
	}
}

ostream& MotorVehicle::write(ostream &os){
	os<<"| "<<this->year<<" | "<<this->license<<" | "<<this->address;
	return os;
}

istream& MotorVehicle::read(istream &is){
	cout<<"Built year: ";
	is>>this->year;
	cout<<"License plate: ";
	is>>this->license;
	cout<<"Current Location: ";
	static char line[LIC];
	is>>line;
	this->address = line;
	return is;
}

ostream& operator<<(ostream &os, MotorVehicle &t){
	t.write(os);
	return os;
}
istream& operator>>(istream &is, MotorVehicle &t){
	t.read(is);
	return is;
}

MotorVehicle::~MotorVehicle() {}


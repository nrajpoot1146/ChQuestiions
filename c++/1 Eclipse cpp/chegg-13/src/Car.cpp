/*
 * Car.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: naren
 */

#include "Car.h"

Car::Car(std::string make, int year) {
	this->make = make;
	this->year = year;
	this->speed = 0;
}

void Car::accelerate(){
	this->speed += DEFAULT_ACCELERATION;
}

bool Car::brek(){
	if (this->speed > 0){
		this->speed -= DEFAULT_ACCELERATION;
		return true;
	}
	return false;
}

std::string Car::getMake(){
	return this->make;
}

int Car::getSpeed(){
	return this->speed;
}

int Car::getYear(){
	return this->year;
}

void Car::print(){
	std::cout<<this->make<<" | "<<this->year<<" | "<<this->speed<<" mph";
}

Car::~Car() {

}


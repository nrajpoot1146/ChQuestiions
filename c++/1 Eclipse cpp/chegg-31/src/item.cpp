/*
 * item.cpp
 *
 *  Created on: 25-Jul-2020
 *      Author:
 */

#include "item.h"

Item::Item() {
	this->cost = 0;
	this->name = "";
}

Item::Item(std::string name, double cost){
	this->cost = cost; // set cost of item
	this->name = name; // set name of item
}

double Item::getCost(){
	return this->cost; // return cost of item
}

void Item::setCost(double cost){
	this->cost = cost; // set cost of item
}

string Item::getName(){
	return this->name; // return name of item
}

void Item::setName(string name){
	this->name = name; // set name of item
}

Item::~Item() {}


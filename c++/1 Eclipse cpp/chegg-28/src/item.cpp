/*
 * item.cpp
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#include "item.h"

Item::Item() {
	this->name = "";
	this->cost = 0.0;
}

Item::Item(std::string name, double cost){
	this->name = name;
	this->cost = cost;
}

void Item::setCost(double cost){
	this->cost = cost;
}

void Item::setName(std::string name){
	this->name = name;
}

std::string Item::getName(){
	return this->name;
}

double Item::getCost(){
	return this->cost;
}

Item::~Item() {}


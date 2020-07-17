/*
 * Car.cpp
 *
 *  Created on: 11-Jul-2020
 *      Author: naren
 */

#include "Car.h"
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * sets Model year of car
 * @param model year of car to be set
 */
void Car::SetModelYear(int year){
	this->modelYear = year;
}

/**
 * sets current year of car
 * @param current year of car to be set
 */
void Car::SetCurrentYear(int year){
	this->currentYear = year;
}

/**
 * sets purchase price of car
 * @param purchase price of car to be set
 */
void Car::SetPurchasePrice(double price){
	this->purchasePrice = price;
}

/**
 * Print the model year, purchase price, current year, current value
 * For example
 * Model Year		:	2004
 * Purchase Price	:	14488.98
 * Current Year 	:	2020
 * Current Value	:	1075.23
 *
 * formatting above is done using the following values for setw
 * column width 15 | column width 2 | column width 11
 * Price must be printd with 2 decimal values.
 */
void Car::PrintInfo(){
	cout<<setw(15)<<"Model Year"<<setw(2)<<":"<<setw(11)<<this->modelYear<<endl;
	cout<<setw(15)<<"Purchase Price"<<setw(2)<<":"<<setw(11)<<fixed<<setprecision(2)<<this->purchasePrice<<endl;
	cout<<setw(15)<<"Current Year"<<setw(2)<<":"<<setw(11)<<this->currentYear<<endl;
	cout<<setw(15)<<"Current Value"<<setw(2)<<":"<<setw(11)<<this->currentValue<<endl;
}

/**
 * calculate current price of car
 * use formula
 * currentPrice = purchasePrice * pow((1 - depreciation), carAge)
 */
void Car::CalcCurrentValue(){
	int carAge = this->currentYear - this->modelYear;
	this->currentValue = this->purchasePrice * pow((1 -this->depreciation), carAge);
}


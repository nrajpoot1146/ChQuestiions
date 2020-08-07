/*
 * cashRegister.cpp
 *
 *  Created on: 25-Jul-2020
 *      Author:
 */

#include "cashRegister.h"

CashRegister::CashRegister() {
	this->count = 0;	// set count to 0
	this->name = "";	// set register name to empty string
	this->total = 0;	// set total amount to 0
	this->taxRate = 0; 	// set default tax rate to 0
}

CashRegister::CashRegister(std::string name, double rate){
	this->count = 0; // set count to 0
	this->name = name; // set name
	this->total = 0; // set total amount to 0
	this->taxRate = rate; // set rate to given rate
}

bool CashRegister::purchase(Item &item){
	if (this->count > 100){
		return false; // return false if item list is full
	}

	this->item[count] = &item; // add an item in list
	this->count+=1; // increase counter variable by one
	return true; // return true if successfully added
}

void CashRegister::printTotal(){
	// calculate to amount to be pay
	for (int i=0; i<this->count; i++){
		this->total += this->item[i]->getCost();
	}
	double taxAmt = this->total * this->taxRate / 100;
	this->total += taxAmt;
	cout<<"Total amount(including tax): "<<this->total<<endl;
}

CashRegister::~CashRegister() {}


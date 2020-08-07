/*
 * cashRegister.cpp
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#include "cashRegister.h"

CashRegister::CashRegister() {
	this->name = "";
	this->taxRate = 0.0;
	this->total = 0.0;
	this->count = 0;
}

CashRegister::CashRegister(std::string name, double rate){
	this->name = name;
	this->count = 0;
	this->taxRate = rate;
	this->total = 0.0;
}

bool CashRegister::purchase(Item &item){
	if (this->count > 100){
		return false;
	}

	this->item[count] = &item;
	this->count++;
	return true;
}

void CashRegister::printTotal(){
	for (int i=0; i<this->count; i++){
		this->total += this->item[i]->getCost();
	}
	double taxAmt = this->total * this->taxRate / 100;
	this->total += taxAmt;
	std::cout<<"Total amount(including tax): "<<this->total<<std::endl;
}

CashRegister::~CashRegister() {}


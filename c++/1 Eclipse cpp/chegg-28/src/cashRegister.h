/*
 * cashRegister.h
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_
#include "item.h"
#include <iostream>

class CashRegister {
	Item *item[100];
	std::string name;
	int count;
	double total;
	double taxRate;
public:
	/**
	 * default constructor
	 * set name of cashRegister to empty string
	 * set count to 0
	 * set total to 0
	 * set taxRate to 0
	 */
	CashRegister();

	/**
	 * overloaded constructor
	 * set name to given name
	 * set count to 0
	 * set total to 0
	 * set taxRate to given taxRate
	 */
	CashRegister(std::string name, double rate);

	/**
	 * add an item to item array
	 * return true if item successfully added otherwise return false
	 */
	bool purchase(Item &item);

	/**
	 * print total amount including taxRate
	 */
	void printTotal();
	virtual ~CashRegister();
};

#endif /* CASHREGISTER_H_ */

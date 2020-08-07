/*
 * cashRegister.h
 *
 *  Created on: 25-Jul-2020
 *      Author:
 */

#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_
#include "item.h"
#include <iostream>
using namespace std;

class CashRegister {
	Item *item[100];
	string name;
	int count;
	double total;
	double taxRate;
public:
	/**
	 * default constructor
	 * set all attribute to 0
	 */
	CashRegister();

	/**
	 * overloaded constructor
	 * @param name of cashregister to be set
	 * @param rate
	 */
	CashRegister(string name, double rate);

	/**
	 * purchase an item and add it to array list
	 * @param item to be purchase
	 */
	bool purchase(Item &item);

	/**
	 * print total amount including taxRate
	 */
	void printTotal();
	virtual ~CashRegister();
};

#endif /* CASHREGISTER_H_ */

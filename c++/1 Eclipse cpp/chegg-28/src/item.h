/*
 * item.h
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>

class Item {
	std::string name;
	double cost;
public:

	/**
	 * default constructor
	 * set name with empty string
	 * set cost to 0
	 */
	Item();

	/**
	 * overloaded constructor
	 * set name with given name
	 * set cost with given cost
	 */
	Item(std::string name, double cost);

	/**
	 * get name of item
	 */
	std::string getName();

	/**
	 * set name of item
	 */
	void setName(std::string name);

	/**
	 * get cost of item
	 */
	double getCost();

	/**
	 * set cost of item
	 */
	void setCost(double cost);
	virtual ~Item();
};

#endif /* ITEM_H_ */

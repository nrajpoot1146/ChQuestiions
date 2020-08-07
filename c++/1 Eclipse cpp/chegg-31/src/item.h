/*
 * item.h
 *
 *  Created on: 25-Jul-2020
 *      Author:
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
using namespace std;

class Item {
	string name;
	double cost;
public:

	/**
	 * default constructor
	 */
	Item();

	/**
	 * overloaded constructor
	 * @param name of item
	 * @param cost of item
	 */
	Item(std::string name, double cost);

	/**
	 * get name of item
	 * @return name of item
	 */
	string getName();

	/**
	 * set name of item
	 * @param name of item to be set
	 */
	void setName(string name);

	/**
	 * get cost of item
	 * @return cost of item
	 */
	double getCost();

	/**
	 * set cost of item
	 * @param cost of item
	 */
	void setCost(double cost);
	virtual ~Item();
};

#endif /* ITEM_H_ */

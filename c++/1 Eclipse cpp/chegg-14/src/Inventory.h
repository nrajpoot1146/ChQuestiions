/*
 * Inventory.h
 *
 *  Created on: 06-Jul-2020
 *      Author: naren
 */

#ifndef SRC_INVENTORY_H_
#define SRC_INVENTORY_H_
#include <vector>
#include <iostream>
#include <fstream>

class Inventory {
public:
	Inventory();

	/**
	 * read inventory item from inventory.txt file
	 * store in inItems vector
	 */
	void readFromFile();

	/**
	 * write data to inventory.txt file
	 */
	void writeToFile();

	/**
	 * add item to inventory
	 * @param item to add
	 * @return true if item successfully grabbed otherwise return false
	 */
	bool grab(std::string item);

	/**
	 * drop an item from inventory
	 * @param item number
	 * @return dropped item;
	 */
	std::string drop(unsigned int n);

	/**
	 * check inventory is full or not
	 * @return true if inventory is full otherwise return false
	 */
	bool isFull();

	/**
	 * check inventory is empty or not
	 * @return true is inventory is empty otherwise return false
	 */
	bool isEmpty();

	/**
	 * print all inventory items
	 */
	void print();
	virtual ~Inventory();

private:
	std::vector<std::string> inItems;
	std::string filename;
	const unsigned int maxItems;
};

#endif /* SRC_INVENTORY_H_ */

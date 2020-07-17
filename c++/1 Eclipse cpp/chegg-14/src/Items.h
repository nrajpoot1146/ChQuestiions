/*
 * Items.h
 *
 *  Created on: 06-Jul-2020
 *      Author: naren
 */

#ifndef SRC_ITEMS_H_
#define SRC_ITEMS_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

class Items {
public:
	Items();

	/**
	 * read items from all_items.txt
	 * store all items into vector
	 */
	void readFromFile();

	/**
	 * get item from inventory
	 */
	std::string getItem();
	virtual ~Items();

private:
	std::vector<std::string> items;
	std::string filename;
};

#endif /* SRC_ITEMS_H_ */

/*
 * Items.cpp
 *
 *  Created on: 06-Jul-2020
 *      Author: naren
 */

#include "Items.h"

Items::Items() {
	this->filename = "all_items.txt";
	this->readFromFile();
}

void Items::readFromFile(){
	std::ifstream fin;
	fin.open(this->filename.c_str());
	while (fin){
		std::string line;
		getline(fin, line);

		if (line == ""){
			break;
		}

		this->items.push_back(line);
	}

	fin.close();
}

std::string Items::getItem(){
	int num = rand() % this->items.size();
	return this->items[num];
}

Items::~Items() {}


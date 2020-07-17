/*
 * Inventory.cpp
 *
 *  Created on: 06-Jul-2020
 *      Author: naren
 */

#include "Inventory.h"

Inventory::Inventory(): maxItems(4) {
	this->filename = "inventory.txt";
}

void Inventory::readFromFile(){
	this->inItems.clear();
	std::ifstream fin;

	fin.open(this->filename.c_str());

	while (fin){
		std::string line;
		getline(fin, line);

		if (line == ""){
			break;
		}

		this->inItems.push_back(line);
	}

	fin.close();
}

void Inventory::writeToFile(){
	std::ofstream fout;
	fout.open(this->filename.c_str());

	for (unsigned int i = 0; i < this->inItems.size(); i++){
		fout<<this->inItems[i]<<std::endl;
	}

	fout.flush();
	fout.close();
	this->inItems.clear();
}

bool Inventory::grab(std::string item){
	this->inItems.clear();
	this->readFromFile();

	if (this->isFull()){
		std::cout<<"You can not carry any more items. Drop one item first.\n";
		return false;
	}

	this->inItems.push_back(item);
	this->writeToFile();
	return true;
}

std::string Inventory::drop(unsigned int num){
	this->inItems.clear();
	this->readFromFile();

	if (num > this->inItems.size()){
		return "";
	}

	std::string erasedItem = this->inItems[num-1];
	this->inItems.erase(this->inItems.begin() + num-1);
	this->writeToFile();
	return erasedItem;
}

bool Inventory::isFull(){
	this->inItems.clear();
	this->readFromFile();
	return this->inItems.size() == this->maxItems;
}

bool Inventory::isEmpty(){
	this->inItems.clear();
	this->readFromFile();
	return this->inItems.size() == 0;
}

void Inventory::print(){
	this->inItems.clear();
	this->readFromFile();
	for (unsigned int i = 0; i<this->inItems.size(); i++){
		std::cout<<i + 1<<". a "<<this->inItems[i]<<std::endl;
	}
}


Inventory::~Inventory() {}


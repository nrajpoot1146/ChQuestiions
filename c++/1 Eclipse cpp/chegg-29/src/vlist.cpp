/*
 * vlist.cpp
 *
 *  Created on: 24-Jul-2020
 *      Author:
 */

#include "vlist.h"

vlist::vlist() {
	cout<<"Default Constructor Invoked\n";
}

vlist::vlist(vlist &ov){
	cout<<"Copy Constructor Invoked\n";
	for (unsigned int i=0; i < ov.DB.size(); i++){
		this->DB.push_back(ov.DB[i]);
	}
}

bool vlist::is_Empty(){
	return this->DB.size() == 0;
}

vector<string>::iterator vlist::search(const string &str){
	if (this->is_Empty()){
		return this->DB.end();
	}

	for (vector<string>::iterator s = this->DB.begin(); s !=this->DB.end(); s++){
		if (*s == str){
			cout<<"Item Found! key = "<<str<<endl;
			return s;
		}
	}
	cout<<"Item Not Found! key = "<<str<<endl;
	return this->DB.end();
}

void vlist::insert(const string &key){
	if (this->getSize() == 0){
		this->DB.push_back(key);
		return;
	}

	for (vector<string>::iterator s = this->DB.begin(); s !=this->DB.end(); s++){
		if (*s > key){
			this->DB.insert(s, key);
			return;
		}
	}

	this->DB.push_back(key);
}

void vlist::remove(const string &key){
	if (this->getSize() == 0){
		return;
	}

	for (vector<string>::iterator s = this->DB.begin(); s !=this->DB.end(); s++){
		if (*s == key){
			this->DB.erase(s);
			return;
		}
	}

	cout<<key<<" it was not in vector\n";
}

void vlist::print(){
	for (vector<string>::iterator s = this->DB.begin(); s !=this->DB.end(); s++){
		cout<<*s<<"\n";
	}
}


unsigned int vlist::getSize(){
	return this->DB.size();
}

vlist::~vlist() {
	cout<<"Destructor Invoked\n";
}


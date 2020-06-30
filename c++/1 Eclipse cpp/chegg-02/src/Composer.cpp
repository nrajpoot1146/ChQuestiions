/*
 * Composer.cpp
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#include "Composer.h"

Composer::Composer(){

}
Composer::Composer(string name) {
	this->name = name;
	this->date = 0;
}

Composer::Composer(string name, int date) {
	this->name = name;
	this->date = date;
}

Composer::~Composer() {
	// TODO Auto-generated destructor stub
}

Composer::Composer(const Composer &c){
	this->name = c.name;
	this->date = c.date;
}

string Composer::getName(){
	return this->name;
}

int Composer::getDate(){
	return this->date;
}

void Composer::print(){
	cout<<this->name<<" - "<<this->date<<endl;
}

bool Composer::equals(const Composer &c) const{
	if(this->name == c.name){
		return true;
	}
	return false;
}

void Composer::setName(string name){
	this->name = name;
}

void Composer::setDate(int date){
	this->date = date;
}

bool Composer::operator <(const Composer &c) const{
	if(this->date < c.date){
		return true;
	}
	return false;
}

bool Composer::operator >(const Composer &c) const{
	if(this->date > c.date){
		return true;
	}
	return false;
}

bool Composer::operator <=(const Composer &c) const{
	if(this->date < c.date || this->date == c.date){
		return true;
	}
	return false;
}

bool Composer::operator >=(const Composer &c) const{
	if(this->date > c.date || this->date == c.date){
		return true;
	}
	return false;
}

bool operator==(const Composer &c1, const Composer &c2){
	if( c1.date == c2.date){
		return true;
	}
	return false;
}

bool operator!=(const Composer &c1, const Composer &c2){
	if( c1.date != c2.date){
		return true;
	}
	return false;
}

ostream &operator<<(ostream &os, const Composer &c){
	cout<<c.name<<" - "<<c.date;
	return os;
}


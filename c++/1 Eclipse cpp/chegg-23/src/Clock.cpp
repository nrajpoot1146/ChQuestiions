/*
 * Clock.cpp
 *
 *  Created on: 16-Jul-2020
 *      Author: naren
 */

#include "Clock.h"

Clock::Clock() : hh(0), mm(0){
	time_t currTime = time(0);
	struct tm *tim = localtime(&currTime);
	this->hh = tim->tm_hour;
	this->mm = tim->tm_min;
}

Clock::Clock(int h, int m) : hh(h), mm(m) {

}

int Clock::getMinutes(){
	int minutes = this->hh * 60 + this->mm;
	return minutes;
}

void Clock::setTimeInMinutes(int minutes){
	this->hh = minutes / 60;
	this->mm = minutes % 60;
}

int Clock::getHH(){
	return this->hh;
}

int Clock::getMM(){
	return this->mm;
}

Clock  &Clock::operator +(Clock &c){
	static Clock newC;
	int m = this->getMinutes() + c.getMinutes();
	newC.setTimeInMinutes(m);
	return newC;
}

Clock &Clock::operator -(Clock &c){
	static Clock newC;
	int m = this->getMinutes() - c.getMinutes();
	newC.setTimeInMinutes(m);
	return newC;
}

Clock &Clock::operator *(Clock &c){
	static Clock newC;
	int m = this->getMinutes() * c.getMinutes();
	newC.setTimeInMinutes(m);
	return newC;
}

Clock &Clock::operator /(Clock &c){
	static Clock newC;
	int m = this->getMinutes() / c.getMinutes();
	newC.setTimeInMinutes(m);
	return newC;
}

Clock &Clock::operator++(int){
	int m = this->getMinutes();
	m++;
	this->setTimeInMinutes(m);
	return *this;
}

Clock &Clock::operator--(int){
	int m = this->getMinutes();
	m--;
	this->setTimeInMinutes(m);
	return *this;
}

ostream& operator<<(ostream &os, const Clock &c){
	int ap = c.hh / 12;
	int h = c.hh % 12 == 0 ? 12 : c.hh % 12;
	cout<<h<<":"<<setw(2)<<setfill('0')<<c.mm<<" ";
	ap == 0 ?cout<<"AM" : cout<<"PM";
	return os;
}

Clock::~Clock() {

}


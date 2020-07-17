/*
 * Reminder.cpp
 *
 *  Created on: 16-Jul-2020
 *      Author:
 */

#include "Reminder.h"

Reminder::Reminder(int month, int day, std:: string description) : month(month), day(day), des(description) {}

void Reminder::setDay(int day){
	this->day = day;
}

int Reminder::getDay(){
	return this->day;
}

void Reminder::setMonth(int month){
	this->month = month;
}

int Reminder::getMonth(){
	return this->month;
}

void Reminder::setDescription(std::string description){
	this->des = description;
}

std::string Reminder::getDescription(){
	return this->des;
}

std::string Reminder::toString(){
	std::stringstream ss;
	std::string res = "";

	std::string temp;
	ss<<this->month;
	ss>>temp;
	res += temp;
	res += "/";

	ss.clear();
	ss<<this->day;
	ss>>temp;
	res += temp;
	res+=": ";
	res += this->des;
	return res;
}

bool Reminder::isBefore(const Reminder &r){
	if (this->month < r.month){
		return true;
	}else if(this->day < r.day){
		return true;
	}

	return false;
}

Reminder::~Reminder() {}


/*
 * Text.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author:
 */

#include "Text.h"
#include <string.h>
#include <iostream>
using namespace std;

Text::Text() {
	strcpy(this->topic, "");
	strcpy(this->owner, "");
	this->slides = 0;
}

void Text::setTopic(const char* x){
	if (strlen(x) > 0 && ( (x[0] >= 'a' && x[0] <='z') || (x[0] >= 'A' || x[0] <= 'Z'))){
		strcpy(this->topic, x);
		return;
	}
}

void Text::setOwner(const char* x){
	if (strlen(x) > 0 && ( (x[0] >= 'a' && x[0] <='z') || (x[0] >= 'A' || x[0] <= 'Z'))){
		strcpy(this->owner, x);
		return;
	}
}

const char* Text::getTopic() const{
	return this->topic;
}

const char* Text::getOwner() const{
	return this->owner;
}

void Text::setSlides(int q){
	if (q >= 0){
		this->slides = q;
		return;
	}
}

int Text::getSlides(){
	return this->slides;
}

void Text::output(){
	cout<<this->topic<<" by "<<this->owner<<" ("<<this->slides<<" pg)";
}

Text::~Text() {}


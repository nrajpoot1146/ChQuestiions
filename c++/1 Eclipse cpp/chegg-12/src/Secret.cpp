/*
 * Secret.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include "Secret.h"

Secret::Secret() {
	this->msg = "WELCOME";
	this->flag = false;
}

void Secret::display(){
	if (flag)
		std::cout<<"Encrypted message: "<<std::endl;
	else
		std::cout<<"Decrypted message: "<<std::endl;
	std::cout<<this->msg<<std::endl;
}

Secret::~Secret() {}


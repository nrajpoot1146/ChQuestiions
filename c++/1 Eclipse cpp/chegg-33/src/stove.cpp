/*
 * stove.cpp
 *
 *  Created on: 4-Aug-2020
 *      Author:
 */

#include "stove.h"

stove::stove() {
	this->p = 0;
	this->state = normal;
	this->elements = new devicestate[4];
	for (int i=0; i<4; i++){
		this->elements[i] = off;
	}
}

stove::stove(stovestate s, devicestate s1, devicestate s2, devicestate s3, devicestate s4){
	this->state = s;
	this->p = 0;
	this->elements = new devicestate[4];
	this->elements[0] = s1;
	this->elements[1] = s2;
	this->elements[2] = s3;
	this->elements[3] = s4;

	for (int i=0; i<4; i++){
		if (this->elements[i] == devicestate::on){
			this->p++;
		}
	}
}

string stove::GetState(){
	string res = "";

	if (this->state == stovestate::normal){
		res = "normal";
	} else if (this->state == stovestate::clean){
		res = "clean";
	}

	return res;
}

void stove::SetState(stovestate s){
	if (s == stovestate::normal || s == stovestate::clean){
		this->state = s;
	}
}

int stove::GetP(){
	return this->p;
}

void stove::SetElement(int n, devicestate q){
	if (n < 3 && n>0){
		if (q == on || q == off)
			this->elements[n] = q;

		this->p=0;
		for (int i=0; i<4; i++){
			if (this->elements[i] == devicestate::on){
				this->p++;
			}
		}
	}
}

void stove::boil(int n){

	if (n > 3 || n<0){
		cout<<"Error: value for n must be in 0 to 3 (inclusive)\n";
	}
	else if (this->elements[n] == devicestate::off || this->state != stovestate::normal){
		cout<<"Error: either element is off or stove state is not normal\n";
	}
	else {
		cout<<"boiling wait for 3 second.....\n"<<flush;
		// sleep current thread for 3 second
		this_thread::sleep_for(chrono::seconds(3));
	}
}

void stove::clean(){
	if (this->state != stovestate::clean){
		cout<<"Error: stove state is not clean\n";
	} else {
		this->p = 0;
		cout<<"stove is cleaning wait for 5 seconds...\n"<<flush;
		for (int i=0; i<p; i++){
			this->elements[i] = devicestate::off;
		}
		// sleep current thread for 5 second
		this_thread::sleep_for(chrono::seconds(5));
	}
}

stove::~stove() {
	cout<<"stove shutting down...\n";
}


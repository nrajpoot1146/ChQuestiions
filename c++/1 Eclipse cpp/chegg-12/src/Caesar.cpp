/*
 * Caesar.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include "Caesar.h"

Caesar::Caesar() {}

void Caesar::encrypt(std::string key){
	if (!this->flag){
		std::string result = "";
		std::stringstream ss(key);
		int k;
		ss>>k;

		for (unsigned int i=0; i<this->msg.length(); i++){
			if(std::isupper(this->msg[i])){
				result += char(int(this->msg[i] + k - 65) % 26 + 65);
			}else{
				result += char(int(this->msg[i] + k -97) % 26 +97);
			}
		}

		this->msg = result;
		this->flag = true;
	}
}

void Caesar::decrypt(std::string key){
	if (this->flag){
		std::string result = "";
		std::stringstream ss(key);
		int k;
		ss>>k;

		for (unsigned int i=0; i<this->msg.length(); i++){
			if(std::isupper(this->msg[i])){
				int temp = int(this->msg[i] - k - 65);
				temp = temp < 0 ? temp + 26 : temp;
				result += char(temp % 26 + 65);
			}else{
				int temp = int(this->msg[i] - k - 97);
				temp = temp < 0 ? temp + 26 : temp;
				result += char(temp % 26 + 97);
			}
		}

		this->msg = result;
		this->flag = false;
		}
}

Caesar::~Caesar() {}


/*
 * Autokey.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#include "Autokey.h"

Autokey::Autokey() {
	// TODO Auto-generated constructor stub

}

void Autokey::encrypt(std::string key){
	if (!this->flag){
		int i = 0;
		while (key.length() < this->msg.length()){
			key += this->msg[i];
			i++;
		}

		std::string res = "";

		for (unsigned int i = 0; i < this->msg.length(); i++) {
			int first  = 0;
			int second = 0;

			if (std::isupper(this->msg[i])){
				first = int(this->msg[i] - 65);
			}else{
				first = int(this->msg[i] - 97);
			}

			if(std::isupper(key[i])){
				second = int(key[i] - 65);
			}else{
				second = int(key[i] - 97);
			}

			int encChar = 0;
			if(std::isupper(this->msg[i])){
				encChar = (first+second) % 26 + 65;
			}else{
				encChar = (first+second) % 26 + 97;
			}

			res += char(encChar);
		}

		this->msg = res;
		this->flag = true;
	}
}

void Autokey::decrypt(std::string key){
	if (this->flag){

		std::string res = "";

		for (unsigned int i = 0; i < this->msg.length(); i++) {
			int first  = 0;
			int second = 0;

			if (std::isupper(this->msg[i])){
				first = int(this->msg[i] - 65);
			}else{
				first = int(this->msg[i] - 97);
			}

			if(std::isupper(key[i])){
				second = int(key[i] - 65);
			}else{
				second = int(key[i] - 97);
			}

			int encChar = 0;
			if(std::isupper(this->msg[i])){
				encChar = first - second;
				encChar = encChar < 0 ? encChar + 26 : encChar;
				encChar = encChar % 26 + 65;
			}else{
				encChar = first - second;
				encChar = encChar < 0 ? encChar + 26 : encChar;
				encChar = encChar % 26 + 97;
			}

			res += char(encChar);
			key += char(encChar);
		}

		this->msg = res;
		this->flag = false;
	}
}

Autokey::~Autokey() {}


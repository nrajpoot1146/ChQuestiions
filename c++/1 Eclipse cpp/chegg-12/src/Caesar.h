/*
 * Caesar.h
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#ifndef SRC_CAESAR_H_
#define SRC_CAESAR_H_
#include "Secret.h"
#include <sstream>

class Caesar : public Secret{
public:
	Caesar();

	/**
	 * encrypt message using Caesar encryption algorithm
	 */
	void encrypt(std::string key);

	/**
	 * decrypt message using Caesar decryption algorithm
	 */
	void decrypt(std::string key);
	virtual ~Caesar();
};

#endif /* SRC_CAESAR_H_ */

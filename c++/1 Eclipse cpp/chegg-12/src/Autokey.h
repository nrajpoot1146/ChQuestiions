/*
 * Autokey.h
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#ifndef SRC_AUTOKEY_H_
#define SRC_AUTOKEY_H_

#include "Secret.h"
#include <iostream>

class Autokey : public Secret{
public:
	Autokey();

	/**
	 * encrypt message using Autokey encryption algorithm
	 */
	void encrypt(std::string key);

	/**
	 * decrypt message using Autokey decryption algorithm
	 */
	void decrypt(std::string key);
	virtual ~Autokey();
};

#endif /* SRC_AUTOKEY_H_ */

/*
 * Secret.h
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#ifndef SRC_SECRET_H_
#define SRC_SECRET_H_
#include <iostream>
#include <string>

class Secret {
public:
	Secret();
	/**
	 * function to encrypt stored message
	 * @param key encryption key
	 */
	virtual void encrypt(std::string key) = 0;

	/**
	 * function to decrypt stored message
	 * @param key decryption key
	 */
	virtual void decrypt(std::string key) = 0;

	/**
	 * display current message is decrypted or encypted
	 * display message
	 */
	void display();
	virtual ~Secret();

protected:
	std::string msg;
	bool flag;
};

#endif /* SRC_SECRET_H_ */

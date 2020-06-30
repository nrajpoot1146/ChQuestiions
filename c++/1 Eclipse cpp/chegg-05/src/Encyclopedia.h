/*
 * Encyclopedia.h
 *
 *  Created on: 22-Jun-2020
 *      Author:
 */

#ifndef SRC_ENCYCLOPEDIA_H_
#define SRC_ENCYCLOPEDIA_H_
#include "Book.h"
#include <iostream>

/**
 * Derived from book class
 * contains two more private attribute
 * edition 		=> edition of Encyclopedia
 * numVolumes 	=> volumes of encyclopedia
 */
class Encyclopedia: public Book{
private:
	string edition;
	int numVolumes;
public:
	/**
	 * default constructor
	 *
	 */
	Encyclopedia();

	/**
	 * setter method to set edition of encyclopedia
	 * @param string edition of encyclopedia
	 *
	 */
	void SetEdition(string);

	/**
	 * setter method to set number of volumes of encyclopedia
	 * @param int numbers of volume of encyclopedia
	 */
	void SetNumVolumes(int);

	/**
	 * method to print information of encyclopedia
	 */
	void PrintInfo();
	virtual ~Encyclopedia();
};

#endif /* SRC_ENCYCLOPEDIA_H_ */

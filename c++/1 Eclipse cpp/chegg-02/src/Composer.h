/*
 * Composer.h
 *
 *  Created on: 18-Jun-2020
 *      Author: naren
 */

#ifndef SRC_COMPOSER_H_
#define SRC_COMPOSER_H_
#include <string>
#include <iostream>
using namespace std;

class Composer {
private:
	string name;
	int date;
public:
	/**
	 * default constructor
	 */
	Composer();

	/**
	 * constructor with one parameter
	 * @param string name of composer
	 */
	Composer(string);

	/**
	 * constructor with two parameter
	 * @param string name of composer
	 * @param int date of death of composer
	 */
	Composer(string, int);

	/**
	 * copy constructor
	 * @param constructor to be copy
	 */
	Composer(const Composer &c);

	/**
	 * function to fetch name of compoer
	 * @return name of composer
	 */
	string getName();

	/**
	 * function to fetch date of composer
	 * @return date of composer
	 */
	int getDate();

	/**
	 * function to set name of composer
	 * @param string name of composer
	 */
	void setName(string);

	/**
	 * function to set date of death of composer
	 * @param int date of death of composer
	 */
	void setDate(int);

	/**
	 * default destructor
	 */
	virtual ~Composer();

	/**
	 * function to print details of composer
	 */
	void print();

	/**
	 * function to check whether to composer have same name or not
	 * @param c other composer
	 * @return true if both have same name otherwise return false
	 */
	bool equals(const Composer &c) const;

	/**
	 * less than operator overloading to check current composer date is less than or not from other composer
	 * @param c other composer
	 * @return true if date of death of this composer is less then from other composer
	 */
	bool operator<(const Composer &c) const;

	/**
	 * geater than operator overloading to check current composer date is greater than or not from other composer
	 * @param c other composer
	 * @return true if date of death of this composer is greater then from other composer
	 */
	bool operator>(const Composer &c) const;

	/**
	 * lesser than or equal operator overloading to check current composer date is lesser than or equal  or not from other composer
	 * @param c other composer
	 * @return true if date of death of this composer is lesser than or equal from other composer
	 */
	bool operator<=(const Composer &c) const;

	/**
	 * greater than or equal operator overloading to check current composer date is greater than or equal  or not from other composer
	 * @param c other composer
	 * @return true if date of death of this composer is greater than or equal from other composer
	 */
	bool operator>=(const Composer &c) const;

	/**
	 * << operator overloading to print details of currnt composer
	 */
	friend ostream &operator<<(ostream &os,const Composer &c);
	friend bool operator==(const Composer &c1, const Composer &c2);
	friend bool operator!=(const Composer &c1, const Composer &c2);
};
//#include "Composer.cpp"
#endif /* SRC_COMPOSER_H_ */

/*
 * Rational.h
 *
 *  Created on: 07-Aug-2020
 *      Author: naren
 */

#ifndef SRC_RATIONALNUMBER_H_
#define SRC_RATIONALNUMBER_H_

#include <iostream>
#include <sstream>

class RationalNumber {
public:

	/**
	 * default constructor
	 */
	RationalNumber(int numerator = 0, int denominator = 1);

	/**
	 * add two rational number
	 * @return addition of two rational number
	 */
	RationalNumber addRationalNumber(const RationalNumber &r);

	/**
	 * overloaded + operator
	 * @return sum of two rational numbers
	 */
	RationalNumber operator+(const RationalNumber &r);

	/**
	 * subtract two rational number
	 * @return subtraction of two rational number
	 */
	RationalNumber subRationalNumber(const RationalNumber &r);

	/**
	 * overloaded - operator
	 * return subtraction of two rational number
	 */
	RationalNumber operator-(const RationalNumber &r);

	/**
	 * multiply two rational number
	 * @return multiplication of two rational number
	 */
	RationalNumber mulRationalNumber(const RationalNumber &r);

	/**
	 * overloaded * operator
	 * return multiplication of two rational number
	 */
	RationalNumber operator*(const RationalNumber &r);

	/**
	 * divide two rational number
	 * @return division of two rational number
	 */
	RationalNumber divRationalNumber(const RationalNumber &r);

	/**
	 * overloaded / operator
	 * return division of two rational numbers
	 */
	RationalNumber operator/(const RationalNumber &r);

	/**
	 * overloaded < operator
	 * return true if this rational number is less, otherwise return false
	 */
	bool operator<(const RationalNumber &r);

	/**
	 * overloaded > operator
	 * return true if this rational number is greater, otherwise return false
	 */
	bool operator>(const RationalNumber &r);

	/**
	 * overloaded <= operator
	 * return true if this rational number is less or equal, otherwise return false
	 */
	bool operator<=(const RationalNumber &r);

	/**
	 * overloaded >= operator
	 * return true if this rational number is greater or equal, otherwise return false
	 */
	bool operator>=(const RationalNumber &r);

	/**
	 * overloaded == operator
	 * return true if this rational number is equal, otherwise return false
	 */
	bool operator==(const RationalNumber &r);

	/**
	 * overloaded != operator
	 * return true if this rational number is not equal, otherwise return false
	 */
	bool operator!=(const RationalNumber &r);

	/**
	 * print rational number (p/q)
	 */
	void printRationalNumber();

	/**
	 * print rational number in double form
	 */
	void printDoubleNumber();

	virtual ~RationalNumber();

private:
	int numerator;
	int denominator;

	/**
	 * helper function
	 * reduce rational number
	 */
	void reduce();
};

#endif /* SRC_RATIONALNUMBER_H_ */


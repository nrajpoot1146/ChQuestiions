/*
 * Rational.h
 *
 *  Created on: 10-Jul-2020
 *      Author: naren
 */

#ifndef SRC_RATIONAL_H_
#define SRC_RATIONAL_H_

#include <iostream>
#include <sstream>

class Rational {
	int numer;
	int denom;

	/**
	 * reduce rational number
	 */
	void reduce();

	/**
	 * find gcd (greatest common factor) of two number
	 */
	int gcd(int a, int b);
public:

	/**
	 * constructor
	 * takes two parameters
	 * set numerator
	 * set denominator
	 * if denominator is 0 set it to 1
	 */
	Rational(int numerator, int denominator);

	/**
	 * add two rational number
	 * @return addition of two rational number
	 */
	Rational &add(const Rational &r);

	/**
	 * subtract two rational number
	 * @return substraction of two rational number
	 */
	Rational &sub(const Rational &r);

	/**
	 * multiply two rational number
	 * @return multiplication of two rational number
	 */
	Rational &mult(const Rational &r);

	/**
	 * divide two rational number
	 * @return division of two rational number
	 */
	Rational &divi(const Rational &r);

	/**
	 * generate string to rational number
	 * @return rational string (p/q)
	 */
	std::string toRationalString();

	/**
	 * get floating point number from rational number
	 * @return floating point number
	 */
	double toDouble();

	virtual ~Rational();
};

#endif /* SRC_RATIONAL_H_ */

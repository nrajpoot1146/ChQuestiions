/*
 * Clock.h
 *
 *  Created on: 16-Jul-2020
 *      Author: naren
 */

#ifndef CLOCK_H_
#define CLOCK_H_
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

class Clock {
private:
	int hh, mm;

	/**
	 * set time by passing minutes as parameter
	 * @param minutes to be sets
	 */
	void setTimeInMinutes(int minutes);

	/**
	 * get total minutes;
	 * @return total minutes
	 */
	int getMinutes();
public:
	/**
	 * default constructor;
	 * sets hour and minutes to current time
	 */
	Clock();

	/**
	 * overloaded constructor
	 * set hour to h
	 * set minutes to m;
	 * @param h hour to be sets;
	 * @param minutes to be sets
	 */
	Clock(int h, int m);

	/**
	 * gets hours
	 */
	int getHH();

	/**
	 * gets minutes
	 */
	int getMM();

	/**
	 * + overloaded operator to calculate sum of two clocks
	 * @param c another clock
	 * @return sum of two clocks
	 */
	Clock &operator+(Clock &c);

	/**
	 * - overloaded operator to calculate subtraction of two clocks
	 * @param c another clock
	 * @return subtraction of two clocks
	 */
	Clock &operator-(Clock &c);

	/**
	 * * overloaded operator to calculate multiplication of two clocks
	 * @param c another clock
	 * @return multiplication of two clocks
	 */
	Clock &operator*(Clock &c);

	/**
	 * / overloaded operator to calculate division of two clocks
	 * @param c another clock
	 * @return division of two clocks
	 */
	Clock &operator/(Clock &c);

	/**
	 * post increment overloaded operator
	 * @return
	 */
	Clock &operator++(int);

	/**
	 * post increment overloaded operator
	 * @return
	 */
	Clock &operator--(int);

	/**
	 * insertion operator overloading
	 * @param c
	 *
	 */
	friend ostream &operator<<(ostream &os, const Clock &c);
	virtual ~Clock();
};

#endif /* CLOCK_H_ */

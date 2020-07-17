/*
 * MotorVehicle.h
 *
 *  Created on: 12-Jul-2020
 *      Author:
 */

#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_
#include <iostream>
#include <string.h>
using namespace std;
const int LIC = 32;

class MotorVehicle {
	char license[LIC];
	char *address;
	int year;
public:
	/**
	 * custom constructor
	 * @param licPlateNo license plate number
	 * @param year Built year
	 */
	MotorVehicle(char licPlateNo[], int year);
	void moveTo(const char* address);


	/**
	 * print data of current vehicle
	 * @param os output stream
	 * @return output stream
	 */
	ostream &write(ostream &os);

	/**
	 * read current vehicle data
	 * @param in input stream
	 * @return input stream
	 */
	istream &read(istream &in);

	/**
	 * overload insertion operator
	 * print data of current vehicle
	 * @param os output stream
	 * @param t instance of current vehicle
	 * @return output stream
	 */
	friend ostream& operator<<(ostream &os, MotorVehicle &m);

	/**
	 * overload extraction operator
	 * read data of current vehicle
	 * @param is input stream
	 * @return input stream
	 */
	friend istream& operator>>(istream &os, MotorVehicle &m);
	virtual ~MotorVehicle();
};

#endif /* MOTORVEHICLE_H_ */

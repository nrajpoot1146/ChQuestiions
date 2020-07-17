/*
 * Truck.h
 *
 *  Created on: 12-Jul-2020
 *      Author: naren
 */

#ifndef TRUCK_H_
#define TRUCK_H_
#include "MotorVehicle.h"
#include "string.h"

class Truck : public MotorVehicle{
	double maxWeight, currentWeight;
public:
	/**
	 * custom constructor
	 * @param licPlateNo license plate number
	 * @param year Built year
	 * @param capacity max capacity of truck
	 * @param currAddress current address of truck
	 */
	Truck(char licPlateNo[], int year, double capacity, char *currAddress);

	/**
	 * load truck
	 * @param cargo load
	 * @return true if successfully loaded otherwise return false
	 */
	bool addCargo(double cargo);

	/**
	 * unload truck
	 * set current weight to zero
	 * @return true if current weight is differ than previous weight otherwise return false
	 */
	bool unloadCargo();

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
	friend ostream& operator<<(ostream &os, Truck &t);

	/**
	 * overload extraction operator
	 * read data of current vehicle
	 * @param is input stream
	 * @return input stream
	 */
	friend istream& operator>>(istream &is, Truck &t);

	virtual ~Truck();
};

#endif /* TRUCK_H_ */

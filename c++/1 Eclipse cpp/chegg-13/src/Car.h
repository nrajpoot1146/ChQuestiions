/*
 * Car.h
 *
 *  Created on: 05-Jul-2020
 *      Author: naren
 */

#ifndef SRC_CAR_H_
#define SRC_CAR_H_
#include <iostream>
#define DEFAULT_ACCELERATION 5;

class Car {
public:

	/**
	 * create car object
	 */
	Car(std::string make, int year);

	/**
	 * accelerate current car
	 */
	void accelerate();

	/**
	 * brake current car
	 */
	bool brek();

	/**
	 * get car speed
	 * @return car speed
	 */
	int getSpeed();

	/**
	 * get car year
	 * @return car year
	 */
	int getYear();

	/**
	 * get car make
	 * @return car make
	 */
	std::string getMake();

	/**
	 * print current car details
	 */
	void print();
	virtual ~Car();

private:
	std::string make;
	int year;
	int speed;
};

#endif /* SRC_CAR_H_ */

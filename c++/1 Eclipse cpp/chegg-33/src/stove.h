/*
 * stove.h
 *
 *  Created on: 4-Aug-2020
 *      Author:
 */

#ifndef SRC_STOVE_H_
#define SRC_STOVE_H_
#include <iostream>
#include <thread>
using namespace std;

enum stovestate{
	normal = 1,
	clean = 2,
};

enum devicestate{
	on = 1,
	off = 2
};

class stove {
	stovestate state;
	int p;
	devicestate *elements;
public:

	/**
	 * default constructor
	 */
	stove();

	/**
	 * overloaded constructor
	 */
	stove(stovestate s, devicestate s1, devicestate s2, devicestate s3, devicestate s4);

	/**
	 * get stovestate of stove
	 */
	string GetState();

	/**
	 * set state of stove
	 */
	void SetState(stovestate s);

	/**
	 * get number of working devices
	 */
	int GetP();

	/**
	 * set nth device state
	 */
	void SetElement(int n, devicestate q);

	/**
	 * boil nth device
	 */
	void boil(int n);

	/**
	 * clean stove
	 */
	void clean();

	/**
	 * default destructor
	 */
	virtual ~stove();
};

#endif /* SRC_STOVE_H_ */

/*
 * Neural.h
 *
 *  Created on: 21-Jun-2020
 *      Author: naren
 */

#ifndef SRC_NEURAL_H_
#define SRC_NEURAL_H_
#include<string>
#include<iostream>
#include<iomanip>

template<class T>
class Neural {
private:
	T *x;
	T *w;
	T *y;
	int INPUT_SIZE;
	int OUTPUT_SIZE;
public:
	/**
	 * default constructor
	 */
	Neural();

	/**
	 * constructor with parameters
	 * @param array of input value
	 * @param array of weight value
	 */
	Neural(T *x,T *w);

	/**
	 * function to calculate output value
	 * output value stored in array y,  a private variable;
	 */
	void call();

	/**
	 * function to display input, weight and output value;
	 */
	void Display();

	/**
	 * function to calculate sum of output value
	 * @return sum of output value
	 */
	T Add();

	/**
	 * default destructor
	 * release all allocated memory
	 */
	virtual ~Neural();
};

#endif /* SRC_NEURAL_H_ */

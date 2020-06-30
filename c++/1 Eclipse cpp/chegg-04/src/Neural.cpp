/*
 * Neural.cpp
 *
 *  Created on: 21-Jun-2020
 *      Author: naren
 */

#include "Neural.h"

/**
 * set input array size 20
 * set output array size 15
 * assign NULL to input pointer x, weight pointer w and output pointer y
 */
template<typename T>
Neural<T>::Neural(){
	this->INPUT_SIZE = 20;
	this->OUTPUT_SIZE = 15;
	this->x = NULL;
	this->w = NULL;
	this->y = new T[this->OUTPUT_SIZE];
}

/**
 * set input array size 20
 * set output array size 15
 * assign input pointer x to param x, weight pointer w to param w and output pointer y to new array address
 */
template<typename T>
Neural<T>::Neural(T *x, T *w) {
	this->INPUT_SIZE = 20;
	this->OUTPUT_SIZE = 15;
	this->x = x;
	this->w = w;
	this->y = new T[this->OUTPUT_SIZE];
}

template<typename T>
void Neural<T>::Display(){

	// display input array values
	std::cout<<"Input : ";
	for (int i = 0; i < this->INPUT_SIZE; i++){
		std::cout<< std::setfill(' ') << std::setw(4) << this->x[i]<<" ";
	}

	// display weight array values
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"weight : ";
	for (int i=0; i < this->OUTPUT_SIZE; i++){
		std::cout<< std::setfill(' ') << std::setw(5) <<this->w[i]<<" ";
	}

	// display output array values
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"output : ";
	for (int i=0; i < this->OUTPUT_SIZE; i++){
		std::cout<< std::setfill(' ') << std::setw(5) <<this->y[i]<<" ";
	}
	std::cout<<std::endl;

}


template<typename T>
void Neural<T>::call(){
	// calculate output array values
	for (int i = 0; i < this->OUTPUT_SIZE; i++){
		int sum = 0;
		for (int j = 0; j < this->INPUT_SIZE; j++){
			sum += this->w[i] * this->x[j]; // formula y[i] = y[i] + x[j] * w[i];
		}
		this->y[i] = sum;
	}
}

template<typename T>
T Neural<T>::Add(){
	int sum = 0;

	for (int i = 0; i < this->OUTPUT_SIZE; i++){
		sum += this->y[i];
	}
	return sum;
}

template<typename T>
Neural<T>::~Neural() {
	// TODO Auto-generated destructor stub
	delete[] x;
	delete[] w;
	delete[] y;
}


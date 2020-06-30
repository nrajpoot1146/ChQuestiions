/*
 * main.cpp
 *
 *  Created on: 21-Jun-2020
 *      Author: naren
 */

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "Neural.cpp"

using namespace std;

int main(){
	int x[20];
	int w[15];

	srand(time(0));

	// assign random values to input array and weight array
	for (int i = 0;  i<20; i++){
		x[i] = rand() % 101;

		if ( i<15 ){
			w[i] = rand() % 6;
		}
	}


	Neural<int> nl(x, w);

	nl.call();

	nl.Display();

	cout<<"sum: "<< std::setfill(' ') << std::setw(50) <<nl.Add();
}



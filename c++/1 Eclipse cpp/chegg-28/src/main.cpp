/*
 * main.cpp
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#include <iostream>
#include "item.h"
#include "cashRegister.h"

using namespace std;

int main(){
	CashRegister c("cRegister", 5.0); // create object of CashRegister class

	Item i1("Tshirt", 250); // create item i1
	Item i2("pen", 10); 	// create item i2
	c.purchase(i1); 		// purchase item i1
	c.purchase(i2); 		// purchase item i2

	c.printTotal(); 		// print total amount of item
}



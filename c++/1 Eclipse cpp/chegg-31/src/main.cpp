/*
 * main.cpp
 *
 *  Created on: 23-Jul-2020
 *      Author:
 */

#include <iostream>
#include "cashRegister.h"

using namespace std;

int main(){
	CashRegister c("cRegister", 5.0); // create object of CashRegister class

	Item item1("Scale", 25); 			// create item1
	Item item2("Tie", 10); 				// create item2
	Item item3("Undergarments", 50); 	// create item3
	Item item4("Cap", 70); 				// create item4
	c.purchase(item1); 					// purchase item1
	c.purchase(item2); 					// purchase item2
	c.purchase(item3); 					// purchase item3
	c.purchase(item4); 					// purchase item4

	c.printTotal(); 		// print total amount of item
}



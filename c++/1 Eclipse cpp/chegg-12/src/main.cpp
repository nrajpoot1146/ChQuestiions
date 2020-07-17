/*
 * main.cpp
 *
 *  Created on: 01-Jul-2020
 *      Author:
 */

#include "Autokey.h"
#include "Caesar.h"
#include <iostream>
using namespace std;

int main(){

	Autokey autokey; // instance of autokey
	Caesar caesar; // instance of caesar

	cout<<"using caesar cipher: "<<endl;
	caesar.display();

	// encryption using Caesar cipher
	cout<<endl;
	caesar.encrypt("4");
	caesar.display();

	// decryption using Carsar cipher
	cout<<endl;
	caesar.decrypt("4");
	caesar.display();

	cout<<"\n\nusing autokey cipher: "<<endl;
	autokey.display();

	// encryption using auto key cipher
	cout<<endl;
	autokey.encrypt("N");
	autokey.display();

	// decryption using autokey cipher
	cout<<endl;
	autokey.decrypt("N");
	autokey.display();
}

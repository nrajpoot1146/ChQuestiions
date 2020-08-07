/*
 * main.cpp
 *
 *  Created on: 4-Aug-2020
 *      Author:
 */


#include "stove.h"

int main(){
	stove kenmore(normal, off, on, off, off);
	cout << kenmore.GetState() <<endl ;
	cout << kenmore.GetP()<<endl;

	kenmore.SetElement(3, on);
	cout << kenmore.GetP()<<endl;

	kenmore.boil(0);
	kenmore.boil(1);
	kenmore.boil(2);
	cout<<kenmore.GetP()<<endl;

	kenmore.SetElement(2, off);
	kenmore.clean();
	kenmore.SetState(clean);
	kenmore.clean();
	cout<<kenmore.GetState()<<endl;
	cout<<kenmore.GetP()<<endl;
}


/*
 * Driver.cpp
 *
 *  Created on: 16-Jul-2020
 *      Author: naren
 */

#include "Clock.h"
#include <iostream>
using namespace std;

int main(){
	// declare two clocks and print sum and subtraction
	Clock c1(15, 15);
	Clock c2(0, 45);
	Clock sum = c1 + c2;
	Clock sub = c1 - c2;
	cout<<c1.getHH()<<":"<<setw(2)<<setfill('0')<<c1.getMM()
			<< " + "
			<<c2.getHH()<<":"<<setw(2)<<setfill('0')<<c2.getMM()
			<<" = "
			<<sum.getHH()<<":"<<setw(2)<<setfill('0')<<sum.getMM();
	cout<<endl;
	cout<<c1.getHH()<<":"<<setw(2)<<setfill('0')<<c1.getMM()
			<< " - "
			<<c2.getHH()<<":"<<setw(2)<<setfill('0')<<c2.getMM()
			<<" = "
			<<sub.getHH()<<":"<<setw(2)<<setfill('0')<<sub.getMM();

	cout<<endl;
	Clock c3(4, 30);
	Clock c4(1, 50);
	sum  = c3 + c4;
	sub = c3 - c4;
	cout<<c3.getHH()<<":"<<setw(2)<<setfill('0')<<c3.getMM()
			<< " + "
			<<c4.getHH()<<":"<<setw(2)<<setfill('0')<<c4.getMM()
			<<" = "
			<<sum.getHH()<<":"<<setw(2)<<setfill('0')<<sum.getMM();
	cout<<endl;
	cout<<c3.getHH()<<":"<<setw(2)<<setfill('0')<<c3.getMM()
			<< " - "
			<<c4.getHH()<<":"<<setw(2)<<setfill('0')<<c4.getMM()
			<<" = "
			<<sub.getHH()<<":"<<setw(2)<<setfill('0')<<sub.getMM();

	// declare two clocks and print multiplication and division
	cout<<endl;
	Clock c5(0, 15);
	Clock c6(0, 5);
	Clock mul = c5 * c6;
	Clock divide = c5 / c6;
	cout<<c5.getHH()<<":"<<setw(2)<<setfill('0')<<c5.getMM()
			<< " * "
			<<c6.getHH()<<":"<<setw(2)<<setfill('0')<<c6.getMM()
			<<" = "
			<<mul.getHH()<<":"<<setw(2)<<setfill('0')<<mul.getMM();
	cout<<endl;
	cout<<c5.getHH()<<":"<<setw(2)<<setfill('0')<<c5.getMM()
			<< " / "
			<<c6.getHH()<<":"<<setw(2)<<setfill('0')<<c6.getMM()
			<<" = "
			<<divide.getHH()<<":"<<setw(2)<<setfill('0')<<divide.getMM();

	cout<<endl;
	Clock c7(1, 30);
	Clock c8(0, 30);
	divide = c7 / c8;
	mul = c7 * c8;
	cout<<c7.getHH()<<":"<<setw(2)<<setfill('0')<<c7.getMM()
			<< " / "
			<<c8.getHH()<<":"<<setw(2)<<setfill('0')<<c8.getMM()
			<<" = "
			<<divide.getHH()<<":"<<setw(2)<<setfill('0')<<divide.getMM();
	cout<<endl;
	cout<<c7.getHH()<<":"<<setw(2)<<setfill('0')<<c7.getMM()
			<< " * "
			<<c8.getHH()<<":"<<setw(2)<<setfill('0')<<c8.getMM()
			<<" = "
			<<mul.getHH()<<":"<<setw(2)<<setfill('0')<<mul.getMM();

	// post increment and preincrement test
	cout<<endl;
	Clock c9(4, 59);
	cout<<c9.getHH()<<":"<<setw(2)<<setfill('0')<<c9.getMM()
			<< "++ = ";
	c9++;
	cout<<c9.getHH()<<":"<<setw(2)<<setfill('0')<<c9.getMM();
	cout<<endl;

	Clock c10(16, 00);
	cout<<c10.getHH()<<":"<<setw(2)<<setfill('0')<<c10.getMM()
			<< "-- = ";
	c10--;
	cout<<c10.getHH()<<":"<<setw(2)<<setfill('0')<<c10.getMM();

	cout<<endl;
	// print current time
	Clock clock1;
	cout<<"Current Time: "<<clock1<<endl;
}



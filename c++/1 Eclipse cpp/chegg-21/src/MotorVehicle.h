/*
 * MotorVehicle.h
 *
 *  Created on: 14-Jul-2020
 *      Author:
 */

#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_
//#include "Truck.h"
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_PLATE = 32;
const int MAX_ADDRESS = 64;

namespace sdds {

   class MotorVehicle {

       char licencePlate[MAX_PLATE];           // unititialized array of characters
       char addressOfVehicle[MAX_ADDRESS];       // address where vehicle is located
       int year;                               // year vehicle was made

   public:

       // Custom constructor that recieves licencePlate and year
       MotorVehicle(const char licencePlateNumber[], int yearMade);

       // Constructor calls to set address to "Factory"
       void setAddress(const char* addressLocated);

       // Moves the vehicle to new addrress if the address is different from the current address
       void moveTo(const char* address);

       // In / Out console functions
       /* Reference: */
       ostream& write(ostream& os);
       istream& read(istream& is);

       // Overloading In / Out Operator
       // HELPER FUNCTIONS:
       friend ostream& operator<<(ostream& os, MotorVehicle& m);
       friend istream& operator>>(istream& os, MotorVehicle& m);

       ~MotorVehicle();

   };

}

#endif

/*
 * MotorVehicle.cpp
 *
 *  Created on: 14-Jul-2020
 *      Author:
 */

#define _CRT_SECURE_NO_WARNINGS

#include "MotorVehicle.h"
//#include "Truck.h"
//#include
#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

namespace sdds {

   MotorVehicle::MotorVehicle(const char licencePlateNumber[], int yearMade) {

//       assert(strlen(licencePlate) < sizeof(licencePlateNumber));
	   assert(strlen(licencePlateNumber) < sizeof(licencePlate));
       strcpy(licencePlate, licencePlateNumber);

       year = yearMade;
       strcpy(addressOfVehicle, "Factory");

   }

   void MotorVehicle::moveTo(const char* address) {

       if (address != addressOfVehicle) {

           cout << "| " << right << setw(10) << licencePlate << " | | " << setw(20) << right <<
               addressOfVehicle << " --->--- " << address << " |" << endl;

//           assert(strlen(addressOfVehicle) < sizeof(address));
           assert(strlen(address) < sizeof(addressOfVehicle));
           strcpy(addressOfVehicle, address);
       }
   }

   ostream& MotorVehicle::write(ostream& os) {

       //cout << " | " << [YEAR] << " | " << [PLATE] << " | " << [ADDRESS] << endl;

       os << "| " << year << " | " << right << setw(10) << licencePlate << " | "
           << setw(20) << right << addressOfVehicle;
       return os;
   }

   istream& MotorVehicle::read(istream& is)
   {
       cout << "Built year: ";
       is >> year;
       cout << "License plate: ";
       is >> licencePlate;
       cout << "Current location: ";
       is >> addressOfVehicle;
       return is;
   }

   ostream& operator<<(ostream& os, MotorVehicle& t)
   {
       return t.write(os);
   }

   istream& operator>>(istream& is, MotorVehicle& t)
   {
       return t.read(is);
   }

   MotorVehicle::~MotorVehicle() { }
}


/*
 * Truck.cpp
 *
 *  Created on: 14-Jul-2020
 *      Author:
 */

#define _CRT_SECURE_NO_WARNINGS
//#include
#include "Truck.h"
#include "MotorVehicle.h"
#include <iomanip>
#include <iostream>
#include <string.h>
//#include

using namespace std;

namespace sdds {

   Truck::Truck(const char licencePlateNumber[], int year, double capacity, char* currentAddress) : MotorVehicle(licencePlateNumber, year) {

       maxWeight = capacity;
       currentWeight = 0;

       MotorVehicle::moveTo(currentAddress);
   }

   bool Truck::addCargo(double cargo) {
       /* a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter.
           Do not exceed the capacity! If the current load has been changed, return true, otherwise return false. */

       bool flag = false;
       double tempWeight = currentWeight + cargo;

       if (currentWeight != maxWeight)
       {
           if (tempWeight <= maxWeight) {
               currentWeight = currentWeight + cargo;
               return true;
           }
           else{
               currentWeight = maxWeight;
               return true;
           }
       }
       return false;

   }

   bool Truck::unloadCargo() {
       /* A mutator that unloads current cargo(sets the attribute to 0).
       If the current load has been changed, return true, otherwise return false. */

       bool flag = false;

       if (currentWeight != 0) {
           currentWeight = 0;
           flag = true;
       }
       return flag;
   }

   ostream& Truck::write(ostream& os) {

       // Call function from MotorVehicle class to write it's members to OS
       MotorVehicle::write(os);

       os << "| " << right << setw(10) << currentWeight << "/" << maxWeight << " | ";
       return os;
   }

   istream& Truck::read(istream& in) {
       MotorVehicle::read(in);//calling superclass function
       cout << "Capacity: ";
       in >> this->maxWeight;
       cout << "Cargo: ";
       in >> this->currentWeight;
       return in;
   }

   ostream& operator<<(ostream& os, Truck& t)
   {
       return t.write(os);
   }

   istream& operator>>(istream& is, Truck& t)
   {
       return t.read(is);
   }

   Truck::~Truck() { }

}


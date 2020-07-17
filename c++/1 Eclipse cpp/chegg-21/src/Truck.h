/*
 * Truck.h
 *
 *  Created on: 14-Jul-2020
 *      Author:
 */

#ifndef TRUCK_H_
#define TRUCK_H_
#include "MotorVehicle.h"
#include <iostream>
#include <string.h>

using namespace std;

namespace sdds {

	class Truck : public MotorVehicle{

       double maxWeight;
       double currentWeight;

   public:

       Truck(const char licencePlateNumber[], int year, double capacity, char* currentAddress);

       bool addCargo(double cargo);
       bool unloadCargo();

//       MotorVehicle::write;
//       MotorVehicle::read;

       ostream& write(ostream& os);
       istream& read(istream& in);

       friend ostream& operator<<(ostream& os, Truck& t);
       friend istream& operator>>(istream& is, Truck& t);

       ~Truck();
   };

}

#endif /* SRC_TRUCK_H_ */

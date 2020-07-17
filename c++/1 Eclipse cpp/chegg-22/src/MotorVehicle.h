

#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_
#include <iostream>
#include <string.h>

using namespace std;
const int LIC = 32;
namespace sdds
{
	class MotorVehicle
	{
		private:
			char license[LIC];
			char address[64];
			int year;
		public:
			MotorVehicle(char licPlateNo[], int year);
			void moveTo(const char *address);
			ostream& write(ostream &os);
			istream& read(istream & in);
			friend ostream& operator<<(ostream &os, MotorVehicle m);
			friend istream& operator>>(istream &os, MotorVehicle &m);
			virtual ~MotorVehicle();
	};
}
#endif

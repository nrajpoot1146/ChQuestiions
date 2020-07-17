
#include <iomanip>
#include "MotorVehicle.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(char licPlateNo[], int year)
	{
		strcpy(this->license, licPlateNo);
		this->year = year;
		strcpy(this->address,"At Factory");
	}

	void MotorVehicle::moveTo(const char *address)
	{
		if (strcmp(this->address, address) != 0)
		{
			cout<<license << " | " <<setw(20)<<this->address << "--->---"<<address<<endl;
			strcpy(this->address, address);
		}
	}

	ostream& MotorVehicle::write(ostream &os)
	{
		os << "| " << this->year << " | " <<license << " | "<<address;
		return os;
	}

	istream& MotorVehicle::read(istream &is)
	{
		cout << "Built year: ";
		is >> this->year;
		cout << "License plate: ";
		is >> this->license;
		cout << "Current location: ";
		is >> this->address;
		return is;
	}

	ostream& operator<<(ostream &os, MotorVehicle t){
		t.write(os);
		return os;
	}

	istream& operator>>(istream &is, MotorVehicle &t){
		t.read(is);
		return is;
	}

	MotorVehicle::~MotorVehicle(){}
}

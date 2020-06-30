#include "Godzilla.h"

#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

 Godzilla::Godzilla() {

     //default constructor

     srand(time(0));
     _name = "Godzilla";
     _health = (rand() % 49) + 51; //random number not inclusive
     _power = (rand() % 14) + 11; //random number not inclusive


 }
    //parameterized constructor
Godzilla::Godzilla(string n, double h, double p){

     _name = n;
     SetHealth(h);
     SetPower(p);


};

double Godzilla::GetHealth() {

    return _health;
}

void Godzilla::SetHealth(double h) {
    if (h <= 0) {
        _health = rand() % 49 + 51;
    } else {
        _health = h;
    }

}
double Godzilla::GetPower() {

    return _power;
}

void Godzilla::SetPower(double p) {

    if (p <= 0) {
        _power = rand() % 14 + 11;
    } else {
        _power = p;
    }

}

/**
* definition of attack function
* function substract callee's power from target health
*/
void Godzilla::attack(Godzilla &godzilla){
	cout<<this->_name << " attacks "<<godzilla._name<<".\n";
	double health = godzilla.GetHealth();
	health = health - this->_power ;
	godzilla._health = health;
	if(godzilla.GetHealth()<=0){
		cout<<godzilla._name<<" has been vanquished.\n";
	}
}

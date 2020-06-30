#ifndef CSCI261_GODZILLA_H
#define CSCI261_GODZILLA_H

#endif //CSCI261_GODZILLA_H

#include <string>

using namespace std;

class Godzilla{

    public:
        Godzilla();
        Godzilla(string n, double h, double p);
        double GetHealth();
        double GetPower();
        void SetHealth(double h);
        void SetPower(double p);
        /**
        * prototype of attack function
        * @param target godzilla object
        */
        void attack(Godzilla &godzilla);

    private:
        string _name;
        double _health;
        double _power;

};

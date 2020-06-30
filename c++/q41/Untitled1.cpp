#include "Godzilla.cpp"
#include<iostream>

using namespace std;

int main() {
    double health;
    double power;

    cout << "Enter Health: ";
    cin >> health;
    cout << "Enter Power: ";
    cin >> power;

    Godzilla godzilla;

    Godzilla Mechagodzilla("mechagodzilla", health, power);

    cout << "\nGodzilla: \n";
    cout << "Health = " << godzilla.GetHealth() << endl;
    cout << "Power = " << godzilla.GetPower() << endl;

    cout << "Mechagodzilla: \n";
    cout << "Health = " << Mechagodzilla.GetHealth() << endl;
    cout << "Power = " << Mechagodzilla.GetPower() << endl;
    
    cout<<endl;
	// godzilla attack mechagodzilla one time 
    godzilla.attack(Mechagodzilla);
    
    // mechagodzilla attack godzilla until godzilla health is less than or equal to zero
    while(godzilla.GetHealth()>0){
    	Mechagodzilla.attack(godzilla);
	}

    return 0;

}

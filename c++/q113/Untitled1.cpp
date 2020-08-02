#include <iostream>
using namespace std;

enum PlanetIndex{
	Mercury,
	Venus,
	Earth,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune
};

class Planet{
	string name;
	float gravity;
	double distanceFromSun;
	public:
		
		Planet(){
			this->name = "";
			this->gravity = 0.0;
			this->distanceFromSun = 0.0;
		}
		
		Planet(string name, float gravity, float distanceFromSun){
			this->name = name;;
			this->gravity = gravity;
			this->distanceFromSun = distanceFromSun;
		}
		
		string getName(){
			return this->name;
		}
		
		void setName(string name){
			this->name = name;
		}
		
		float getGravity(){
			return this->gravity;
		}
		
		void setGravity(float gravity){
			this->gravity = gravity;
		}
		
		double getDistanceFromSun(){
			return this->distanceFromSun;
		}
		
		void setDistanceFromSun(double distanceFromSun){
			this->distanceFromSun = distanceFromSun;
		}
		
};

void showMenu(){
	cout<<"INTERPLANETARY TRAVEL MENU\n";
	cout<<"----------------------------";
	cout<<"a) Mercury"<<endl;
	cout<<"b) Venus"<<endl;
	cout<<"c) Earth"<<endl;
	cout<<"d) Mars"<<endl;
	cout<<"e) jupiter"<<endl;
	cout<<"f) Saturn"<<endl;
	cout<<"g) Uranus"<<endl;
	cout<<"h) Neptune"<<endl;
	cout<<"q) Quit"<<endl;
}

int main(){
	Planet planets[8];
	
	planets[Mercury].setName("Mercury");
	planets[Mercury].setGravity(3.7); // in ms^2
	planets[Mercury].setDistanceFromSun(48.176); // in million km
	
	planets[Venus].setName("Veus");
	planets[Venus].setGravity(8.87);
	planets[Venus].setDistanceFromSun(108.84);
	
	planets[Earth].setName("Earth");
	planets[Earth].setGravity(9.807);
	planets[Earth].setDistanceFromSun(151.87);
	
	planets[Mars].setName("Mars");
	planets[Mars].setGravity(3.711);
	planets[Mars].setDistanceFromSun(807.89);
	
	planets[Jupiter].setName("Jupiter");
	planets[Jupiter].setGravity(24.79);
	planets[Jupiter].setDistanceFromSun(770.92);
	
	planets[Saturn].setName("Saturn");
	planets[Saturn].setGravity(10.44);
	planets[Saturn].setDistanceFromSun(1494.6);
	
	planets[Uranus].setName("Uranus");
	planets[Uranus].setGravity(8.87);
	planets[Uranus].setDistanceFromSun(2960.7);
	
	planets[Neptune].setName("Neptune");
	planets[Neptune].setGravity(11.15);
	planets[Neptune].setDistanceFromSun(4476.5);
	
	showMenu();
	char selection;
}

#include <iostream>
#include <iomanip>

/**
* class that can store matrial name and it's index
*/
class Material{
public:
	std::string name;
	float n;
	
	Material (std::string name, float n) : name(name), n(n){}
	
	Material (std::string name) : name(name), n(0){}
	
	Material () : name(""), n(0){}
};

int main(){
	Material m[10]; // declaration array of matrial object
	
	const double c = 2.99792458e08; // speed of light
	
	// intialize array with material name and it's index
	m[0].name = "Vacuum"; m[0].n = 1;
	m[1].name = "Air"; m[1].n = 1.0003;
	m[2].name = "Water"; m[2].n = 1.33;
	m[3].name = "Ethyl Alcohol"; m[3].n = 1.36;
	m[4].name = "Whale Oil"; m[4].n = 1.460;
	
	m[5].name = "Crown Glass"; m[5].n = 1.52;
	m[6].name = "Salt"; m[6].n = 1.54;
	m[7].name = "Heavy Flint Glass"; m[7].n = 1.65;
	m[8].name = "Diamond"; m[8].n = 2.42;
	m[9].name = "Lead"; m[9].n = 2.6;
	
	/*
	* calculate speed of light in material
	* print material name, refractive index, and speed of light in material
	*/
	for(int i=0; i<10; i++){
		std::cout<<"Material: "<<m[i].name<<std::endl;
		std::cout<<std::setw(10)<<"n = "<<std::setw(5)<<m[i].n<<std::setw(10)<<"v = "<< (c/m[i].n) <<std::endl;
	}
}

#include <vector>
#include <iostream>
using namespace std;

/**
* function to check location has mine or open location
* @param v vector of mine and open location
* @param loc location
* @return content of vector v if location is valid otherwise return false
*/
bool IsLocationAMine(vector<bool> v, int loc){
	try {
		return v.at(loc);
	}catch(...){
		return false;
	}
}

/**
* function to count left and right adjecent mines
* @param v vector of mine and open location
* @param loc location
* @return number of mines
*/
int HowManyMinesAreAdjacent(vector<bool> v, int loc){
	try {
		int nMine = 0;
		nMine += IsLocationAMine(v, loc - 1);
		nMine += IsLocationAMine(v, loc + 1);
		return nMine;
	}catch (...){
		return -1;
	}
}

/**
* driver main function
*/
int main(){
	vector<bool> v; // vector of bool
	vector<int> pV; // vector of mines count
	
	// fill vector of bool
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	
	// count adjecent mines
	// push back into vector of mines count
	for (int i = 0; i < v.size(); i++){
		int nMines = HowManyMinesAreAdjacent(v, i);
		pV.push_back(nMines);
	}
	
	// test of sLocationAMine function
	for (int i = 0; i < v.size(); i++){
		IsLocationAMine(v, i) ? cout<<"M " : cout<<"O ";
	}
	
	cout<<endl;
	// print mines count vector
	for (int i = 0; i < pV.size(); i++){
		cout<<pV.at(i)<<" ";
	}
}



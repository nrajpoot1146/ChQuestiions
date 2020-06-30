#include<iostream>
#include "DateProfile.cpp"
using namespace std;

// function to display fit value and name of two profiles
void displayTwoProfile(DateProfile profile1, DateProfile profile2){
	cout<<"Fit between "<<profile1.getName()<<" and "<<profile2.getName()<<": "<<profile1.fitValue(profile2);
	cout<<endl;
}

int main(){
	DateProfile profile[4];
	profile[0].setGender('F');
	profile[0].setSearchGender('M');
	profile[0].setName("Sarah Somebody");
	profile[0].setRomance(8);
	profile[0].setFinance(7);
	
	profile[1].setGender('M');
	profile[1].setSearchGender('F');
	profile[1].setName("Steve nobody");
	profile[1].setRomance(8);
	profile[1].setFinance(7);
	
	profile[2].setGender('F');
	profile[2].setSearchGender('M');
	profile[2].setName("abc nobody");
	profile[2].setRomance(4);
	profile[2].setFinance(5);
	
	profile[3].setGender('F');
	profile[3].setSearchGender('M');
	profile[3].setName("def nobody");
	profile[3].setRomance(7);
	profile[3].setFinance(2);
	
	profile[4].setGender('F');
	profile[4].setSearchGender('M');
	profile[4].setName("ghi nobody");
	profile[4].setRomance(5);
	profile[4].setFinance(8);
	
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			displayTwoProfile(profile[i],profile[j]);
		}
	}
}

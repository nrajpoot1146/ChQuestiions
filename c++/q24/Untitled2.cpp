#include<iostream>

using namespace std;

int main(){
	cout<<"|======================================================|"<<endl;
	cout<<"|                 Filename: spHWintro.cpp              |"<<endl;
	cout<<"|                  Programmer: Your_Name               |"<<endl;
	cout<<"|          Description: Solve a physics problem        |"<<endl;
	cout<<"|                 Major: Computer Science              |"<<endl;
	cout<<"|                 Classification: Freshman             |"<<endl;
	cout<<"|          Programming ExperienceL: HTMP,Python        |"<<endl;
	cout<<"|======================================================|"<<endl;
	cout<<endl<<endl;
	
	
	cout<<"Now for some physics..."<<endl;
	
	float v,i,r;
	cout <<"Enter value of voltage: ";
	cin>>v; // read the value of v from stdin
	cout<<"Enter value of resisteance: ";
	cin>>r; //read the value of r from stdin
	
	if(r != 0){
		i = v / r; // ohms law formula;
		cout<<endl<<"current is: "<<i<<" amps";
	}else{
		cout<<endl<<"value of resistance should not be zero... thank you"<<endl;
	}
	
	cout<<endl<<endl<<"Program completed successfully"<<endl;
}

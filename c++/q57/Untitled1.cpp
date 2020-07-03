#include <iostream>
using namespace std;

int main(){
	// variable declaration
	int a, b, sum, product, avg;
	
	cout<<"Input a: ";
	cin>>a; // read variable a
	
	cout<<"Input b: ";
	cin>>b; // read vaiable b

	if (a % 2 == 0){ // check a is even  or odd
		cout<<"a is even number"<<endl;
	}else{
		cout<<"a is odd number"<<endl;
	}
	
	if(b % 2 == 0){ // check b is even or odd
		cout<<"b is even number"<<endl;
	}else{
		cout<<"b is odd number"<<endl;
	}
	
	// calculate sum of a and b
	sum = a + b;
	cout<<"Sum = "<<sum<<endl; // print sum
	
	// calculate average of a and b
	avg = (a + b) / 2;
	cout<<"Average = "<<avg<<endl; // print average
	
	// calculate product of a and b 
	product = a * b;
	cout<<"Product = "<<product<<endl;// print average
}

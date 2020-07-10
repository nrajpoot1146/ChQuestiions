#include <iostream>

using namespace std;

int main(){
	int num;
	cout<<"Enter a number: ";
	cin>>num; // read number
	
	int reverse = 0;
	
	// generate reverse number
	while (num > 0) {
		int mod = num % 10; // get last digit
		reverse = reverse * 10 + mod; // generate reverse number
		num /= 10;
	}
	
	cout<<"Here are digits: "<<endl;
	// print number
	while (reverse > 0){
		int mod = reverse % 10; // get last digit
		cout<<mod<<endl; // print digits of number
		reverse /= 10;
	}
}

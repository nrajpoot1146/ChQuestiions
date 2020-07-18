#include <iostream>
using namespace std;

int main(){
	int amt;
	
	// declare an array of size 6
	// to store bill count for different bill value
	// a[0] for bill value 1
	// a[1] for bill value 5
	// a[2] for bill value 10
	// a[3] for bill value 20
	// a[4] for bill value 50
	// a[5] for bill value 100
	// initialize all array value to 0
	int nb[6] = {0};
	cout<<"Enter total amount: ";
	cin>>amt;
	
	// pay for bill value 1
	if (amt % 5 != 0){
		nb[0] = amt % 5;
		amt = amt - nb[0];
		
	}
	
	// pay for bill value 5
	if (amt % 10 != 0){
		nb[1] = (amt % 10) / 5;
		amt = amt - nb[1] * 5;
	}
	
	// pay for bill value 10 and 20
	if (amt % 50 != 0){
		int temp = amt % 50;
		
		// pay for bill value 10
		if (temp % 20 != 0){
			nb[2] = (temp % 20) / 10;
			temp = temp - nb[1] * 10;
		}
		
		// pay for bill value 20
		nb[3] = temp / 20;
		amt = amt - temp; 
	}
	
	// pay for bill value 50
	if (amt % 100 != 0){
		nb[4] = (amt % 100) / 50;
		amt = amt - nb[4] * 50;
	}
	
	// pay for bill value 100
	nb[5] = amt / 100;

	// print array
	for (int i=0; i<6; i++){
		cout<<nb[i]<<" ";
	}
}

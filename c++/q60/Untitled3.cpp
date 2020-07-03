
#include <iostream>
using namespace std;

int main(){
	int x, y;
	
	cout<<"Enter two integer: ";
	// read two integer
	cin>>x>>y;
	
	cout<<endl;
	
	// loop to calculate and print
	// x and x = x-y until x is >= 0
	while (x >= 0){
		cout<<x<<" ";
		x = x - y;
	}
}

#include <iostream>
using namespace std;

int main(){
	string str;
	cout<<"Enter a string: ";
	cin>>str; // read string from user
	int len = str.length(); // get length of string
	// exchange letter
	// first letter with last letter
	// second letter with second last letter
	// and so on
	for (int i=0; i < len / 2; i++){
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	cout<<str; // print resultant string;
}

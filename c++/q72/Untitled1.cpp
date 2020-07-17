#include <iostream>

using namespace std;

int main(){
	
	while (true){
		// declare string variable
		string str;
		cout<<"Enter a word: ";
		// read string variable
		cin>>str;
		
		// check condition to quit program
		if(str == "quit"){
			// print good bye message
			cout<<"Good Bye";
			break;
		}
		
		// generate reverse of word
		string rev = string(str.rbegin(), str.rend());
		
		// print reverse
		cout<<rev<<endl;
	}
}

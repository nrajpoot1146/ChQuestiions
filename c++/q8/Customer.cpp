#ifndef Customer_cpp
#define Customer_cpp
#include<string>
#include<iostream>
using namespace std;
class Customer{
	private:
		string name;
		string address;
	public:
		Customer(): name(NULL), address(NULL){
			
		}
		Customer(string n, string a): name(n), address(a){
			
		}
		
		string getName(){
			return this->name;
		}
		void setName(string n){
			this->name = n;
		}
		string getAddress(){
			return this->address;
		}
		void setAddress(string a){
			this->address = a;
		}
		void displayCustomer(){
			cout<<"Customer Name : "<<this->name<<endl;
			cout<<"Customer Address : "<<this->address<<endl;
		}
};

#endif

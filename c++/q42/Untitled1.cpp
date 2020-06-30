#include<iostream>
#include "Customer.cpp"
#include "WaittingList.cpp"
using namespace std;

int main(){
	WaittingList wl;
	wl.readFromFile();
	double current_balance = 60000000;
	cout<<"Enter new Customer: "<<endl;
	cout<<"name: ";
	string name;
	getline(cin,name);
	cout<<"operation (Deposit or Withdraw):";
	string operation;
	getline(cin,operation);
	double money;
	cout<<"Enter money: ";
	cin>>money;
	cout<<"Enter age: ";
	int age;
	cin>>age;
	
	Customer newCustomer = Customer(name, operation, money, age);
	wl.addCustomer(newCustomer);
	
	wl.print();
	
	cout<<"\namount in bank: ";
	printf("%6.2lf\n",current_balance);
	
	while(wl.size()>0){
		Customer oldest = wl.getOldest();
		if ( oldest.getOperation() == "Deposit" || oldest.getOperation() == "deposit"){
			current_balance += oldest.getMoney();
		}else{
			current_balance -= oldest.getMoney();
		}
		
		string operation = oldest.getOperation();
		printf("Amount in bank after %s operation: %6.2lf\n",operation.c_str(),current_balance);
		wl.removeOldest();
	}
}

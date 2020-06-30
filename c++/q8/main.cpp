#include"Account.cpp"
#include"Bank.cpp"
#include"Saving.cpp"
#include"Checking.cpp"
#include"Customer.cpp"
#include<iostream>
#include<map>
using namespace std;

int main(){
	Bank bank;
	
	bank.setName("public bank");
	bank.setroutingnum(100);
	
	bank.createAccount("ram","america",5000);
	bank.createAccount("rohan","india",50000);
	bank.createAccount("shyam","china",6000);
	
	map<int, Account*> accounts = bank.getAccounts();
	
	accounts[1]->displayAccount();
	accounts[2]->displayAccount();
	accounts[3]->displayAccount();
	
	cout<<endl<<endl<<"updated : "<<endl;
	accounts[1]->withdraw(1,500);
	accounts[1]->displayAccount();
	accounts[2]->withdraw(1,600);
	
	cout<<"Bank Name : "<<bank.getname()<<endl;
	cout<<"Bank routing Number : "<<bank.getroutingnum()<<endl;
}

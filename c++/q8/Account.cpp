#ifndef account_cpp
#define account_cpp
#include<string>
#include"Customer.cpp"
#include<iostream>
using namespace std;
class Account{
	private:
		int accountNum;
		float balance;
		Customer *customer;
	public:
		Account():accountNum(0), balance(0), customer(new Customer()){
			
		}
		Account(int acctNum,float b): accountNum(acctNum), balance(b), customer(new Customer()){
			
		}
		Account(int acctNum, float b, string custName, string custAddress): accountNum(acctNum), balance(b), customer(new Customer(custName, custAddress)){
			
		}
		bool withdraw(int accountNum, float ammount){
			if(accountNum == this->accountNum && this->balance > ammount){
				this->balance -= ammount;
				return true;
			}
			else{
				return false;
			}
		}
		bool deposit (int accountNum, float ammount){
			if(accountNum == this->accountNum && ammount>0){
				this->balance += ammount;
				return true;
			}else{
				return false;
			}
		}
		void setaccountNum(int a){
			this->accountNum = a;
		}
		void setbalance(float b){
			this->balance = b;
		}
		void setC(string name, string address){
			this->customer->setName(name);
			this->customer->setAddress(address);
		}
		int getaccountNum(){
			return this->accountNum;
		}
		float getbalance(){
			return this->balance;
		}
		Customer *getC(){
			return this->customer;
		}
		void displayAccount(){
			this->customer->displayCustomer();
			cout<<"Account Number : "<<this->accountNum<<endl;
			cout<<"Balance : "<<this->balance<<endl;
		}
};
#endif

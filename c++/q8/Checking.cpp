#include"Account.cpp"
#ifndef checking_cpp
#define checking_cpp
#include<iostream>
using namespace std;
class Checking : public Account{
	private:
		float chargePerCheck;
		int numCheck;
		float minBalance;
	public:
		Checking(): chargePerCheck(0), numCheck(0), minBalance(0){
			
		}
		
		void setchargePerCheck(float c){
			this->chargePerCheck = c;
		}
		
		void setnumCheck(int c){
			this->numCheck = c;
		}
		
		void setminBalance(float b){
			this->minBalance = b;
		}
		
		float getchargePerCheck(){
			return this->chargePerCheck;
		}
		
		int getnumCheck(){
			return this->numCheck;
		}
		
		float getminBalance(){
			return this->minBalance;
		}
		
		float getBalance(){
			return Account::getbalance();
		}
		
		bool withdraw(int accountNum, float ammount){
			if(this->getaccountNum() == accountNum && (this->getBalance()-ammount) >= minBalance && ammount > 0){
				return Account::withdraw(accountNum, ammount);
			}
			else{
				return false;
			}
		}
		
		void displayAccount(){
			Account::displayAccount();
			cout<<"Charge/Check : "<<this->chargePerCheck<<endl;
			cout<<"Number Check : "<<this->numCheck<<endl;
			cout<<"Minmum Balance : "<<this->minBalance<<endl;  
		}
};

#endif

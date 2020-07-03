#include<iostream>
using namespace std;

class Account{
private:
	string accNum;
	string name;
	double balance;
	double interestRate;

public:
	
	// answer - 16
	// default constructor
	Account(){
		this->accNum = "0000";
		this->name = "N/A";
		this->balance = 0;
		this->interestRate = 0;
	}
	
	// answer 17
	// overloaded constructor
	Account(string accNum, string name){
		this->accNum = accNum;
		this->name = name;
		this->balance = 0;
		this->interestRate = 0;
	}
	
	// answer 18
	// overloaded constructor
	Account(string accNum, string name, double balance, double interestRate){
		this->accNum = accNum;
		this->name = name;
		this->balance = balance;
		this->interestRate = interestRate;
	}
	
	// answer 19
	// accessor mehtod for the balance field
	double getBalance(){
		return this->balance;
	}
	
	// answer 20
	// mutator method for interestRate field
	double setInterestRate(double interestRate){
		this->interestRate = interestRate;
	}
	
	// answer 21
	// return earned interest
	double calcInterest(){
		return this->balance * this->interestRate / 100.0;
	}
	
	string getAcctNum(){
		return this->accNum;
	}
};

// answer 26
// return true if given account is exist in array, otherwise return false
bool findAccount(Account *accounts[], string accountNum){
	for (int i = 0; i<5; i++){
		if (accounts[i]->getAcctNum() == accountNum){
			return true;
		}
	}
	
	return false;
}

int main(){
	// answer 22
	Account myAccount("1234", "sampOne", 2500, 1);
	
	// answer 23
	myAccount.setInterestRate(1);
	
	// answer 24
	cout<<"Balance: "<<myAccount.getBalance()<<endl;
	
	// answer 25
	Account *ptr;
	ptr = &myAccount;
	cout<<"Earned Interest: "<<ptr->calcInterest()<<endl;
	
	// answer 26
	Account *accounts[5];
	accounts[0] = new Account("1234", "sampOne", 2500, 1);
	accounts[1] = new Account("2345", "sampTwo", 3400, 1);
	accounts[2] = new Account("3456", "sampThree", 8400, 1);
	accounts[3] = new Account("4567", "sampFour", 1400, 1);
	accounts[4] = new Account("5678", "sampFive", 4400, 1);
	
	bool val = findAccount(accounts, "2342");
	val ? cout<<"find successfully" : cout<<"account not found";
	
}

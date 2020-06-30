#include"Account.cpp"
#ifndef saving_cpp
#define saving_cpp
#include<iostream>
using namespace std;
class Saving : public Account{
	private:
		float interestRate;
	public:
		Saving(): interestRate(0){
			
		}	
		void setinterestRate(float i){
			this->interestRate = i;
		}
		void getinterestRate(){
			this->interestRate;
		}
		float getBalance(){
			this->getBalance();
		}
		void displayAccount(){
			Account::displayAccount();
			cout<<"Interest Rate : "<< this->interestRate<<endl;
		}
};

#endif

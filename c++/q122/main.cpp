
#include <iostream>
using namespace std;

class Money{
	double amount;
	public:
		
		// default constructor
		Money(){
			this->amount = 0.0;
		}
		
		// constructor with single parameter
		Money(double amount){
			this->amount = amount;
		}
		
		// print current amount
		void output() const{
			cout<<"Amount:"<<this->amount<<endl;
		}
		
		// get amount
		double getAmount(){
			return this->amount;
		}
		
		// set amount
		void setAmount(double amount){
			this->amount = amount;
		}
};

int main(){
	Money a,b(2.5);
	a.output(); // Amount:0
	b.output(); // Amount:2.5
	a.setAmount(1.2);
	cout<<a.getAmount()<<endl; // 1.2
}

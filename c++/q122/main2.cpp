
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

// class USD derived from class Money
class USD : public Money{
	public:
		USD(){}
		USD(double amount) : Money(amount){}
};

// class EUR derived from class Money
class EUR : public Money{
	public:
		EUR(){}
		EUR(double amount) : Money(amount){}
};

// class GBP derived from class Money
class GBP : public Money{
	public:
		GBP(){}
		GBP(double amount) : Money(amount){}
};

int main(){
	USD u1,u2(1.2);
	u1.output();
	u2.output();
	GBP g1,g2(2.5);
	g1.output();
	g2.output();
	EUR e1,e2(3.6);
	e1.output();
	e2.output();
}

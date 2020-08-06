
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
		virtual void output() const{
			cout<<"Amount:"<<this->amount<<endl;
		}
		
		// get amount
		double getAmount() const{
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
		
		// override output method
		void output() const{
			cout<<"Amount:"<<this->getAmount()<<" USD"<<endl;
		}
};

// class EUR derived from class Money
class EUR : public Money{
	public:
		EUR(){}
		EUR(double amount) : Money(amount){}
		
		// override output method
		void output() const{
			cout<<"Amount:"<<this->getAmount()<<" EUR"<<endl;
		}
};

// class GBP derived from class Money
class GBP : public Money{
	public:
		GBP(){}
		GBP(double amount) : Money(amount){}
		
		// override output method
		void output() const{
			cout<<"Amount:"<<this->getAmount()<<" GBP"<<endl;
		}
};

int main(){
	Money *p = new Money(1.1);
	p->output(); // print Amount: 1.1
	p = new USD(2.2);
	p->output(); // print Amount: 2.2 USD
	p = new EUR(3.3);
	p->output(); // print Amount: 3.3 EUR
	p = new GBP(4.4);
	p->output(); // print Amount: 4.4 GBP
}

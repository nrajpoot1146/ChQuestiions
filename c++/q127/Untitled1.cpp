#include <iostream>
using namespace std;

class PolynomialFactor{
	int cofficient;
	char baseFactor;
	int exponent;
	public:
		
		// parameterize constructor
		PolynomialFactor(int cofficient = 1, char baseFactor = 'x', int exponent = 0){
			this->cofficient = cofficient;
			this->baseFactor = baseFactor;
			this->exponent = exponent;
		}
		
		// print polynomial factor (c*x^e)
		void print(){
			if (cofficient == 0){
				cout<<0;
				return;
			}
			
			if (exponent == 0){
				cout<<cofficient;
				return;
			}
			
			cout<<cofficient<<"*"<<baseFactor<<"^"<<exponent;
		}
};

int main(){
	PolynomialFactor p1(5);
	PolynomialFactor p2(5,'x',1);
	PolynomialFactor p3(-3, 'x', 7);
	
	p1.print();
	cout<<endl;
	p2.print();
	cout<<endl;
	p3.print();
}

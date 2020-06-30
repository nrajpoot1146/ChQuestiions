#include<iostream>
using namespace std;

int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
}

int main(){
	int a,b;
	int c;
	cout<<"Enter first number: ";
	cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	cout<<"Enter control bit: ";
	cin>>c;
	if(c==1){
		cout<<binaryToDecimal(a)+binaryToDecimal(b);
	}else{
		cout<<binaryToDecimal(a)-binaryToDecimal(b);
	}
}

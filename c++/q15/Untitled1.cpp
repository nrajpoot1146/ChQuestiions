#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int power(int x,int y){//function to calculate power of a number
	int res=1;
	while(y>0){
		res *= x;
		y--;
	}
	return res;
}

int convert_str_Bs_ten(string str,int base){// function to convert input entry (string) to number (integer) in base ten
	int n = str.length()-1;
    int dec_value = 0;
	int i=0;
    while (n>=0) {
    	char c = str[n];
    	
        int digit = 0;
        
        if(c >= '0' && c<= '9'){
        	digit = c-'0';
		}else if(c>='A' && c<='F'){
			digit = 10 + c - 'A';
		}else{
			return -1;
		}
		
		if(digit>=base){
			return -1;
		}

        dec_value += digit * power(base,i);

        i++;
        n--;
    }

    return dec_value;
}

void convert_fbs_tbs(int num,int tobase){//function to convert from base 10 to another base
	string res = "";
	while(num>0){
		int mod = num % tobase;
		char c;
		if(mod<10){
			c = (mod+'0'); //convert integer to charracter
		}else{
			c = 'A' + mod - 10; //convert integer to charracter
		}
		res = c + res;
		num = num / tobase;
	}
	cout<<res;
}

//driver function
int main(){
	int frombase;
	int tobase;
	string value;
	while(true){
		cout<<"\t\tNUMBER SYSTEM CONVERSION TOOL"<<endl;
		cout<<"\t\t_____________________________"<<endl;
		cout<<"Choose bases from 2 to 16"<<endl;
		cout<<"\nFrom base:";
		cin>>frombase;
		while(frombase<2 || frombase>16){
			cout<<"From base:";
			cin>>frombase;
		}
		cout<<"To base:";
		cin>>tobase;
		
		while(tobase<2 || tobase>16){
			cout<<"To base:";
			cin>>tobase;
		}
		
		cout<<"\nEnter the value:";
		cin>>value;
		
		int decValue = convert_str_Bs_ten(value,frombase);
		while(decValue == -1){
			cout<<"Enter the value:";
			cin>>value;
			decValue = convert_str_Bs_ten(value,frombase);
		}
		
		cout<<"\nResult Value : ";
		convert_fbs_tbs(decValue, tobase);
		cout<<endl;
		
		char op;
		cout<<"\nWould you like to continue : ";
		cin>>op;
		if(op == 'n' || op =='N'){
			break;
		}
	}
}

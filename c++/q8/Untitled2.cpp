#include<iostream>
using namespace std;
string format(long long);

int main(){
	long long a;
	
	
	cin>>a;	
	string res = format(a);
	cout<<res;
}


  string format(long long val){
  	int count = 0 ;//number of digit
  	long long temp = val;
  	int countCom = 0;
  	while(temp != 0){
  		temp/=10;
  		count++;
	  }
	
	if(count % 3 == 0){
		countCom = (count/3) -  1;
	}else{
		countCom = (count / 3);
	}
	
	int totalChar = count + countCom;
	
	char res[totalChar+1];
	res[totalChar] = '\0';
	cout<<sizeof(res)<<endl;
	int mod;
	int i=0;
	while(totalChar--){
		if(i == 3){
			res[totalChar] = ',';
			i=0;
			continue;
		}
		int mod = val % 10;
		res[totalChar] = mod + '0';
		i++;
		val = val/10;
	}
	
	return res;
  }

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char s1[50] = "Corona Virus";
	char s2[50] = " Covid-19";
	// code to append string s2 into s1
	// (i)
	strcat(s1, s2);
	// (ii)
	// code to compare string s1 and se and display
	// ths string that has highest value
	int cmp = strcmp(s1, s2);
	if (cmp > 0){
		cout << s1;
	}else {
		cout << s2;
	}
	
	cout<<endl;
	// code to display string s1 and s2
//	cout<<"String s1 = "<<s1<<endl;
//	cout<<"String s2 = "<<s2<<endl;
	cout<<s1<<" year 2020"<<endl;
	cout<<"String s1="<<strlen(s1)<<" characters \n";
	cout<<"String s2="<<strlen(s2)<<" characters \n";
	
	return 0;
}

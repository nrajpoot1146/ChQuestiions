#include"mystring2.cpp"

#include<iostream>
using namespace std;

void PrintString(const char *label,
                 const String &str)
{
    cout << label << " holds \"";
    cout << str; // << is overloaded
    cout << "\" (length = " << str.length() << ")" << endl;
}

int main(){
	String str("abcd"); char c[50];
	cin>>c;
	str= c;
	cout<<str;
	cin>>c;
	str+=c;
	cout<<str;
}

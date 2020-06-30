#include<iostream>
#include<string>
#include"bag.h"

using namespace std;

int main(){
	Bag bag1,bag2,bag3;
	string str;
	int i = 0;
	cout<<"First bag: The bag contains 5 items:"<<endl;
	// reads items of first bag
	while(i++<5){
		cin>>str;
		bag1.push_back(str);
	}
	
	i=0;
	// reads items of second bag
	cout<<"\nSecond bag: The bag contains 5 items:"<<endl;
	while(i++<5){
		cin>>str;
		bag1.push_back(str);
	}
	
	// call union function
	bag3 = bag1.bagUnionWith(bag2);
	i=0;
	// print all item of third bag
	cout<<"\nThe bag containing the union of these bag: The bag contains 10 items: "<<endl;
	while(i<bag3.size()){
		cout<<bag3.at(i)<<" ";
		i++;
	}
}

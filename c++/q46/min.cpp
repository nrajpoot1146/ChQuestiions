#include<iostream>
#include<fstream>
#include "DynamicArray.h"

using namespace std;

/**
* function to remove occurence of given number
*/
template<class T>
DynamicArray<T> *removeOccurences(DynamicArray<T> da, T num){
	DynamicArray<T> *newArray = new DynamicArray<T>();
	for (int i=0; i<da.size(); i++){
		if(da[i] != num){
			newArray->add(da[i]);
		}
	}
	return newArray;
}

/*
* function to print dynamic array
*/
template<class T>
void print(DynamicArray<T> da){
	for(int i=0; i<da.size(); i++){
		cout<<da[i]<<" ";
	}
}

int main(){
	DynamicArray<int> da;
	
	ifstream fin;
	fin.open("data.txt");
	int x;
	while(fin>>x){
		da.add(x);
	}
	
	DynamicArray<int> d = *removeOccurences(da,1);
	
	print(d);
}

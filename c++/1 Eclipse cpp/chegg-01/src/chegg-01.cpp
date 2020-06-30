//============================================================================
// Name        : chegg-01.cpp
// Author      : Narendra Rajpoot
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	int n; // counts of number to be generated
	int length; // how large a number generated
	vector <unsigned long long> vec1;
	cout<<"How many random number generated: ";
	cin>>n;
	cout<<"How large a number: ";
	cin>>length;

	int l = 1;
	while(length-- > 1){
		l *= 10;
	}

	srand(3);

	int i = 0;
	while(i < n){
		unsigned long long number = rand();
		printf("%llu ", number);
		i++;
	}

	return 0;
}

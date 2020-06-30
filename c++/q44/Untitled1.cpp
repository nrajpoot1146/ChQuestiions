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
#include <time.h>
#include <algorithm>
using namespace std;

/**
* function to print a elements of given vector
* @param a vector to be print
*/
void printVector(string msg, vector<unsigned long long> vec){
	cout<<"Contents of "<<msg<<":"<<endl;
	for(int j = 0; j<vec.size(); j++){
		printf("%llu ", vec.at(j)); // print element of vector
	}
}

/**
* function to sort vector elements using bubble sort 
* @param vector to be sort
*/
void bubbleSort(vector<unsigned long long> &vec){
	for(int i = 0; i<vec.size()-1; i++){
		for (int j=0; j<vec.size()-i-1; j++){
			if(vec.at(j)>vec.at(j+1)){ // check current element is greater than next element
				// if yes, swap current element with next element
				unsigned long long t = vec.at(j);
				unsigned long int n = vec.at(j+1);
				vec[j] = n;
				vec[j+1] = t;
			}
			
		}
	}
}

/**
* function to search a number from vector
* @param vector of elements
* print index and frequency if gien number is found
*/
void searchNumber(vector<unsigned long long> &vec){
	int searchNumber;
	int count = 0;
	
	// take a number from user to be search
	cout<<endl;
	cout<<"Enter a number to be search: ";
	cin>>searchNumber;
	
	// binary search for searching an element
	int startIndex = 0; 
	int endIndex = vec.size();
	int mid = 0;
	while(startIndex < endIndex){
		mid = (startIndex + (endIndex - 1)) / 2; // calculate mid index
		
		if(vec[mid] == searchNumber){ // compare mid element of vector with search number
			// if number is equal to mid element break the loop
			break;
		}
		
		if ( searchNumber < vec[mid] ){
			// if number is less than mid element, set endIndex to mid
			endIndex = mid;
		}else{
			// if number is greater than mid element, set startIndex to mid+1
			startIndex = mid+1;
		}
	}
	
	if(startIndex < endIndex){ // check number is found or not
		int i = mid;
		// count frequency of given number, after the current index
		// remove search number from vector
		while(vec[i] == searchNumber){
			count++;
			vec.erase(vec.begin()+i);
		}
		
		i = mid-1;
		// count frequency of given number, before the current index
		// remove search number from vector
		while(vec[i] == searchNumber){
			vec.erase(vec.begin()+i);
			count++;
			i--;
		}
		
		cout<<endl;
		cout<<"Given number is found at index: "<<mid<<endl; // print index of search number if it is found
		cout<<"Frequency of word is: "<<count<<endl; // print frequency of search number
	}else{
		cout<<endl;
		cout<<"given number is not found"<<endl; // print message if search number is not found
	}
	

}

int main() {
	int n; // counts of number to be generated
	int length; // how large a number generated
	vector <unsigned long long> vec1; // vector to store random numbers
	cout<<"How many random number generated: ";
	cin>>n;
	cout<<"How large a number, length should be less then 20: ";
	cin>>length;
	
	// get a number to fix the range of random number
	while(length > 20){
		cout<<"How large a number length should be less then 20: ";
		cin>>length;
	}

	int l = 1;
	// generate a number to fix the range of random number
	while(length-- > 0){
		l *= 10;
	}

	srand(time(0));

	int i = 0;
	// generate random number and store into vector
	while(i < n){
		unsigned long long number = rand() % l;
		vec1.push_back(number);
		i++;
	}
	
	// print content of vector before sorting
	cout<<endl;
	cout<<endl;
	cout<<"Size of vec1: "<<vec1.size()<<endl;
	printVector("vec1 before sorting",vec1);
	
	cout<<endl<<endl;
	vector<unsigned long long> vec2 = vec1; // generate copy of vector vec1
	
	sort(vec1.begin(),vec1.end()); // sort vector vec1 using sort algorithm
	printVector("vec1 after sorting",vec1); // print vector vec1 after sorting
	
	bubbleSort(vec2); // sort vector vec2, copy of vector vec1
	cout<<endl<<endl;
	printVector("vec2", vec2); // print vector vec2 after bubble sorting
	
	// search a number
	for (int j = 0; j<5; j++){
		searchNumber(vec1);
	}
	
	return 0;
}


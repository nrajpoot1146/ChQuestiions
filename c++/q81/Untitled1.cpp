#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std; 

double * genInput(int size, int cap); 
void printList(double *list, int size); 
// write the function prototype of push function 
double *push(double *list, double data, int &size, int *cap);

int main() { 
	// getting two values for capacity and size of a list 
	// Assume that size is equal or less than capacity 
	int m, n; 
	cout << "Enter a number as capacity of list : " ; 
	cin >> n;
	cout << "Enter a number as size of list : " ; 
	cin >> m; 
	// declares a list of n elements but initializes only m random numbers 
	double *list = genInput(m, n); 
	printList(list, m); 
	list = push(list, 12.5, m, &n); //this function adds 12.5 at the end of list. 
	printList(list, m); 
	return 0; 
} 

// generates an array of a given capacity where size represents the number 
// of valid items in the array. 
double * genInput(int size, int cap){ 
	srand(time(0)); 
	double *p = new double[cap];
	for (int i=0; i<size; i++){
		p[i] = rand() % 10000 / 100.0;
	}
	return p;	
}

// prints the array with given size
void printList(double *p, int size){
	for (int i=0; i<size; i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}

// write push function
double *push(double *list, double data, int &size, int *cap){
	if (size >= *cap){
		// list is full
		// create new double array
		double *p = new double[2 * *cap];
		*cap = *cap * 2;
		
		// copy old list to new arrray
		for (int i=0; i<size; i++){
			p[i] = list[i];
		}
		// delete old list
		delete[] list;
		// assign new list to old array
		list = p;
	}
	list[size] = data; // push new data
	size++; // increase size by one
	return list; // return list
}

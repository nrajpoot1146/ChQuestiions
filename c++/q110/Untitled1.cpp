
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// fucntion to swap two number
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}


// function to sort given array
// use bubble sort algorithm
void bubbleSort(int list[], int numberOfElements, int &nComparision, int &nAssignments){
	for (int i=0; i<numberOfElements-1; i++){
		for (int j=0; j<numberOfElements-i-1; j++){
			if (list[j] > list[j+1]){
				swap(list[j], list[j+1]);
				nComparision++;
				nAssignments+=3;
			}
		}
	}
}


// function to sort given array
// use selection sort algorithm
void selectionSort(int list[], int numberOfElements, int &nComparision, int &nAssignments){
	
	for (int i=0; i<numberOfElements-1; i++){
		int min = i;
		
		for (int j= i+1; j<numberOfElements; j++){
			if (list[min] > list[j]){
				min = j;
				nComparision++;
			}
		}
		
		swap(list[min], list[i]);
		nAssignments+=3;
	}
}


// function to sort given array
// use insertion sort algorithm
void insertionSort(int list[], int numberOfElements, int &nComparision, int &nAssignments){
	for (int i=1; i<numberOfElements; i++){
		int sel = list[i];
		
		int j=0;
		for (int j = i-1; i>=0 && list[j] > sel; j--){
			list[j+1] = list[j];
			nAssignments++;
			nComparision++;
		}
		list[j+1] = sel;
		nAssignments++;
	}
}

// print given arrray
void printList(int list[], int nElements){
	for (int i=0; i<nElements; i++){
		cout<<list[i]<<" ";
	}
}


// mainn driver function
int main(){
	int list1[5000], list2[5000], list3[5000]; // declare three integer array of length 5000
	int numberOfElements = 20;
	// fill 20 elements
	srand(time(0));
	for (int i=0; i<numberOfElements; i++){
		list1[i] = rand() % 100;
		list2[i] = rand() % 100;
		list3[i] = rand() % 100;
	}
	
	cout<<"Before sorting\n";
	cout<<"list 1: ";
	printList(list1, numberOfElements);
	cout<<endl;
	cout<<"list 2: ";
	printList(list2, numberOfElements);
	cout<<endl;
	cout<<"list 3: ";
	printList(list3, numberOfElements);
	cout<<endl;
	
	int nComparison=0;
	int nAssignments=0;
	bubbleSort(list1, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng bubble sort: \n";
	cout<<"list 1: ";
	printList(list1, numberOfElements);
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list2, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng selection sort: \n";
	cout<<"list 2: ";
	printList(list2, numberOfElements);
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list3, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng insertion sort: \n";
	cout<<"list 3: ";
	printList(list3, numberOfElements);
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	
	
	numberOfElements = 500;
	// fill 500 elements
	srand(time(0));
	for (int i=0; i<numberOfElements; i++){
		list1[i] = rand() % 500;
		list2[i] = rand() % 500;
		list3[i] = rand() % 500;
	}
	
	
	nComparison=0;
	nAssignments=0;
	bubbleSort(list1, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng bubble sort: \n";
	cout<<"list 1: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list2, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng selection sort: \n";
	cout<<"list 2: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list3, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng insertion sort: \n";
	cout<<"list 3: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	
	
	numberOfElements = 5000;
	// fill 5000 elements
	srand(time(0));
	for (int i=0; i<numberOfElements; i++){
		list1[i] = rand() % 5000;
		list2[i] = rand() % 5000;
		list3[i] = rand() % 5000;
	}
	
	nComparison=0;
	nAssignments=0;
	bubbleSort(list1, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng bubble sort: \n";
	cout<<"list 1: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list2, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng selection sort: \n";
	cout<<"list 2: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
	cout<<endl;
	
	
	nComparison=0;
	nAssignments=0;
	selectionSort(list3, numberOfElements, nComparison, nAssignments);	
	cout<<"\nAfter sorting uisng insertion sort: \n";
	cout<<"list 3: ";
	cout<<endl;
	cout<<"Comparision = "<<nComparison<<"; Assignments = "<<nAssignments<<endl;
}

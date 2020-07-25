#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// swap two number
void swap(int &f, int &s){
	int temp = f;
	f = s;
	s = temp;
}

// function to generate max heap
void MaxHeapify(int *array, int s, int len) 
{ 
    int lChild = 2 * s + 1; // left child = 2*i + 1 
    int rChild = 2 * s + 2; // right child = 2*i + 2 
    int l = s;
  
    if (lChild < len && array[lChild] > array[l]) // compare root with left child
        l = lChild; 
  
    if (rChild < len && array[rChild] > array[l]) // compare root with right child
        l = rChild; 
  
    if (l != s) { // if largest is not root
        swap(array[s], array[l]); // swap root with largest child
        MaxHeapify(array, len, l); // call MaxHeapify recursively
    } 
} 

// heapsort function
void MyFunc ( int *array, int len) {
	// Your code here -----------------
	// generate max heap
    for (int i = len / 2 - 1; i >= 0; i--) 
        MaxHeapify(array, i, len); 
  	len--;
    while (len >= 0) { 
        swap(array[0], array[len]); // swap first element with last element
        MaxHeapify(array, 0, len);  // generate max heap
        len--;
    } 
}

int main(int argc,char **argv) {
	int *Sequence;
	int arraySize;
	// Get the size of the sequence
	cin >> arraySize;
	// Allocate enough memory to store "arraySize" integers
	Sequence = new int[arraySize];
	
	// Read in the sequence
	for ( int i=0; i<arraySize; i++ )
		cin >> Sequence[i];
	
	// Run your algorithms to manipulate the elements in Sequence
	MyFunc(Sequence, arraySize);
	
	// Output the result
	for(int i=0; i<arraySize; i++)
		cout << Sequence[i] << endl;
	
	// Free allocated space
	delete[] Sequence;

}

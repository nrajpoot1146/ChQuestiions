#include<iostream>
#include<cstdlib>
using namespace std;
#define max_size 11

void insert(int arr[], int value);
void display(int arr[]);


int main(){ // old: void main()
	const int SIZE = max_size; // old: SIZE = 10
	int arr[SIZE] = {0}; // initialize all array element with 0
	// removed: int i;
	
	insert(arr, 5); // old: insert(5)
	insert(arr, 8); // old: insert(8)
	insert(arr, 11); // old: insert(9)
	insert(arr, 1); // old: insert(1)
	insert(arr, 4); // old: insert(4)
	display(arr);
}

// function to insert an value into bst
void insert(int arr[], int value){ // old: void insert(int value){
	int Index = 0;	// old: Index = 1;
	if (arr[Index]>0){ // old: Index > 0;
		while (1){
		// removed: Index = 1;
			if (value<arr[Index]){
				if (arr[Index * 2 + 1] == 0){ // old: if (arr[Index * 2] == 0)
					Index = Index * 2 + 1; // old: Index = Index * 2;
					break;
				}
				Index = Index * 2 + 1; // old: else Index = Index * 2
			} else if (value >= arr[Index]) {
				if (arr[Index * 2 + 2] == 0){ // old: if (arr[Index * 1] == 0)
					Index = Index * 2 + 2; // old: Index = Index * 2 +1
					break;
				}
				Index = Index * 2 + 2; // old: Index = Index * 2 +1
			}
		}
		arr[Index] = value;
	} else {
		arr[0] = value; // old: arr[1] = value
		// removed: Index = 1
	}
	cout << "\n\n" << value << " inserted";
}
  
// function to display array
void display(int arr[]) {
	// removed: int j = 0; 
	cout << "\n\n array: ";
	for (int i = 0; i < max_size; i++) { // old: for (int i = 1; i <= max_size; i++)
	if (arr[i] != 0) {
		cout << arr[i] << " ";
		// removed: j++;
	} else
		cout << "-" << " ";
	}
	cout << endl << endl;
}

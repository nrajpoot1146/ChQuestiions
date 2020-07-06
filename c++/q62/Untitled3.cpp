
#include <iostream>
#include "BST.cpp"

using namespace std;

int main(){
	BST bst1;
	bst1.insert(4);
	bst1.insert(45);
	bst1.insert(5);
	bst1.insert(40);
	bst1.insert(25);
	
	cout<<"First BST: \n";
	bst1.print();
	
	cout<<"\nSecond BST using copy constructor: \n";
	BST bst2(bst1);
	bst2.print();
	
	cout<<"\nThird BST using assignment operator: \n";
	BST bst3;
	bst3 = bst1;
	bst3.print();
}

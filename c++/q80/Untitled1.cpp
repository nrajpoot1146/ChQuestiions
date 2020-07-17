#include <iostream>
#include <string>
using namespace std;

#define nullptr NULL

// template node
template <class T>
class Node{
	public:
		// public data members
		T item;
		Node *next;
};


// given function
void linkedList (){
	Node<char> *ptr1;
	Node<char> *ptr2;
	Node<char> *top;
	char ch;
	
	ptr1 = new Node<char>;
	top = ptr1;
	ptr1->item = 'P';
	ptr1 = new Node<char>;
	top->next = ptr1;
	ptr1->item = 'R';
	
	for (ch = 'C'; ch < 'K'; ch = ch +3){
		ptr2 = new Node<char>;
		ptr1->next = ptr2;
		ptr2->item = ch;
		ptr1 = ptr1->next;
		ptr2 = new Node<char>;
		ptr1->next = ptr2;
		ptr2->item = ch + 1;
		ptr1 = ptr1->next;
	}
	
	ptr1->next = nullptr;
	ptr2 = top->next->next;
	ptr2 = ptr2->next;
	ptr1 = ptr2->next->next;
	
	cout << ptr1->item;
	cout << ptr2->item;
	cout << ptr1->next->item;
	cout << ptr2->next->item;
	cout << top->next->item;
	cout << top->item<<endl;
}

// main function
int main(){
	linkedList();
}

#include<iostream>
#define nullptr NULL
using namespace std;

struct Node{
	int data; 		// each node holds an integer data
	Node* previous; // pointer to the previous node
	Node* next;		// pointer to the next node
	
	Node(int d = 0, Node *p=nullptr, Node *n = nullptr):data(d), previous(p), next(n){}
	Node *get_previous() const { return previous; } // get previous node of current node
	Node *get_next() const { return next; } //get next node of current node
	Node *insert_before(int d); // insert d before this node
	Node *insert_after(int d); // insert d after this node
	void delete_before(); // delete the node before this node
	void delete_after(); // delete the node after this node
};

Node* Node::insert_before(int d){
	Node *newNode = new Node(d, this->previous, this); // create new node
	if(this->previous != nullptr){
		this->previous->next = newNode; // put new node refrence to next of previous node
	}
	this->previous = newNode; // put new node refrence to previous of current node
}

Node* Node::insert_after(int d){
	Node *newNode = new Node(d, this, this->next); // create new node to insert after this node
	if(this->next != nullptr){
		this->next->previous = newNode;
	}
	this->next = newNode;
}

// function to delete node before current node
void Node::delete_before(){
	if(this->previous != nullptr){
		if(this->previous->previous != nullptr){
			this->previous->previous->next = this;
		}
		this->previous = this->previous->previous;
	}
}

// function to delete node after current node
void Node::delete_after(){
	if(this->next != nullptr){
		if(this->next->next != nullptr){
			this->next->next->previous = this;
		}
		this->next = this->next->next;
	}
}

/**
* function to print link list
*/
void printList(Node* root){
	while(root != nullptr){
		cout<<root->data<<" ";
		root = root->next;
	}
}

int main(){
	Node *n = new Node(2); // create new list
	n->insert_after(5); // insert a node after first node
	n->get_next()->insert_after(6); // insert a node after second node
	n->get_next()->get_next()->insert_after(9); // insert a node after third node
	
	cout<<"Initial linked list "<<endl;
	printList(n); // print list
	
	cout<<endl<<endl;
	
	n->get_next()->get_next()->insert_before(4); // insert a node before third node
	
	cout<<"Linked list after adding an element 4 before element 6"<<endl;
	printList(n);
	
	cout<<endl<<endl;
	cout<<"Linked list after deleting an element before 6"<<endl;
	n->get_next()->get_next()->delete_before();
	printList(n);
	
	cout<<endl<<endl;
	cout<<"Linked list after deleting an element after 6"<<endl;
	n->get_next()->get_next()->delete_after();
	printList(n);
}



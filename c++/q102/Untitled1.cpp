#include <iostream>
using namespace std;

// node class
class node {
    void *info;
	node *next;
public:
	node (void *v) {
		info = v;
		next = 0;
	}
	void put_next (node *n) {
		next = n;
	}
    node *get_next ( ) {
		return next;
	}
    void *get_info ( ) {
		return info;
	}
};

// list class
// support operation
//	1. insert
//	2. append
//	3. find
//	4. display
//	5. remove
class list {
    node *head; // head of the list
    node *tail;
    int nNode; // number of nodes in list
public:
    list ( ) {
		nNode = 0; // set number of nodes to 0
		head = 0; // set head poitner to 0
		tail = 0; // set tail pointer to 0
	}
	
	// remove node at given index
    void remove (int index){
    	if (nNode == 0 || index >= nNode){
    		// if list is empty do nothing
    		return;
		}
		
		if (index == 0){ // if index is 0 
			// remove head node
			head = head->get_next();
			nNode--;
			return;
		}
		
		if (index == nNode - 1){ // if index is index of last element
			// remove tail
			tail->put_next(0);
			nNode--;
			return;
		}
		
		// if index is not zero remove node at given index
		node *prev = head;
		node *curr = head->get_next();
		int i=1;
		while(curr != 0){
			if ( i == index){
				prev->put_next(curr->get_next());
				nNode--;
				break;
			}
			i++;
			prev = curr;
			curr = curr->get_next();
		}
	}
	
	// insert node at gievn position
    void insert (void *v, int index){
    	node *newNode = new node(v); // create new node

    	if (index == 0 || nNode == 0){
    		// if index is 0 or list is empty
    		// insert node as head of list
    		nNode++;
			newNode->put_next(head);
			head = newNode;
			return;
		}
		
		// otherwise insert node at given index
		nNode++;
		node *prev = head;
		node *curr = head->get_next();
		int i=1;
		while(curr != 0){
			if ( i == index){
				break;
			}
			i++;
			prev = curr;
			curr = curr->get_next();
		}
		newNode->put_next(curr);
		prev->put_next(newNode);
	}
	
	// append a node at end of the list
	void append (void * v){
		node *newNode = new node(v); // create new node
    	if (nNode == 0){ // if list is empty insert node as head
			tail = newNode;
			head = newNode;
			nNode++;
			return;
		}
		nNode++;
		tail->put_next(newNode);
		tail = newNode;
	}
	
	// get info of node at given position
	void *find (int index){
		if (index >= nNode){
			return 0;
		}
		node *curr = head;
		int i=0;
		while (curr != 0){
			if(i == index){
				return curr->get_info();
			}
			curr = curr->get_next();
		}
	}
	
	// display info of all node
    void display ( ){
    	node *curr = head;
    	while (curr != 0){
    		cout<<(*(int*)curr->get_info())<<" ";
    		curr = curr->get_next();
		}
	}
};

int main(){
	list l1; // list 
	
	// append 5 element into list
	for (int i=0; i<5; i++){
		cout<<"append: "<<(i+1) * 13<<endl;
		l1.append(new int((i+1) * 13));
	}
	cout<<endl;
	cout<<"list: ";
	l1.display();
	cout<<endl<<endl;
	
	cout<<"Insert 88 at index 2: \n";
	l1.insert(new int(88), 2);
	cout<<"list: ";
	l1.display();
	cout<<endl<<endl;
	
	l1.remove(2);
	cout<<"After removing element from index 2, \nlist: ";
	l1.display();
}




#include <iostream>
using namespace std;

// node class
class node {
    void *info; // info pointer
	node *next; // next node link
public:
	node (void *v) {
		info = v;
		next = 0;
	}
	void put_next (node *n) {
		next = n; // set next node link
	}
    node *get_next ( ) {
		return next; // return next node link
	}
    void *get_info ( ) {
		return info; // return info
	}
};

class list {
    node *head; // head of the list
    int node_num; // number of nodes in list
public:
    list ( ) {
		node_num = 0; // set number of nodes to 0
		head = 0; // set head poitner to 0
	}
	
	// remove node at given index
    void remove (int index){
    	
    	if (node_num == 0 || index >= node_num){
    		// if list is empty do nothing
    		return;
		}
		
		if (index == 0){
			// if index is 0 
			// remove head node
			head = head->get_next();
			node_num--;
			return;
		}
		
		// if index is not zero remove node at given index
		node *prev = head;
		node *curr = head->get_next();
		int i=1;
		while(curr != 0){
			if ( i == index){
				prev->put_next(curr->get_next());
				node_num--;
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

    	if (index == 0 || node_num == 0){
    		// if index is 0 or list is empty
    		// insert node as head of list
    		node_num++;
			newNode->put_next(head);
			head = newNode;
			return;
		}
		
		// otherwise insert node at given index
		node_num++;
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
    	if (node_num == 0){
    		// if list is empty 
    		// insert node as head
			newNode->put_next(head);
			head = newNode;
			node_num++;
			return;
		}
		node_num++;
		node *curr = head;
		while(curr->get_next() != 0){
			curr = curr->get_next();
		}
		
		curr->put_next(newNode);
	}
	
	// find node at given poistion
	void *find (int index){
		if (index >= node_num){
			return 0;
		}
		int i=0;
		node *curr = head;
		while (curr != 0){
			if(i == index){
				return curr->get_info();
			}
			curr = curr->get_next();
		}
	}
	
	// display all value of list
    void display ( ){
    	node *curr = head;
    	while (curr != 0){
    		void *info = curr->get_info();
    		cout<<(*(int*)info)<<" ";
    		curr = curr->get_next();
		}
	}
};

// class stack
class stack : public list{
	public:
		// push an element into stack
		void push(int *val){
			insert(val, 0);
		}
		
		// pop an element from stack
		int pop(){
			void *t = find(0);
			remove(0);
			return *((int*)t);
		}
};

int main(){
	list l1; // list 
	
	// append 5 element into list
	l1.append(new int(15));
	l1.append(new int(16));
	l1.append(new int(144));
	l1.append(new int(12));
	l1.append(new int(1));
	cout<<"Initial list: ";
	l1.display();
	cout<<endl;
	
	l1.remove(2);
	cout<<"After removing element from index 2, list: ";
	l1.display();
	cout<<endl<<endl;
	
	stack s1;
	// push five value into stack
	s1.push(new int(16));
	s1.push(new int(14));
	s1.push(new int(17));
	s1.push(new int(88));
	s1.push(new int(99));
	s1.push(new int(100));
	cout<<"Intially stack elements: ";
	s1.display();
	
	// pop an element from stack
	s1.pop();
	cout<<endl<<"After removing one element fronm the stack: ";
	s1.display();
}



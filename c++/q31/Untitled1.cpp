#include<iostream>

using namespace std;

struct Element{
	Element *next;
	Element *prev;
	int data;
};

class Array{
	protected:
		Element *front;
		Element *back;
		int size;
	public:
		virtual void decreaseSize() = 0;
		virtual void increaseSize() = 0;
		virtual void print() = 0;
		virtual void insert(int ) = 0;
};

// class to manage array backword direction
class manageArrayBackward : public Array{
	
	public:
		manageArrayBackward(Element *ele){
			this->front = ele;
			this->back = ele;
		}
		
		// fucntion to decrease current array size by one
		void decreaseSize(){
			if(this->front != this->back){
				this->back = this->back->next;
				this->back->prev = NULL;
			}
		}
		
		// function to increase size of current array by one
		void increaseSize(){
			Element *c = new Element();
			c->next = this->back;
			c->prev = NULL;
			this->back->prev = c;
			this->back = c;
		}
		
		// print element of current array in backword direction
		void print(){
			Element *c = this->front;
			while(c != NULL){
				printf("%d ",c->data);
				c = c->prev;
			}
			cout<<endl;
		}
		
		// insert an element at the front of array
		void insert(int n){
			this->increaseSize();
			this->back->data = n;
		}
};
// class to manage arrayforward direction
class manageArrayForward : public Array{
	
	public:
		manageArrayForward(Element *ele){
			this->front = ele;
			this->back = ele;
		}
		
		// fucntion to decrease current array size by one
		void decreaseSize(){
			while(this->front != this->back){
				this->back = this->back->prev;
				this->back->next = NULL;
			}
		}
		
		// function to increase currrent array size by one
		void increaseSize(){
			Element *c = new Element();
			c->prev = this->back;
			c->next = NULL;
			this->back->next = c;
			this->back = c;
		}
		
		// print array in forward direction
		void print(){
			Element *c = this->front;
			while(c != NULL){
				printf("%d ",c->data);
				c = c->next;
			}
			cout<<endl;
		}
		
		// insert an element at the end of the array;
		void insert(int n){
			this->increaseSize();
			this->back->data = n;
		}
};

int main(){
	Element *start = new Element();
	start->data = 0;
	
	manageArrayForward *arrayForward = new manageArrayForward(start);
	manageArrayBackward *arrayBackward = new manageArrayBackward(start);
	
	while(true){
		cout<<"\n1. insert in forward\n";
		cout<<"2. insert in backward\n";
		cout<<"3. print forward\n";
		cout<<"4. print backward\n";
		cout<<"5. decrease forward\n";
		cout<<"6. decrease backward\n";
		int o;
		cin>>o;
		if(o == 1){
			cout<<"Enter a number: ";
			int n;
			cin>>n;
			arrayForward->insert(n);
			
		}else if(o == 2){
			cout<<"Enter a number: ";
			int n;
			cin>>n;
			arrayBackward->insert(n);
			
		}else if (o == 3){
			arrayForward->print();
			
		}else if (o == 4){
			arrayBackward->print();
		}else if (o == 5){
			arrayForward->decreaseSize();
		}else if (o == 6){
			arrayBackward->decreaseSize();
		}
		
	}
}

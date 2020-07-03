
#include <iostream>
#include <sstream>
#include "Stack.cpp"
using namespace std;

template <class T>
class stackImplementation : public Stack<T>{
public:	

	// default constructor
	// create an array of template type T of default size
	// sets number of items to zero
	// sets capacity to default capacity
	stackImplementation(){
		this->items = new T[this->DEFAULT_SIZE];
		this->nOfItems = 0;
		this->capacity = this->DEFAULT_SIZE;
	}
	
	// overloaded constructor
	// create an array of template type T of given size
	// sets number of items to zero
	// sets capacity to given capacity
	stackImplementation(int cap){
		this->items = new T[cap];
		this->nOfItems = 0;
		this->capacity = cap;
	}
	
	// clear stack completely
	void clear(){
		this->nOfItems = 0;
	}
	
	// check current stack is empty or not
	// @return true if stack is empty otherwise return false
	bool isEmpty() const{
		return this->nOfItems == 0;
	}
	
	// push an item into stack
	void push(const T& newItem){
		if (this->nOfItems == this->capacity){
			return;
		}
		this->items[this->nOfItems] = newItem;
		this->nOfItems++;
	}
	
	// return top of the stack
	T top() const{
		if (isEmpty()){
			throw "Stack is empty.";
		}
		
		return this->items[this->nOfItems - 1];
	}
	
	// pop an item from stack
	void pop(){
		if(!isEmpty())
			this->nOfItems--;
	}
	
	// @return size of stack ( nnumber of items in stack)
	int size() const{
		return this->nOfItems;
	}
	
	// create a string of items and return
	string toString(){
		string res = "";
		stringstream ss;
		for (int i = 0; i < this->nOfItems; i++){
			ss.clear();
			ss<<this->items[i];
			string s;
			ss>>s;
			res += s + " ";
		}
		return res;
	}
	
private:
	T *items;
	int nOfItems;
	int capacity;
	static const int DEFAULT_SIZE = 20;
};


int main(){
	stackImplementation<int> stack_1, stack_2;
	int sum = 0;
	
	stack_1.push(1);
	stack_1.push(2);
	stack_1.push(3);
	stack_1.push(4);
	stack_1.push(5);
	stack_1.push(6);
	
	cout << "Before stack items: "<<stack_1.toString()<<endl;
	// calculate sum 
	while (!stack_1.isEmpty()) {
		int top = stack_1.top();
		stack_1.pop();
		sum += top;
		stack_2.push(top);
	}
	
	// put stack_2 items into stack_1
	while (!stack_2.isEmpty()) {
		int top = stack_2.top();
		stack_2.pop();
		stack_1.push(top);
	}
	
	cout<<"sum = "<<sum<<endl;
	cout << "After stack items: "<<stack_1.toString()<<endl;
}

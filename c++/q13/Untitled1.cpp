#include<iostream>
using namespace std;

template<typename T>
class StackInterface{
	public:
		virtual bool isEmpty() = 0;
		virtual bool isFull() = 0;
		virtual void pop() = 0;
		virtual void push(T item) = 0;
		virtual T top() = 0;
		StackInterface(){
			
		}
		virtual ~StackInterface(){
			
		}
};

template<typename T>
class stack : public StackInterface<T>{
	private:
		size_t arrayCapacity;
		const int GROWBY;
		T *items;
		const int MAX;
		size_t numItems;
		int top_position;
	public:
		//default cunstructor
		stack(int max):MAX(max),arrayCapacity(max),GROWBY(2),numItems(0),top_position(-1){
			this->items = new T[this->MAX];
		}
		
		//copy constructor
		stack(stack<T> *s): arrayCapacity(s->arrayCapacity), GROWBY(s->arrayCapacity), MAX(s->MAX), numItems(s->numItems), top_position(s->top_position) {
			this->items = new  T[this->arrayCapacity];
			for(int i=0; i<this->arrayCapacity; i++){
				this->items[i] = s->items[i];
			}
		}
		
		//function to push data into stack
		void push(T data){
			if(this->top_position+1 < arrayCapacity){
				top_position++;
				this->items[this->top_position] = data;
				this->numItems++;
			}else{
				T *newS = new T[this->arrayCapacity+this->GROWBY];
				for(int i=0;i<this->arrayCapacity;i++){
					newS[i] = this->items[i];
				}
				this->top_position++;
				this->items = newS;
				this->items[this->top_position] = data;
				this->arrayCapacity += GROWBY;
				this->numItems++;
			}
		}
		
		//get top element form stack;
		T top(){
			if(!this->isEmpty()){
				return this->items[this->top_position];
			}
			cout<<"stack is empty\n";
		}
		
		//pop top element from stack
		void pop(){
			if(!this->isEmpty()){
				this->top_position--;
				this->numItems--;
				return;
			}
			cout<<"stack is empty\n";
		}
		
		
		//return true if stack is empty otherwise return false
		bool isEmpty(){
			if(this->top_position < 0){
				return true;
			}
			return false;
		}
		
		//return true if stack is full otherwise return false
		bool isFull(){
			if(this->top_position == this->arrayCapacity-1){
				return true;
			}
			return false;
		}
		
		//return arraycapacity
		size_t getArrayCapacity(){
			return this->arrayCapacity;
		}
		
		//return number of items stored in stack;
		size_t getNumItems(){
			return this->numItems;
		}
		
		//return true if both stack is equal otherwise return false
		bool operator==(stack<T> const &s){
			if(this->arrayCapacity != s.arrayCapacity){
				return false;
			}else if(this->top_position != s.top_position){
				return false;
			}else{
				for(int i=0; i<this->arrayCapacity; i++){
					if(this->items[i] != s.items[i]){
						return false;
					}
				}
				return true;
			}
		}
		
		//destructor
		~stack(){
			cout<<"all memory reeased.\n";
			delete[] this->items;
		}
		
		//copy function to copy one stack to another stack;
		void copyFunction(stack<T> *s){
			this->arrayCapacity = s->arrayCapacity;
			this->top_position = s->top_position;
			this->numItems = s->numItems;
			this->items = new  T[this->arrayCapacity];
			for(int i=0; i<this->arrayCapacity; i++){
				this->items[i] = s->items[i];
			}
		}
};

//template funtion to print element of stack of different datatypes
template<typename T>
void print(stack<T> &s){
	while(!s.isEmpty()){
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	cout<<endl;
}

int main(){
	stack<string> stackstring(5);
	stackstring.push("str1");
	stackstring.push("str2");
	stackstring.push("str3");
	stackstring.push("str4");
	stackstring.push("str5");
	
	stack<int> stackint(5);
	stackint.push(1);
	stackint.push(2);
	stackint.push(3);
	stackint.push(4);
	stackint.push(5);
	
	stack<char> stackchar(5);
	stackchar.push('a');
	stackchar.push('b');
	stackchar.push('c');
	stackchar.push('d');
	stackchar.push('e');
	
	stack<double> stackdouble(5);
	stackdouble.push(2.3);
	stackdouble.push(32.584);
	stackdouble.push(452.547);
	stackdouble.push(79.237);
	stackdouble.push(63.987);
	
	cout<<"string stack\n";
	print(stackstring);
	
	cout<<"int stack\n";
	print(stackint);
	
	cout<<"char stack\n";
	print(stackchar);
	
	cout<<"double stack\n";
	print(stackdouble);
	
}

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// don't #include anything else!
using namespace std;

class Vec_stack : public Stack {
    //  implement it using a vector
    vector<string> items;
    int top;
public:
    //  has a default constructor that makes an empty stack
    Vec_stack(){
    	this->top = -1;
	}
	
	bool is_empty() const{
		return top == -1;
	}
	
	int size() const{
		return top+1;
	}
	
	void push(const string &x){
		this->items.push_back(x);
		this->top++;
	}
	
	void push (const vector<string> &v) {
		for (int i=0; i<v.size(); i++){
			this->items.push_back(v[i]);
			this->top++;
		}
	}
	
	void push_new(const string &s) {
		for (int i=0; i<size(); i++){
			if (items[i] == s){
				return;
			}
		}
		items.push_back(s);
		this->top++;
	}
	
	string pop(){
		if (!is_empty()){
			string t = items[top];
			items.pop_back();
			top--;
			return t;
		}
		
		return "";
	}
	
	
	vector<string> pop(int n){
		vector<string> vec;
		if (n<0){
			return vec;
		}
		for (int i=0; i<n && i<size(); i++){
			string t = items[top];
			top--;
			vec.push_back(t);
			items.pop_back();
		}
	}
	
	string peek() const {
		if (!is_empty()){
			return items[top];
		}
	}
	
}; // class Vec_stack

int main() {
    // add automated testing that tests every method in Vec_stack
    Vec_stack stack;
    // test stack.size and stack.is_empty method
    assert(stack.size() == 0);
    assert(stack.is_empty() == true);
    
    // test stack.push method
    // push three element onto stack
    stack.push("first");
    stack.push("second");
    stack.push("third");
	// test stack.peek method
    assert(stack.peek() == "third");
    assert(stack.size() == 3);
    assert(stack.is_empty() == false);
    
    // test stack.pop method
    assert(stack.pop() == "third");
    assert(stack.size() == 2);
    
    // test stack.push_new method
    stack.push_new("second");
    assert(stack.size() == 2);
    stack.push_new("third");
    assert(stack.size() == 3);
    
    // test stack.push(vector) method
    vector<string> vTemp;
    vTemp.push_back("fourth");
    vTemp.push_back("fifth");
    stack.push(vTemp);
    assert(stack.size() == 5);
    assert(stack.peek() == "fifth");
    
    // test stack.pop(int n) method
    vector<string> v = stack.pop(3);
    assert(stack.size() == 2);
    assert(v.size() == 3);
    assert(v[0] == "fifth");
    
    // test stack.pop_all() method
    stack.pop_all();
    assert(stack.is_empty() == true);
    assert(stack.size() == 0);
    
    cout << "All Vec_stack tests passed\n";
}

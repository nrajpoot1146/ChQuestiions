// stack class template

#ifndef STACK_H
#define STACK_H
#include <deque> 	// for use STL library
#include <iostream>

template <typename T>
class Stack {
	public:
		// return the top element of the Stack
		const T& top() {
			return stack.front();
		}
		
		// function to push an element onto the stack
		// add an element front of the stack
		void push(const T& pushValue) {
			stack.push_front(pushValue);
		}
		
		// function to pop an element from the stack
		// remove front element of the stack
		void pop() {
			stack.pop_front();
		}
		
		// function to check whether stack is empty or not
		// return true if stack is empty
		// otherwise return false
		bool isEmpty() const {
			return stack.empty();
		}
		
		// this function return the number of element in stack
		size_t size() const {
			return stack.size();
		}
		
	private:
		std::deque<T> stack; // deque is defined in STL template library
};

#endif

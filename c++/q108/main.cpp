
#include <iostream>
#include <string>
#include "Stack.h" // Stack class template definition

using namespace std;

template <typename T>
void testStack(
	Stack<T> & theStack, // refrence parameter to Stack<T>
	const T& value,		// intial value to push
	const T& increment, // increment to get other subsequent values
	size_t size, 		// number od items to push
	const string &stackName) { // refrence parameter to name of stack
		cout<<"\nPushing elements onto "<<stackName<<'\n'; // print message and stack name
		T pushValue(value); // initialize push value to initial value
		
		// loop for
		// push element onto Stack
		for (size_t i(0); i<size; i++){
			theStack.push(pushValue); // push element onto Stack
			cout << pushValue << ' '; // print pushed value
			pushValue += increment; // get next value to be push
		}
		
		cout<<"\n\nPopping elements from "<<stackName<<'\n'; // print message and stack name
		// pop elements from Stack
		while (!theStack.isEmpty()){
			cout << theStack.top() << ' '; // print value at top of the stack
			theStack.pop(); // remove top element
		}
		
		cout << "\nStack is empty. cannot pop."<<endl;
	}
	
int main(){
	// create a object of stack that can store value of double type
	Stack<double> doubleStack;
	const size_t doubleStackSize(5); // initialize size of stack
	// call testStack method
	testStack(doubleStack, 1.1, 1.1, doubleStackSize, "doubleStack");
	
	// create a object of stack that can store value of integer type
	Stack<int> intStack;
	const size_t intStackSize(10); // initialize size of stack
	// call testStack method
	testStack(intStack, 1, 1, intStackSize, "intStack");
}

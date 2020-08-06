#include <string>
#include <vector>
using namespace std;

class Stack {
public:
    virtual ~Stack() { }  // always include a virtual destructor in a base class
    // Pre Condition
    //    none
    // Post condition
    //    returns true if the stack is empty, and false otherwise
    virtual bool is_empty() const = 0;
    
    // Pre Condition
    //    none
    // Post Condition
    //    returns the number of elements in this stack
    virtual int size() const = 0;

    // Pre Condition
    //    none
    // Post Condition
    //    puts x on the top of the stack
    virtual void push(const string& x) = 0;

    // Pre Condition
    //    none
    // Post Condition
    //    pushes all the elements of v onto the stack; first v[0] is pushed,
    //    then v[1], etc.
    virtual void push(const vector& v) = 0;

    // Pre Condition =   //    none
    // Post Condition =  //    if x occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes x onto the stack
    virtual void push_new(const string& s) = 0;
    
    // Pre Condition =   //    !is_empty()
    // Post Condition =  //    removes and returns the top element of the stack
    virtual string pop() = 0;

    // Pre Condition  //    none
    // Post Condition
    //    if n <= 0, an empty vector is returned; otherwise, pops the first n items
    //    off the stack and returns them in a vector such that the first item of the vector
    //    is the top of the stack, the second item of the vector is the second item of the
    ///   stack, and so on; if n > size(), then all items are popped and returned
    virtual vector pop(int n) = 0;

    // Pre Condition =   //    none
    // Post Condition = //    pops all elements from the stack
    virtual void pop_all() {
        while (!is_empty()) pop();
    }

    // Pre Condition = //    !is_empty()
    // Post Condition =   //    returns a copy of the top element of the stack (without removing it)
    virtual string peek() const = 0;
};

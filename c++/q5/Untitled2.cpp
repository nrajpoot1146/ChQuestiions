#include <iostream>
#include <string>
#include "ArrayStack.h"

void stackTester(StackInterface<std::string> *stackPtr)
{
    std::string items[] = {"zero", "one", "two", "three", "four", "five"};
    std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << "Pushing " << items[i] << std::endl;
        bool success = stackPtr->push(items[i]);
        if (!success)
            std::cout << "Failed to push " << items[i] << " onto the stack." << std::endl;
    }

    std::cout << "Empty?: " << stackPtr->isEmpty() << std::endl;

    for (int i = 0; i < 5; i++) // NEEDS TO BE 5 TO AVOID ASSERT ERROR
    {
        std::cout << "Loop " << i << std::endl;
        std::cout << "peek1: " << stackPtr->peek() << std::endl;
        std::cout << "pop: " << stackPtr->pop() << std::endl;
        std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
    }
    std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
    std::cout << "pop an empty stack: " << std::endl;
    std::cout << "pop: " << stackPtr->pop() << std::endl; // nothing to pop!

    std::cout << "peek into an empty stack (should fail): " << std::endl;
    std::cout << "peek: " << stackPtr->peek() << std::endl; // nothing to peek!
} // end stackTester

int main()
{
    StackInterface<std::string> *stackPtr = new ArrayStack<std::string>();
    std::cout << "Testing the Array-Based Stack:" << std::endl;
    stackTester(stackPtr);

    return 0;
}
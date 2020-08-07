/*
 * main.cpp
 *
 *  Created on: 26-Jul-2020
 *      Author:
 */

#include <iostream>
#include "List.h"

int reserved_driver_main() {
    List l1;
    List l2;

    // test 1, insertith
    l1.insertith(1, 0);
    l1.insertith(5, 0);
    stringstream ss1;
    ss1 << l1;
    std::cout << ss1.str() << std::endl;
    if(ss1.str() == "5 -> 1 -> NULL (size: 2)"){
        std::cout << "1.1. insert ith successfully inserted; test passed" << std::endl;
    } else {
        std::cout << "1.1. insert ith did not successfully insert; test failed" << std::endl;
    }
    l1.makeEmpty();

    // test 2, remove dupes
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.remove(7);
    l1.insert(4);
    l1.insert(4);
    l1.insert(5);
    l1.removeDups();
    stringstream ss2;
    ss2 << l1;
    std::cout << ss2.str() << std::endl;
    if(ss2.str() == "5 -> 4 -> 6 -> NULL (size: 3)"){
        std::cout << "2.1. successfully removed duplicates; test passed" << std::endl;
    } else {
        std::cout << "2.1. did not successfully remove duplicates; test failed" << std::endl;
    }
    l1.makeEmpty();

    // test 3, concatenate
    l1.insert(7);
    l1.insert(6);
    l1.insert(5);
    l1.insert(4);
    l2.insert(11);
    l2.insert(10);
    l2.insert(9);
    l2.insert(8);
    l1.concatenate(l2);
    stringstream ss3;
    ss3 << l1;
    std::cout << ss3.str() << std::endl;
    if(ss3.str() == "4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> NULL (size: 8)"){
        std::cout << "3.1. successfully concatenated two lists; test passed" << std::endl;
    } else {
        std::cout << "3.1. did not successfully concatenate two lists; test failed" << std::endl;
    }
    l1.makeEmpty();
    l2.makeEmpty();

    // test 4, concatenate empty list
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.concatenate(l2);
    stringstream ss4;
    ss4 << l1;
    std::cout << ss4.str() << std::endl;
    if(ss4.str() == "7 -> 6 -> 5 -> 4 -> NULL (size: 4)"){
        std::cout << "4.1. successfully concatenated empty list; test passed" << std::endl;
    } else {
        std::cout << "4.1. did not successfully concatenate empty list; test failed" << std::endl;
    }
    l1.makeEmpty();

    return 0;
}

int main(){
	reserved_driver_main();
}



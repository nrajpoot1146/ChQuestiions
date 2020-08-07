/*
 * p025.h
 *
 *  Created on: 17-Jul-2020
 *      Author:
 */

#ifndef _P025
#define _P025
#include <iostream>
using namespace std;

class MyList {
    int value;
    MyList* next;
    MyList* last;
public:
    int length;

    /**
     * default constructor
     * set next to null;
     * set last to null;
     * set length to 0;
     */
    MyList();
    ~MyList();

    /**
     * insert val  to the beginning of the list
     */
    void prepend(int val);

    /**
	 * insert val to the end of the list
	 */
    void append(int val);

    /**
     * return the value at index ind
     * if ind out of bound return -1;
     */
    int get(int ind);

    /**
     * change the value at index int to val, and return val,
     * if ind is out of bound , return -1;
     */
    int give(int ind, int val);
};
#endif

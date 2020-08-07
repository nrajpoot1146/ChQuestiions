/*
 * P026.h
 *
 *  Created on: 24-Jul-2020
 *      Author:
 */

#ifndef _P026
#define _P026
class MyList {
    int value;
    MyList* next;
    MyList* last;
public:
    int length;
    /**
     * default constructor
     * set next to 0
     * set last to 0
     * set length to 0
     */
    MyList();
    ~MyList();

    /**
     * insert a value before first node
     */
    void prepend(int val);

    /**
     * insert a value after first node
     */
    void append(int val);

    /**
     * get val at index ind
     */
    int get(int ind);

    /**
     * set value at given index
     */
    int give(int ind, int val);

    /**
     * delete value from given index
     * return 0 if successfully deleted otherwise return -1
     */
    int del(int ind);
};
#endif

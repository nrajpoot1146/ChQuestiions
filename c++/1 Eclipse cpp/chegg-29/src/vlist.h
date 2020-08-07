/*
 * vlist.h
 *
 *  Created on: 24-Jul-2020
 *      Author:
 */

#ifndef VLIST_H_
#define VLIST_H_

#include <vector>
#include <iostream>
using namespace std;

class vlist {
public:

	// default constructor
	// print default constructor invoked
	vlist();

	// copy constructor
	// print Copy Constructor Invoked;
	vlist(vlist &);

	// returns true if empty, otherwise return false
	bool is_Empty();

	// function to search the vector iterator for an item
	// the function will return iterator to the location of the item
	// print Item Found if found
	// otherwise print Item Not Found
	vector<string>::iterator search(const string &);

	// insert a key into vector in alphabetical order
	void insert(const string &key);

	// remove a key from vector
	void remove(const string &key);

	// print item of vector
	void print();
	unsigned int getSize();

	// destructor
	// print Destructor Invoked
	virtual ~vlist();

private:
	vector<string> DB;
};

#endif /* VLIST_H_ */

/*
 * Name.h
 *
 *  Created on: 05-Aug-2020
 *      Author:
 */

#ifndef SRC_NAME_H_
#define SRC_NAME_H_
#include <iostream>
using namespace std;

class Name {
	string fname;
	string lname;
public:
	// default constructor
	// set fname and lname to empty string
	Name();

	// parameterize constructor
	// set fname and lname to given value
	Name(string fname, string lname);

	// setter for fname
	void setFname(string fname);

	// setter for lname
	void setLname(string lname);

	// getter for fname
	string getFname() const;

	// getter for lname
	string getLname() const;

	// get full name of customer
	string getFullName();

	// overloaded equality operator
	bool operator== (const Name &o);

	// overloaded assignment operator
	void operator=(Name &o);

	virtual ~Name();

	// overloaded friend function for insertion operator
	friend ostream &operator<<(ostream &os, const Name &c);
};

#endif /* SRC_NAME_H_ */

/*
 * Name.cpp
 *
 *  Created on: 05-Aug-2020
 *      Author:
 */

#include "Name.h"

// set fname and lname to empty string
Name::Name(){
	this->fname = "";
	this->lname = "";
}

// parameterize constructor
// set fname and lname to given value
Name::Name(string fname, string lname){
	this->fname = fname;
	this->lname = lname;
}

// setter for fname
void Name::setFname(string fname){
	this->fname = fname;
}

// setter for lname
void Name::setLname(string lname){
	this->lname = lname;
}

// getter for fname
string Name::getFname() const{
	return this->fname;
}

// getter for lname
string Name::getLname() const{
	return this->lname;
}

// get full name of name
string Name::getFullName(){
	return this->fname + " " + this->lname;
}

// overloaded equality operatortemplate <class T>
bool Name::operator== (const Name &o){
	return (o.fname == fname && o.lname == lname);
}

// overloaded assignment operator
void Name::operator=(Name &o){
	this->fname = o.fname;
	this->lname = o.lname;
}

Name::~Name(){}


/*
 * nodeType.h
 *
 *  Created on: 01-Jul-2020
 *      Author: naren
 */

#ifndef SRC_NODETYPE_H_
#define SRC_NODETYPE_H_

template<class Type>
class nodeType {
public:
	const nodeType<Type> &operator=(const nodeType<Type> &);
	// overload the assignment operator

	void setInfo(const Type& ele);
	// Function to set the info of the node
	//Postcondition: info = ele

	Type getInfo() const;
	// Function to return the info of the node
	// Postcondition: the value of info is returned

	void setLink(nodeType<Type> *ptr);
	// Function to set the link of the node
	// Postcondition: link = ptr


	nodeType<Type>* getLink() const;
	// Function to return the link of the node
	// Postcondition: the value of the link is returned

	nodeType();
	//Default constructor
	//Postcondition: link = NULL

	nodeType(const Type& elem, nodeType<Type> *ptr);
	//Constructor with parameters
	//Sets info point to the object elem points to and
	//link is set to point to the object ptr points to
	//Postcondition: info = elem; link = ptr

	nodeType(const nodeType<Type> &otherNode);
	//Copy constructor

	virtual ~nodeType();

private:
	Type info;
	nodeType<Type> *link;
};

#endif /* SRC_NODETYPE_H_ */

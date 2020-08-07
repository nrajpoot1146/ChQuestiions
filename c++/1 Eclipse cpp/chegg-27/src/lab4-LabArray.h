/*
 * lab4-LabArray.h
 *
 *  Created on: 21-Jul-2020
 *      Author:
 */

#ifndef SRC_LAB4_LABARRAY_H_
#define SRC_LAB4_LABARRAY_H_


class LabArray {
  protected:
   int *data;
   int size, capacity;

  public:
   virtual int getVal(int) = 0;
   virtual int getCapacity() = 0;
   virtual int getSize() = 0;
   virtual void insertVal(int) = 0;
   virtual int removeVal() = 0;
};


class IntArr : public LabArray{
public:

	/**
	 * default constructor
	 * sets capacity 0
	 * sets size 0;
	 * sets data array NULL
	 */
	IntArr();

	/**
	 * user constructor
	 * sets capacity to given capacity
	 * sets size to 0
	 * create a dynamic array of given capacity
	 * @param capacity size of an array
	 */
	IntArr(int capacity);

	/**
	 * get value at given index
	 */
	int getVal(int);

	/**
	 * get max capacity of array
	 */
	int getCapacity();

	/**
	 * get current number of elements in array
	 */
	int getSize();

	/**
	 * insert value at the end of last element
	 */
	void insertVal(int);

	/**
	 * remove last element of array
	 */
	int removeVal();

	virtual ~IntArr();
};


#endif /* SRC_LAB4_LABARRAY_H_ */

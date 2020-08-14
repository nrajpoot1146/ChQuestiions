
#ifndef _UNSORTEDLIST_CPP_
#define _UNSORTEDLIST_CPP_
#include <iostream>

template<class T>
class UnsortedList {
	T *data;
	int MAX_CAPACITY;
	int size;
	public:
		
		// constructor with single parameter
		// max cap capacity of list
		// set initial size (length) to 0
		UnsortedList(int cap) {
			MAX_CAPACITY = cap;
			size = 0;
			data = new T[cap];
		}
		
		// overloaded copy constructor
		UnsortedList(UnsortedList &list) {
			(*this) = list;
		}
		
		// overloaded assignment operator
		void operator=(UnsortedList &list) {
			MAX_CAPACITY = list.MAX_CAPACITY;
			size = list.size;
			data = new T[MAX_CAPACITY];
			for (int i=0; i<list.size; i++) {
				this->data[i] = list.data[i];
			}
		}
		
		// delete an given item from the list
		void deleteItem(const T &item) {
			if (isEmpty())
				return;
			for (int i=0; i<this->size; i++) {
				if (this->data[i] == item) {
					for (int j=i; j<this->size-1; j++) {
						this->data[j] = this->data[j+1];
					}
					break;
				}
			}
			size--;
		}
		
		// insert given item into the list
		void insertItem(const T &item) {
			if (isFull()){
				return;
			}
			
			this->data[size] = item;
			this->size++;
		}
		
		// check list is full or not
		// return true if list is full otherwise return false
		bool isFull() const{
			return this->size == this->MAX_CAPACITY;
		}
		
		// check list is empty or not 
		// return true if list is empty otherwise return false
		bool isEmpty() const{
			return this->size == 0;
		}
		
		// make current list is empty
		// set size to 0
		void makeEmpty() {
			this->size = 0;
		}
		
		// get length of current list
		int getLength() const{
			return this->size;
		}
		
		// search a given item
		// if item is present return true otherwise return false
		bool searchItem(const T &item) {
			if (isEmpty()) {
				return false;
			}
			for (int i=0; i<this->size; i++) {
				if (this->data[i] == item) {
					return true;
				}
			}
			return false;
		}
		
		// print list items of unordered list
		// if list is empty then print nothing
		void printList() {
			if (isEmpty()) {
				return;
			}
			for (int i=0; i<this->size; i++) {
				std::cout<<data[i]<<" ";
			}
		}
		
		// print sorted list without change main list
		// use bubble sort algorithm
		void printListSorted() {
			UnsortedList l2 = (*this);
			for (int i=0; i<l2.size-1; i++){
				for (int j=0; j<l2.size-i-1; j++) {
					if (l2.data[j+1] < l2.data[j]) {
						int temp = l2.data[j];
						l2.data[j] = l2.data[j+1];
						l2.data[j+1] = temp;
					}
				}
			}
			
			for (int i=0; i<l2.size; i++) {
				std::cout<<l2.data[i]<<" ";
			}
		}
		
		// default destructor
		~UnsortedList() {
			delete[] data;
		}
		
};

#endif

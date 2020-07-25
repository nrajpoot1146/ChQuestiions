
#ifndef _IntArr_
#define  _IntArr_
#include <iostream>
using namespace std;
class IntArr{
	int capacity, size, *array;
	public:
		IntArr(){
			this->capacity = 0;
			this->size = 0;
			this->array = NULL;
		}
		
		IntArr(int capacity){
			this->capacity = capacity;
			this->size = 0;
			this->array = new int[this->capacity];
		}
		
		int operator[](int index){
			if (index < this->size){
				return this->array[index];
			}
		}
		
		IntArr(const IntArr &o){
			this->capacity = o.capacity;
			this->size = o.size;
			this->array = new int[this->capacity];
			for (int i=0; i<o.size; i++){
				this->array[i] = o.array[i];
			}
		}
		
		void operator=(const IntArr &o){
			this->capacity = o.capacity;
			this->size = o.size;
			this->array = new int[this->capacity];
			for (int i=0; i<o.size; i++){
				this->array[i] = o.array[i];
			}
		}
		
		void grow(){
			int *newArray = new int[this->capacity * 2];
			for (int i=0; i<this->size; i++){
				newArray[i] = this->array[i];
			}
			this->capacity *= 2;
			delete[] this->array;
			this->array = newArray;
		}
		
		void push_back(int i){
			if (this->size == this->capacity){
				grow();
			}
			this->array[this->size] = i;
			this->size++;
		}
		
		int pop_back(){
			if (this->size != 0){
				this->size--;
				return this->array[this->size];
			}
		}
		
		int getSize(){
			return this->size;
		}
};

#endif

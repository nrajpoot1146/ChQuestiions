#include <iostream>
using namespace std;

template <class T>
class dynamicArray{
	T *array;
	int size;
	
	public:
		
		// default constructor
		// set data array to null
		// set size to 0
		dynamicArray();
		
		// overloaded copy constructor
		// copy another dynamic array to this array
		dynamicArray(dynamicArray &oa);
		
		// get number of entry in dynnamic array
		int getSize();
		
		// add a entry to dynamic array
		void addEntry(T entry);
		
		// delete a given entry from dynamic array
		// if entry is not found return false, otherwise return true
		bool deleteEntry(T entry);
		
		// get an entry at given index
		// if index is greater then size return null
		T getEntry(int index);
		
		// overloaded assignment operator
		dynamicArray &operator= (dynamicArray &oa);
		
		// default destructor
		// delete all allocated memory
		~dynamicArray();
};

template <class T>
dynamicArray<T>::dynamicArray(){
	this->array = NULL;
	this->size = 0;
}

template <class T>
dynamicArray<T>::dynamicArray(dynamicArray &oa){
	delete[] this->array;
	this->array = new T[oa.size];
	for (int i=0; i<oa.getSize(); i++){
		this-array[i] = oa.array[i];
	}
}

template <class T>
int dynamicArray<T>::getSize(){
	return this->size;
}

template <class T>
void dynamicArray<T>::addEntry(T entry){
	T *newArray = new T[this->size + 1];
	for (int i=0; i<this->size; i++){
		newArray[i] = this->array[i];
	}
	delete[] this->array;
	newArray[this->size] = entry;
	this->size++;
	this->array = newArray;
}

template <class T>
bool dynamicArray<T>::deleteEntry(T entry){
	int fIndex = -1;
	for(int i=0; i<this->size; i++){
		if (this->array[i] == entry){
			fIndex = i;
			break;
		}
	}
	
	if (fIndex == -1){
		return false;
	}
	
	T *newArray = new T[this->size-1];
	for (int i=0, j=0; i<this->size; i++){
		if (i == fIndex){
			continue;
		}
		
		newArray[j] = this->array[i];
		j++;
	}
	delete[] this->array;
	this->array = newArray;
	this->size--;
	return true;
}

template <class T>
T dynamicArray<T>::getEntry(int index){
	if (index < this->size){
		return this->array[index];
	}
	return NULL;
}

template <class T>
dynamicArray<T> &dynamicArray<T>::operator= (dynamicArray &oa){
	delete[] this->array;
	this->array = new T[oa.size];
	for (int i=0; i<oa.getSize(); i++){
		this-array[i] = oa.array[i];
	}
	return *this;
}

template <class T>
dynamicArray<T>::~dynamicArray(){
	delete[] this->array;
}

// overloaded insertion operator
// display all entry
template <class T>
ostream& operator<<(ostream &os, dynamicArray<T> &da){
	os<<"current array size: "<<da.getSize()<<endl;
	os<<"current list: ";
	if (da.getSize() == 0){
		os<<"Empty!"<<endl;
		return os;
	}
	
	for (int i=0; i<da.getSize(); i++){
		os<<da.getEntry(i);
		if(i != da.getSize() - 1){
			os<<", ";
		}
	}
	
	return os;
}


// test main function
int main(){
	dynamicArray<string> da;
	cout<<da;
	
	cout<<"\nAdd Hello"<<endl;
	da.addEntry("Hello");
	cout<<da<<endl;
	
	cout<<"\nAdd Bye"<<endl;
	da.addEntry("Bye");
	cout<<da<<endl;
	
	cout<<"\nAdd Good"<<endl;
	da.addEntry("Good");
	cout<<da<<endl;
	
	cout<<"\nDelete Bye"<<endl;
	if (da.deleteEntry("Bye"))
		cout<<da<<endl;
	else
		cout<<"Not found!\n";
	
	cout<<"\nDelete Bye"<<endl;
	if (da.deleteEntry("Bye"))
		cout<<da<<endl;
	else
		cout<<"Not found!\n";
}

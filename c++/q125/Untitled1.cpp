// main.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class template that represent a set of items
// set has no common items
template <class T>
class Items{
	vector<T> items; // vector to store items
	public:
		
		// function to add an item to items vector
		void add(T item){
			cout<<"Adding: "<<item<<"\n";
			// check this class already has an item or not
			if (find(items.begin(), items.end(), item) != items.end()){
				// if yes do noothing
				return;
			}
			// if no add item into vector
			items.push_back(item);
		}
		
		// get number of items
		int getNumberOfItems(){
			return this->items.size();
		}
		
		// get pointer to an array that contains each items of set
		T *getPointerOfArray(){
			T *temp = new T[this->getNumberOfItems()];
			for (int i=0; i<this->getNumberOfItems(); i++){
				temp[i] = this->items[i];
			}
			return temp;
		}
};

// class Customer 
// this class is defined for point 5.d of your question
class Customer{
	string fname;
	string lname;
	public:
		// default constructor
		// set fname and lname to empty string
		Customer(){
			this->fname = "";
			this->lname = "";
		}
		
		// parameterize constructor
		// set fname and lname to given value
		Customer(string fname, string lname){
			this->fname = fname;
			this->lname = lname;
		}
		
		// setter for fname
		void setFname(string fname){
			this->fname = fname;
		}
		
		// setter for lname
		void setLname(string lname){
			this->lname = lname;
		}
		
		// getter for fname
		string getFname() const{
			return this->fname;
		}
		
		// getter for lname
		string getLname() const{
			return this->lname;
		}
		
		// get full name of customer
		string getFullName(){
			return this->fname + " " + this->lname;
		}
		
		// overloaded equality operator
		bool operator== (const Customer &o){
			return (o.fname == fname && o.lname == lname);
		}
		
		// overloaded assignment operator
		void operator=(Customer &o){
			this->fname = o.fname;
			this->lname = o.lname;
		}
		
		// overloaded friend function for insertion operator
		friend ostream &operator<<(ostream &os, const Customer &c);
};

ostream &operator<<(ostream &os, const Customer &c){
	cout<<c.fname<<" "<<c.lname;
}

// template function to print an given array
template <class T>
void printArray(const T *array, const int &size) {
	for (int i=0; i<size; i++){
		cout<<"\t"<<array[i]<<"\n";
	}
	cout<<endl;
}

int main(){
	
	// Items object for integer, point 5.a
	Items<int> intItems;
	cout<<"---------------------------------\n";
	cout<<"---Example 1: sets of integers---\n";
	cout<<"---------------------------------\n";
	intItems.add(10);
	intItems.add(5);
	intItems.add(15);
	intItems.add(25);
	intItems.add(15);
	cout<<"---------------------------------\n";
	
	int *intArray = intItems.getPointerOfArray();
	cout<<"The first set has "<<intItems.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(intArray, intItems.getNumberOfItems());
	delete[] intArray;
	
	// Items object for double, point 5.b
	Items<double> doubleItems;
	cout<<"--------------------------------\n";
	cout<<"---Example 2: sets of doubles---\n";
	cout<<"--------------------------------\n";
	doubleItems.add(1.5);
	doubleItems.add(5.6);
	doubleItems.add(12.8);
	doubleItems.add(1.5);
	doubleItems.add(12.8);
	cout<<"---------------------------------\n";
	
	double *doubleArray = doubleItems.getPointerOfArray();
	cout<<"The second set has "<<doubleItems.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(doubleArray, doubleItems.getNumberOfItems());
	delete[] doubleArray;
	
	// Items object for string, point 5.c
	Items<string> stringItems;
	cout<<"--------------------------------\n";
	cout<<"---Example 3: sets of strings---\n";
	cout<<"--------------------------------\n";
	stringItems.add("John Smith");
	stringItems.add("Jane doe");
	stringItems.add("John Smith");
	stringItems.add("Jack black");
	cout<<"--------------------------------\n";
	
	string *stringArray = stringItems.getPointerOfArray();
	cout<<"The third set has "<<stringItems.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(stringArray, stringItems.getNumberOfItems());
	delete[] stringArray;
	
	// Items object for Customer, point 5.d
	Items<Customer> customerItems;
	cout<<"----------------------------------------\n";
	cout<<"---Example 4: sets of Custommer names---\n";
	cout<<"----------------------------------------\n";
	Customer c1("John", "Rick");
	customerItems.add(c1);
	Customer c2("Ram", "Singh");
	customerItems.add(c2);
	Customer c3("Rohan", "Kumar");
	customerItems.add(c3);
	cout<<"---------------------------------------\n";
	
	Customer *customerArray = customerItems.getPointerOfArray();
	cout<<"The fourth set has "<<customerItems.getNumberOfItems()<<" items\n";
	cout<<"They are: \n";
	printArray(customerArray, customerItems.getNumberOfItems());
	delete[] customerArray;
}


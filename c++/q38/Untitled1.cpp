#include<iostream>
#include<string>
using namespace std;

// customer structure to store customer information
struct Customer{
	
	// Address structure to store adrress information
	struct Address{
		string street;
		string city;
		string state;
		string zip;
	};
	string lastNm;
	string firstNm;
	Address homAddr;
	Address busAddr;
};

// prototypes of function
/**
* function to display menu
* return int
*/
int displayMenu();

/**
* function to get a customer information from user
* all information of customer stored in a Customer structure;
* @return customer structure variable
*/
Customer getCustomer();

/**
* function to get Address information formm user
* all information of address stored in a Address structure
* @return address structure variable 
*/
Customer::Address getAddress();

/**
* print all information of single customer
*/
void showCustomer(Customer);

/**
* find a cutomer by his first name and last name
* if customer is find successfully print customer details otherwise print error
*/
void findCustomer(Customer[],int);


/**
* a driver main function
*/
int main(){
	int max_size = 8;
	Customer customers[max_size]; // array of Customer size of max_size;
	int n = 0; // number of customer stored in array;
	
	while(true){
		displayMenu();
		string op;
		getline(cin, op); // read option choose by user
		
		if(op == "a"){
			if(n<max_size){
				Customer c = getCustomer(); // get new customer 
				customers[n] = c; // stored new cutomer in customers array
				n++;
			}
		}else if(op == "b"){
			// show all cutomers details stored in customer array
			for (int i=0; i<n; i++){
				showCustomer(customers[i]);
			}
		}else if(op == "c"){
			// find and show specific customer details
			findCustomer(customers,n);
		}else if(op == "d"){
			// exit program
			break;
		}
	}
}

/**
* display menu item on comsole window
* @return 1
*/
int displayMenu(){
	cout<<endl;
	cout<<"Menu:"<<endl;
	cout<<"a. Enter new customer\n";
	cout<<"b. Display all customer\n";
	cout<<"c. Display a particular customer\n";
	cout<<"d. Exit the program\n";
}

Customer getCustomer(){
	Customer customer;
	
	cout<<"Enter customer first name: ";
	getline(cin, customer.firstNm);
	
	cout<<"Enter customer last name: ";
	getline(cin, customer.lastNm);
	
	cout<<endl;
	cout<<"Home Address:\n";
	customer.homAddr = getAddress();
	
	cout<<endl;
	cout<<"Business Address:\n";
	customer.busAddr = getAddress();
	
	return customer;
}

void showCustomer(Customer customer){
	cout<<endl;
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-";
	cout<<endl;
	cout<<"FirstName: "<<customer.firstNm<<endl;
	cout<<"Lastname: "<<customer.lastNm<<endl;
	cout<<"Home Address: \n";
	cout<<"\tStreet: "<<customer.homAddr.street<<endl;
	cout<<"\tcity: "<<customer.homAddr.city<<endl;
	cout<<"\tstate: "<<customer.homAddr.state<<endl;
	cout<<"\tzip: "<<customer.homAddr.zip<<endl;
	cout<<"Business Address: \n";
	cout<<"\tStreet: "<<customer.busAddr.street<<endl;
	cout<<"\tcity: "<<customer.busAddr.city<<endl;
	cout<<"\tstate: "<<customer.busAddr.state<<endl;
	cout<<"\tzip: "<<customer.busAddr.zip<<endl;
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-";
	cout<<endl;
}

Customer::Address getAddress(){
	Customer::Address address;
	
	cout<<"Enter street: ";
	getline(cin, address.street);

	cout<<"Enter city: ";
	getline(cin, address.city);
	
	cout<<"Enter state: ";
	getline(cin, address.state);
	
	cout<<"Enter zip: ";
	getline(cin, address.zip);
	
	return address;
}

void findCustomer(Customer customers[], int n){
	string fname,lname;
	cout<<"Enter customer first name: ";
	getline(cin,fname);
	
	cout<<"Enterr customer last name: ";
	getline(cin,lname);
	
	for (int i = 0; i<n; i++){
		if(customers[i].firstNm == fname && customers[i].lastNm == lname){
			showCustomer(customers[i]);
			return;
		}
	}
	
	cout<<"error: customer not found!\n";
}

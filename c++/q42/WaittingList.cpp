#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>

using namespace std;

bool compare(Customer c1, Customer c2){
	return (c1.getAge() > c2.getAge());
}

/**
* Witting list class to maintaing line of customer
*/
class WaittingList{
	vector<Customer> wlist;
	public:
		
		/**
		* fucntion to read customer data from file
		* and store in vector array
		*/
		void readFromFile(){
			ifstream fin;
			fin.open("input.txt");
			
			while(fin){
				string line;
				getline(fin,line);
				if(line=="")
					break;
				string name = line.substr(0, line.find(","));
				line = line.substr(line.find(",")+1);
				string operation = line.substr(0, line.find(","));
				line = line.substr(line.find(",")+1);
				double money;
				stringstream ss(line.substr(0, line.find(",")));
				ss>>money;
				line = line.substr(line.find(",")+1);
				int age;
				stringstream ss1(line.substr(0, line.find(",")));
				ss1>>age;
				
				Customer customer(name, operation, money, age);
				this->wlist.push_back(customer);
			}
		}
		
		/**
		* sort waitting list by age
		*/
		void SortByAge(){
			sort(this->wlist.begin(), this->wlist.end(), compare);
		}
		
		/**
		* add a customer to waitting list
		*/
		void addCustomer(Customer c){
			this->wlist.push_back(c);
			this->SortByAge();
		}
		
		/**
		* remove oldest customer from waitting list
		*/
		void removeOldest(){
			this->wlist.erase(this->wlist.begin());
		}
		
		/**
		* print customer from waitting list
		*/
		void print(){
			int i=0;
			while(i < this->wlist.size()){
				cout<<endl;
				wlist.at(i).print();
				i++;
			}
		}
		
		/**
		* @return oldest customer from waitting list
		*/
		Customer getOldest(){
			Customer c = this->wlist.at(0);
			return c;
		}
		
		/**
		* size of waitting list
		*/
		int size(){
			return this->wlist.size();
		}
};

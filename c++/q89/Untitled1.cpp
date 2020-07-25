
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Pizza class
class Pizza {
	private:
		string size;
		string type;
		vector<string> toppings;
		double price;
		
		// calculate price of current pizza
		void calPrice(){
			if (this->size == "Small"){
				this->price += 10.00;
			}else if(this->size == "Medium"){
				this->price += 14.00;
			}else if(this->size == "Large"){
				this->price += 17.00;
			}
			
			for (int i=0; i<this->toppings.size(); i++){
				this->price += 2.00;
			}
		}
		
	public:
		// user constructor
		// set Pizza info to given info
		Pizza(string size, string type, vector<string> top){
			this->size = size;
			this->type = type;
			this->toppings = top;
			this->price = 0.0;
			this->calPrice();
		}
		
		// get size of pizza
		string getSize(){
			return this->size;
		}
		
		// get type of pizza
		string getType(){
			return this->type;
		}
		
		// get toppings of pizza
		vector<string> getToppings() const{
			return this->toppings;
		}
		
		// get price of pizza
		double getPrice(){
			return this->price;
		}
		
		// overloaded insertion operator
		// display pizza info
		friend ostream &operator<< (ostream &os, const Pizza &p){
			os<<"Your ordered a "<<p.size<<" "<<p.type<<" with ";
			for (int i=0; i<p.toppings.size(); i++){
				os<<p.toppings[i];
				if (i != p.toppings.size()-1){
					os<<", ";
				}
			}
			os<<endl<<"Pizza Price: $ "<<fixed<<setprecision(2)<<p.price;
			os<<endl;
		}
};

// DeliveredPizza class
// derived class of Pizza class
class DeliveredPizza : public Pizza{
	double delFee;
	double totalPrice;
	string delAddress;
	public:
		// user constructor
		// call parent contsructor
		DeliveredPizza(string size, string type, vector<string> top,string delAddress) : Pizza(size, type, top){
			this->delAddress = delAddress;
			if (Pizza::getPrice() > 20){
				this->delFee = 3.50;
			} else {
				this->delFee = 5.00;
			}
			this->totalPrice = Pizza::getPrice() + delFee;
		}
		
		// overloaded insertion operator;
		// print info of DeliveredPizza
		friend ostream &operator<< (ostream &os, const DeliveredPizza &p){
			Pizza pizza = (Pizza) p;
			os<<pizza;
			os<<"Delivery fee: $ "<<fixed<<setprecision(2)<<p.delFee<<endl;
			os<<"Total price: $ "<<fixed<<setprecision(2)<<p.totalPrice<<endl;
			os<<"Delivery address: "<<p.delAddress<<endl;
		}
};

// function to read pizaa info from user
void askUser(string &size, string &type, string &address, vector<string> &top){
	string toppings[] = {"Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};
	int op;
	
	// read size of pizza
	while (true) {
		cout<<"What size pizza would you like to order?\n";
		cout<<"1 - Small\n";
		cout<<"2 - Medium\n";
		cout<<"3 - Large\n";
		cout<<"----> ";
		cin>>op;
		if (op < 1 || op >3){
			cout<<"Error: Invalid option!"<<endl;
			continue;
		} else if(op == 1){
			size = "Small";
		} else if(op == 2){
			size = "Medium";
		} else if(op == 3){
			size = "Large";
		}
		break;
	} 
	
	// read type of crust
	while (true) {
		cout<<"What type of crust would you like to order?\n";
		cout<<"1 - Classic\n";
		cout<<"2 - Deep Dish\n";
		cout<<"3 - Thin Crust\n";
		cout<<"----> ";
		cin>>op;
		if (op < 1 || op >3){
			cout<<"Error: Invalid option!"<<endl;
			continue;
		} else if(op == 1){
			type = "Classic";
		} else if(op == 2){
			type = "Deep Dish";
		} else if(op == 3){
			type = "Thin Crust";
		}
		break;
	}
	
	// read toppings
	do {
		cout<<"Choose from the following toppings or 0 to quit\n";
		for (int i=0; i<6; i++){
			cout<<i+1<<": "<<toppings[i]<<endl;
		}
		cout<<"----> ";
		cin>>op;
		if (op < 0 || op > 6){
			cout<<"Error: Invalid option!"<<endl;
			continue;
		}
		
		if (op != 0){
			top.push_back(toppings[op-1]);
		}
	} while (op != 0);
	
	
	cout<<"Would you like 1 - pick up or 2 - delivery? ";
	cin>>op;
	if(op == 2){
		cout<<"Enter your address to deliver: ";
		cin.ignore();
		getline(cin, address);
	}else {
		address = "";
	}
}

int main(){
	string size;
	string type;
	string address;
	vector<string> top;
	
	askUser(size, type, address, top);
	
	if (address == ""){
		Pizza p(size, type, top); // create object of pizza
		cout<<p; // print pizza info
	}else {
		DeliveredPizza dp(size, type, top, address); // create object of DeliveredPizza
		cout<<dp; // display info of delivered pizza
	}
}

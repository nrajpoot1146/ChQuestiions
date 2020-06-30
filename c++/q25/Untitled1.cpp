#include<iostream>
#include<string>

using namespace std;

//Inventory class
class Inventory{
	private:
		string code;
		int quantity;
		double cost;
		
	public:
		Inventory(string code){
			this->quantity = 0;
			this->code = code;
			this->cost = 0;
		}
		
		Inventory(){
			this->code = "";
			this->cost = 0;
			this->quantity = 0;
		}
		
		//return item code
		string getItemCode(){
			return this->code;
		}
		
		//return item quantity
		int getItemQuantity(){
			return this->quantity;
		}
		
		//return item cost
		double getItemCost(){
			return this->cost;
		}
		
		//set item code
		void setItemCode(string code){
			this->code = code;
		}
		
		//set item quantity
		void setItemQuantity(int quantity){
			this->quantity = quantity;
		}
		
		// set item cost
		void setItemCost(double cost){
			this->cost = cost;
		}
		
		// add two inventory item 
		Inventory& operator +(Inventory &i) const{
			static Inventory inew;
			inew.code = this->code;
			inew.quantity = this->quantity + i.quantity;
			
			inew.cost = ( (this->cost * this->quantity) + (i.cost * i.quantity) ) / (this->quantity + i.quantity);
			return inew;
		}
		
		//preincrement operator overloading
		Inventory& operator ++(){
			++this->quantity;
			return *this;
		}
		
		//post increment operator overloading
		Inventory& operator ++(int){
			this->quantity++;
			return *this;
		}
		
		//pre decrement operator overloading
		Inventory& operator --(){
			--this->quantity;
			this->quantity = this->quantity < 0 ? 0 : this->quantity;
			return *this;
		}
		
		//post decrement operator overloading
		Inventory& operator --(int){
			this->quantity--;
			this->quantity = this->quantity < 0 ? 0 : this->quantity;
			return *this;
		}
		
		//insertion operator using friend function
		friend ostream& operator<<(ostream& os, const Inventory &i){
			os<<"Item code: "<<i.code<<endl;
			os<<"Quantity : "<<i.quantity<<endl;
			os<<"Cost     : "<<i.cost<<endl;
			return os;
		}	
};

Inventory& operator -(Inventory &i1, Inventory &i2){
	static Inventory inew;
	inew.setItemCode(i1.getItemCode());
	inew.setItemCost(i1.getItemCost());
	inew.setItemQuantity(i1.getItemQuantity() - i2.getItemQuantity());
	if(inew.getItemQuantity() < 0){
		inew.setItemQuantity(0);
	}
	return inew;
}

bool operator ==(Inventory &i1, Inventory &i2){
	if(i1.getItemCode() == i2.getItemCode() && i1.getItemCost() == i2.getItemCost() && i1.getItemQuantity() == i2.getItemQuantity()){
		return true;
	}
	return false;
}



int main(){
	Inventory o1,o2,o3;
	
	o1.setItemCode("SP-001");
	o1.setItemQuantity(15);
	o1.setItemCost(9.99);
	
	o2.setItemCode("SP-001");
	o2.setItemQuantity(15);
	o2.setItemCost(18.99);
	
	o3.setItemCode("SP-001");
	o3.setItemQuantity(19);
	o3.setItemCost(9.99);
	
	cout<<"Inventory 1. \n"<<o1<<endl;
	cout<<"Inventory 2. \n"<<o2<<endl;
	cout<<"Inventory 3. \n"<<o3<<endl;
	
	cout<<"Adition operator\n";
	Inventory inew = (o1+o2);
	cout<<"new Inventory after addition operation\n";
	cout<<inew;
	
	cout<<endl;
	cout<<"pre increment operation\n";
	cout<<"before: \n";
	cout<<o1;
	cout<<endl;
	cout<<"After: \n";
	cout<<++o1;
	
	cout<<endl;
	cout<<"post increment operation\n";
	cout<<"before: \n";
	cout<<o1;
	cout<<endl;
	cout<<"After: \n";
	cout<<o1++;
	
	cout<<endl;
	cout<<"pre decrement operation\n";
	cout<<"before: \n";
	cout<<o1;
	cout<<endl;
	cout<<"After: \n";
	cout<<--o1;
	
	cout<<endl;
	cout<<"post decrement operation\n";
	cout<<"before: \n";
	cout<<o1;
	cout<<endl;
	cout<<"After: \n";
	cout<<o1--;
	
	cout<<endl;
	cout<<"Substraction operation o3-o1\n"<< (o3-o1);
	
	cout<<endl;
	cout<<"Equality operator o1 == o3";
	cout<<endl;
	if(!(o1==o3)){
		cout<<"passed";
	}else{
		cout<<"failed";
	}
	
}

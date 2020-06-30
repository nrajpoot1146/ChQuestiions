#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

struct Package{
	int weight;
	int id;
};

class DeliveryTruck{
	private:
		string adv;
		int weight;
		int totalweight;
		vector<Package> packages;
	public:
		DeliveryTruck(){

		}
		DeliveryTruck(string adv, int weight):adv(adv), weight(weight){

		}

		void print(){
			cout<<"Advertising : "<<this->adv<<endl;
			cout<<"Packages : "<<endl;
			for (int i = 0; i< this->packages.size(); i++ ){
				cout<<"ID : "<< this->packages.at(i).id<<" Weight : "<<this->packages.at(i).id<<endl;
			}
		}

		void setAdvertising(string str){
			this->adv = str;

		}

		void readFromFile(){
			ifstream fin;
			fin.open("pkg.txt");
			int i = 0;
			while(fin){
				string line;
				getline(fin, line);
				line.su
				stringstream ss(line)
				i++;
				Package p;
				p.id = i;
				ss>>p.weight;
			}
		}

		int getWeight(){
			return this->weight;
		}

		int getTotalweight(){
			return this->totalweight;
		}
};


void printMenu(){

}

int main(){
	char c;

	do{
		printMenu();
		cin>>c;
	}while(c!='q');
}

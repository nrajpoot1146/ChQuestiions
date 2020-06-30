#include<iostream>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

class Passenger{
	private:
		string fname;
		string sname;
		string destination;
		
	public:
		Passenger(string fname, string sname, string destination):fname(fname),sname(sname),destination(destination){
			
		}
		
		Passenger(string str){
			this->fname = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ')+1);
			this->sname = str.substr(0, str.find(' '));
			this->destination = str.substr(str.find(' ')+1);
		}
		
		void print(){
			cout<<this->fname<<" "<<this->sname<<" "<<this->destination<<endl;
		}
		string getFname(){
			return this->fname;
		}
		string getSname(){
			return this->sname;
		}
		string getDestination(){
			return this->destination;
		}
		
		string toString(){
			return this->fname+" "+this->sname+" "+this->destination;
		}
};

int main(){
	ifstream fin;
	queue<Passenger*> passengers;
	stack<Passenger*> istanbulStack, ankaraStack, adanaStack;
	int istanbulTrainCapacity, ankaraTrainCapacity, adanaTrainCapacity;
	bool istanbulFlag = true, ankaraFlag = true, adanaFlag = true;
	
	cout<<"Enter Istanbul Train capacity(max): ";
	cin>>istanbulTrainCapacity;
	cout<<"Enter Ankara Train capacity(max): ";
	cin>>ankaraTrainCapacity;
	cout<<"Enter Adana Train capacity(max): ";
	cin>>adanaTrainCapacity;
	
	fin.open("passenger.txt");
	
	while(fin){
		string line;
		getline(fin,line);
		Passenger *p = new Passenger(line);
		passengers.push(p);
	}
	
	while(passengers.size() > 0){
		Passenger *p = passengers.front();
		if(p->getDestination() == "Istanbul" && istanbulFlag){
			if(istanbulStack.size() < istanbulTrainCapacity){
				istanbulStack.push(p);
			}else{
				cout<<"Istanbul train has fulled."<<endl;
				istanbulFlag = false;
			}
		}else if(p->getDestination() == "Ankara" && ankaraFlag){
			if(ankaraStack.size() < ankaraTrainCapacity){
				ankaraStack.push(p);
			}else{
				cout<<"Ankara train has fulled."<<endl;
				ankaraFlag = false;
			}
		}else if(p->getDestination() == "Adana" && adanaFlag){
			if(adanaStack.size() < adanaTrainCapacity){
				adanaStack.push(p);
			}else{
				cout<<"Adana train has fulled."<<endl;
				adanaFlag = false;
			}
		}
		passengers.pop();
	}
	
	ofstream istanbulFile, ankaraFile, adanaFile;
	istanbulFile.open("istanbul.txt");
	ankaraFile.open("anakara.txt");
	adanaFile.open("adana.txt");
	
	while(istanbulStack.size() > 0){
		Passenger *p = istanbulStack.top();
		istanbulFile<<p->toString()<<endl;
		istanbulStack.pop();
	}
	
	while(ankaraStack.size() > 0){
		Passenger *p = ankaraStack.top();
		ankaraFile<<p->toString()<<endl;
		ankaraStack.pop();
	}
	
	while(adanaStack.size() > 0){
		Passenger *p = adanaStack.top();
		adanaFile<<p->toString()<<endl;
		adanaStack.pop();
	}
	
	istanbulFile.close();
	ankaraFile.close();
	adanaFile.close();
	fin.close();
	cout<<endl;
	cout<<"===================================="<<endl;
	cout<<"Passengers distrinuted successfully."<<endl;
	cout<<"===================================="<<endl<<endl;
}

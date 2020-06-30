#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

struct model_details{
	string brand;
	string type;
	int id;
};

struct vehicle{
	int year;
	double price;
	struct model_details model;
};

//function to convert a string to a integer number
int stringtointeger(string str){
	stringstream ss(str);
	int num;
	ss>>num;
	return num;
}

//function to read data from file
void readFile(struct vehicle v[],int n){
	ifstream file;
	file.open("vehicle.txt");
	int i=0;
	while(i<n){
		string line;
		getline(file, line);
		
		string word = line.substr(0,line.find('\t'));
		
		if(word == "Brand"){
			continue;
		}
		v[i].model.brand = word;
		
		line = line.substr(line.find('\t')+1);
		word = line.substr(0,line.find('\t'));
		v[i].model.type = word;
		
		line = line.substr(line.find('\t')+1);
		word = line.substr(0,line.find('\t'));
		v[i].model.id = stringtointeger(word);
		
		line = line.substr(line.find('\t')+1);
		word = line.substr(0,line.find('\t'));
		v[i].year = stringtointeger(word);
		
		line = line.substr(line.find('\t')+1);
		word = line.substr(0,line.find('\t'));
		v[i].price = stringtointeger(word);
		i++;
		
	}
	file.close();
}

//function to display menu;
void menu(){
	cout<<"Enter your choice "<<endl;
	cout<<"Enter 1 to display deatils"<<endl;
	cout<<"Enter 2 to print the details of the vehicle eith the lowest price"<<endl;
	cout<<"Enter 3 to find the average price of a paticular brand of vehicle"<<endl;
	cout<<"Enter -1 to exit program"<<endl<<endl;
}

//function to display details of all vehicles
void display(struct vehicle v[],int n){
	int i=0;
	cout<<"Brand\tModel\tid\tYear\tPrice\n";
	while(i<n){
		cout<<v[i].model.brand<<"\t"<<v[i].model.type<<"\t"<<v[i].model.id<<"\t"<<v[i].year<<"\t"<<v[i].price<<endl;
		i++;
	}
}

//function to find details of minimum price car
void find_min_price(struct vehicle v[],int n){
	int i=0;
	int min = 0;
	while(i<n){
		if(v[min].price > v[i].price){
			min = i;
		}
		i++;
	}
	cout<<"Details of the vehicle with the lowest price\n";
	cout<<"Brand: "<<v[min].model.brand<<endl;
	cout<<"Type: "<<v[min].model.type<<endl;
	cout<<"vehicle id: "<<v[min].model.id<<endl;
	cout<<"Year: "<<v[min].year<<endl;
	cout<<"Price: "<<v[min].price<<endl<<endl;
}

//function to calculate average price of same brand;
void find_average_price(struct vehicle v[], int n){
	string brand;
	cout<<"Enter brand name: ";
	cin>>brand;
	int i=0;
	int numOfcars=0;
	int sum=0;
	while(i<n){
		if(v[i].model.brand == brand){
			numOfcars++;
			sum+=v[i].price;
		}
		i++;
	}
	if(numOfcars==0){
		cout<<"\nNo such brand in the database"<<endl;
	}else{
		printf("Average price for given brand id : %4.2f\n\n",((float)sum)/((float)numOfcars));
	}
}

int main(){
	int n = 6;
	struct vehicle v[n];
	readFile(v,n);
	while(true){
		menu();
		string o;
		cin>>o;
		if(o == "1"){
			display(v,n);
			cout<<endl;
		}else if(o == "2"){
			find_min_price(v,n);
			cout<<endl;
		}else if(o == "3"){
			find_average_price(v, n);
			cout<<endl;
		}else if(o == "-1"){
			break;
		}else{
			cout<<"Invalid Entry! Please try again!"<<endl<<endl;
		}
	}
}

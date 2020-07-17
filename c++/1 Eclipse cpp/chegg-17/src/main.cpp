/*
 * main.cpp
 *
 *  Created on: 10-Jul-2020
 *      Author:
 */


#include <iostream>
#include <fstream>

using namespace std;

/**
 * structure to store student data
 */
struct Student{
	string name;
	string studentNo;
	string phone;
	string address1;
	string address2;
	string major;
	bool isPrint;
};

/**
 * function to count space in any string
 * @return number of space in string
 */
int countspace(string str){
	int count = 0;
	for (unsigned int i = 0; i<str.length(); i++){
		if ( isspace( str[i] ) ){
			count++;
		}
	}
	return count;
}

/**
 * main function
 */
int main(){
	ifstream fin;
	string filename;

	cout<<"\t\tWelcome to the Roster Generator Program!!!\n";
	cout<<"Please enter tha name of your names files: ";

	// read filename
	cin>>filename;
	fin.open(filename.c_str()); // open file

	// check if file successfully opened or not
	while (!fin.good()){
		cout<< "I'm sorry, I could not open '"<<filename<<"'.\n";
		cout<<"Please enter another name: ";
		cin>>filename; // if file failed to open read another file name
		fin.open(filename.c_str()); // open another file
	}

	cout<<"File '"<<filename<<"' opened successfully!\n";
	cin.ignore();

	Student sd;
	sd.isPrint = true;

	int i = 0;
	cout << "Name\t\t | Major\t\t\t |Phone #\t\t|Town\n";
	cout << "------------------------------------------------------------------------------------\n";
	while(fin){
		// read content of file and print
		if (!sd.isPrint) {
			cout<<sd.name<<"\t | "<<sd.major;
			int sCount = countspace(sd.major);

			for (int j = 3 - sCount; j > 0; j--){
				cout<<"\t";
			}
			cout<<" | "<<sd.phone;

			if(sd.phone == ""){
				cout<<"\t\t";
			}

			cout<<"\t | "<<sd.address2<<"\n";
			sd.isPrint = true;
		}

		string line;
		getline(fin, line);

		i++;

		if (i == 1){
			if(line == ""){
				break;
			}
			sd.name = line;
		}else if(i == 2){
			sd.studentNo = line;
		}else if(i == 3){
			sd.address1 = line;
		}else if(i == 4){
			sd.address2 = line;
		}else if(i == 5){
			sd.phone = line;
		}else if(i == 6){
			sd.major = line;
			sd.isPrint = false;
			i = 0;
		}
	}
}


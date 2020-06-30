#include<iostream>
#include<fstream>
#include<cstring>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char **argv){
	ifstream fin;
	ofstream fout;
	
	ArgumentManager am(argc, argv, ' '); // gettting argument manager object
	string inputFileName = am.get("input"); // getting input file name from argument manager
	string outputFileName = am.get("output"); //getting output file name from argument manager
	
	fin.open(inputFileName.c_str()); // open input file
	fout.open(outputFileName.c_str()); // open output file
	
	int charCount = 0; // counter varible for letter count
	int numCount = 0; // counter variable for number count
	
	while(fin){
		string line;
		getline(fin, line); // read line from file
		for(int i=0; i<line.length(); i++){
			if(line[i]>='0' && line[i]<='9'){
				numCount++;
			}else if(line[i] >= 'A' && line[i]<='Z' || line[i] >= 'a' && line[i] <= 'z'){
				charCount++;
			}
		}
	}
	
	fout<<numCount<<endl<<charCount; // write data to output file
	fin.close();
	fout.close();
}

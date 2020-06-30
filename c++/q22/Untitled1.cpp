#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/**
* function to remove space and puntuation
* 
*/
string removeSpacePunc(string str){
	int i = 0;
	int len = str.length();
	
	while(i < len){
		char c = str[i];
		
		if( ispunct(c) || isspace(c)){
			str = str.erase(i, 1);
			len = str.length();
			continue;
		}
		i++;
	}
	
	return str;
}

/**
* function to sort the string
* 
*/
string sortString(string str){
	char charSmall[26] = {0};
	char charCap[26] = {0};
	
	int len = str.length();
	int i = 0;
	
	while(i < len){
		if(str[i] >= 'a' && str[i] <= 'z'){
			charSmall[str[i]-'a']++;
		}else{
			charCap[str[i]-'A']++;
		}
		i++;
	}
	
	string res = "";
	
	for (int j = 0; j < 26; j++){
		for (int k=0; k<charCap[j]; k++){
			res += (char) ('A' + j);
		}
		
		for (int k=0; k<charSmall[j]; k++){
			res += (char) ('a' + j);
		}
		
	}
	
	return res;
}

int main(){
	
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	
	while(fin){
		string line1,line2;
		
		getline(fin, line1);
		getline(fin, line2);
		
		if(line1 == "" && line2 == ""){
			continue;
		}
		
		line1 = removeSpacePunc(line1); // remove white space and puntuation from string one
		line2 = removeSpacePunc(line2); // remove white space and puntuation from string second
		
		int len1 = line1.length(); // calculate length of line 1
		int len2 = line2.length(); // calculate length of line 2
		
		if(len1 == len2){
			line1 = sortString(line1); // sort line one
			line2 = sortString(line2); // sort line2
			
			if(line1 == line2){
				fout<<1<<endl; // write 1 to output file
			}else{
				fout<<0<<endl; // write 0 to output file
			}
		}else{
			fout<<0<<endl; // write 0 to output file
		}
	
	}
	
}

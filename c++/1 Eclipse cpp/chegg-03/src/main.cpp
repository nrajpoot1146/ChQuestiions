/*
 * main.cpp
 *
 *  Created on: 21-Jun-2020
 *      Author: naren
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ArgumentManager.h"
using namespace std;

/**
 * function to map words of number to numeric number
 * one		=>	1;
 * two 		=>	2;
 * three 	=>	3;
 * four		=>	4;
 * five		=>	5;
 * six		=>	6;
 * seven	=>	7;
 * eight	=>	8;
 * nine		=>	9;
 * zero		=>	0;
 *
 * @return an integer between 0 - 9
 */
int getNum(string);

int main(int argc, char **argv){
	ifstream fin;
	ofstream fout;

	ArgumentManager am(argc, argv, ' '); // parse command line argument using ArgumentManager
	string inputFileName = am.get("input"); // fetch input file name from argument manager
	string outputFileName = am.get("output"); // fetch output file name from argument manager

	fin.open(inputFileName.c_str()); // open input file
	fout.open(outputFileName.c_str()); // open output file

	int previousNumber = -1; // variable to store result of last read line
	bool matchFlag = true; // variable to check if all line have equal value or not

	// read all line from file
	while (fin){
		string line = ""; // variable to store read line from file;
		getline(fin, line); // read line from file and store it into line variable

		// if line is empty break the current loop
		if (line == ""){
			break;
		}
		int num = 0;

		// if line have "word" its means line contains word of number like one, two, three
		if (line.find("word") != string::npos){
			num = getNum(line.substr(0,line.find(" "))); // fetch number from current line
		}else if(line.find("+") != string::npos || line.find("-") != string::npos){ // if line contains "+" or "-" this means line have an arithmetic operation

			int first = -1;
			int second = -1;
			char op;

			// fetch first digit from current line
			stringstream ss;
			string temp = "";
			temp = line.substr(0, line.find(" "));
			ss<<temp;
			ss>>first;

			// fetch operator from current line
			line = line.substr(line.find(" ")+1);
			op = line.substr(0, line.find(" "))[0];

			// fetch second digit from current line
			line = line.substr(line.find(" ")+1);
			temp = line.substr(0);
			ss.clear();
			ss<<temp;
			ss>>second;
			num = op == '+' ? first + second : first - second; // perform given arithmetic operation according to previous operator

		}else{ // for line contains only numeric digit
			stringstream ss(line);
			ss>>num;
		}


		if(previousNumber == -1){
			previousNumber = num;
		}else{
			if(previousNumber != num){
				matchFlag = false;
				break;
			}
		}
	}

	// write result to output file
	if(matchFlag == true){
		fout<<"match";
	}else{
		fout<<"not match";
	}

	fin.close();
	fout.flush();
	fout.close();

}

int getNum(string s){
	if(s == "one"){
		return 1;
	}else if(s == "two"){
		return 2;
	}else if(s == "three"){
		return 3;
	}else if(s == "four"){
		return 4;
	}else if(s == "five"){
		return 5;
	}else if(s == "six"){
		return 6;
	}else if(s == "seven"){
		return 7;
	}else if(s == "eight"){
		return 8;
	}else if(s == "nine"){
		return 9;
	}else if(s == "zero"){
		return 0;
	}else{
		return -1;
	}
}



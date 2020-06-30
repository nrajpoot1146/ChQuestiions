#include<iostream>
using namespace std;

class Customer{
	string name;
	string operation;
	double money;
	int age;
	
	public:
		Customer(string name, string operation, double money, int age){
			this->setAge(age);
			this->setName(name);
			this->setMoney(money);
			this->setOperation(operation);
		}
		
		/**
		* function to set name of customer
		* @param name of customer
		*/
		void setName(string name){
			this->name = name;
		}
		
		/**
		* function to set operation of customer
		* @param operaion (Deposit/ Withdraw)
		*/
		void setOperation(string operation){
			this->operation = operation;
		}
		
		/**
		* function to set mmoney of customer 
		* @param money
		*/
		void setMoney(double money){
			this->money = money;
		}
		
		/**
		* function to set age of customer
		* @param age of customer
		*/
		void setAge(int age){
			this->age = age;
		}
		
		/**
		* @return name of customer
		*/
		string getName(){
			return this->name;
		}
		
		/**
		* return operation of customer
		*/
		string getOperation(){
			return this->operation;
		}
		
		/**
		* @return money of customer
		*/
		double getMoney(){
			return this->money;
		}
		
		/**
		* @return age of customer
		*/
		int getAge(){
			return this->age;
		}
		
		
		/**
		* print all details of customer
		*/
		void print(){
			cout<<"Name: "<<this->name<<endl;
			cout<<"Operation: "<<this->operation<<endl;
			cout<<"Money: "<<this->money<<endl;
			cout<<"Age: "<<this->age<<endl;
		}
};

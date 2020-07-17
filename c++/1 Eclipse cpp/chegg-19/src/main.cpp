/*
 * main.cpp
 *
 *  Created on: 11-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

void printWelcomeMessage();
int getModelYear();
double getPurchasePrice();
int getCurrentYear();

int main(){
	/*
	 * sample intput:
	 *
	 */

	printWelcomeMessage();
	int modelYear = getModelYear();
	double purchasePrice = getPurchasePrice();
	int currentYear = getCurrentYear();

	Car mySecion = Car(modelYear, purchasePrice, currentYear);
	mySecion.PrintInfo();
	return 0;
}

void printWelcomeMessage(){
	string welcomeMessage = "Welcome to Help Me Figure Out My Cars Value\n";
	cout << welcomeMessage;
}

int getModelYear(){
	int modelYear;
	string getModelYearMessage = "What is the model year of your vehicle?: ";
	cout<< getModelYearMessage;
	cin >> modelYear;
	return modelYear;
}

double getPurchasePrice(){
	double purchasePrice;
	string getPurchasePriceMessage = "What was the purchase price of the vehicle?: ";
	cout<<getPurchasePriceMessage;
	cin>>purchasePrice;
	return purchasePrice;
}

int getCurrentYear(){
	int currentyear;
	string getCurrentYearMessage = "What is the current year?: ";
	cout <<getCurrentYearMessage;
	cin>>currentyear;
	return currentyear;
}



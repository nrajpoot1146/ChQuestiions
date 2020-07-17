/*
 * Car.h
 *
 *  Created on: 11-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include <math.h>

#ifndef PROJECT5_CAR_H_
#define PROJECT5_CAR_H_

class Car {
public:
	Car(int modelYear, double purchasePrice, int currentYear){
		SetModelYear(modelYear);
		SetPurchasePrice(purchasePrice);
		SetCurrentYear(currentYear);
		CalcCurrentValue();
	}

	void SetModelYear(int year);
	void SetPurchasePrice(double price);
	void SetCurrentYear(int year);
	void PrintInfo();
	void CalcCurrentValue();
private:
	int modelYear;
	double purchasePrice;
	int currentYear;
	double currentValue;
	double static const depreciation = .15;
};

#endif /* PROJECT5_CAR_H_ */

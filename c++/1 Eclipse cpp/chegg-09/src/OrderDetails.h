/*
 * OrderDetails.h
 *
 *  Created on: 27-Jun-2020
 *      Author: naren
 */

#ifndef ORDERDETAILS_H_
#define ORDERDETAILS_H_

#include <time.h>
#include <string>

using namespace std;

class OrderDetails {
	time_t date;
	int quantity;
	string texStatus;
public:
	OrderDetails();
	void calcCartSubTotal();
	void calcTax();
	virtual ~OrderDetails();
};

#endif /* ORDERDETAILS_H_ */

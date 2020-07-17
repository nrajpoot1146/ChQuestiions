/*
 * Reminder.h
 *
 *  Created on: 16-Jul-2020
 *      Author:
 */

#ifndef SRC_REMINDER_H_
#define SRC_REMINDER_H_

#include <iostream>
#include <sstream>

class Reminder {
private:
	int month, day;
	std::string des;
public:
	Reminder(int month, int day, std::string description);

	/**
	 * sets day
	 * @param day to be set
	 */
	void setDay(int day);

	/**
	 * get day
	 */
	int getDay();

	/**
	 * sets Month
	 */
	void setMonth(int month);

	/**
	 * get month
	 */
	int getMonth();

	/**
	 * sets description
	 */
	void setDescription(std::string description);

	/**
	 * get description
	 */
	std::string getDescription();

	/**
	 * generate reminder info string
	 * @return string ( format: mm/dd description)
	 */
	std::string toString();

	/**
	 * check whether date of current object is before the given compared object
	 * @param r other reminder to compare
	 * @return true if date of current object is before date of given compared object
	 */
	bool isBefore(const Reminder &r);
	virtual ~Reminder();
};

#endif /* SRC_REMINDER_H_ */

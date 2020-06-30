/*
 * Shelf.h
 *
 *  Created on: 27-Jun-2020
 *      Author:
 */

#ifndef SRC_SHELF_H_
#define SRC_SHELF_H_

#include "Text.h"

class Shelf {
private:
	char loc[40];
	Text *m_text;
	int ntext;
public:

	/**
	 * Default constructor set all attribute to safe empty state
	 */
	Shelf();

	/**
	 * sets location
	 * sets number of books in shelf
	 * @param loct
	 * @param nText
	 */
	Shelf(const char loct[], int nText);

	/**
	 * display all book information
	 */
	void display();

	/**
	 * add an Text to Shelf
	 * @param text instance of a Book
	 * @param i index of new book in shelf
	 */
	void add(Text *text, int index);

	virtual ~Shelf();
};

#endif /* SRC_SHELF_H_ */

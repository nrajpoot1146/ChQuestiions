/*
 * Book.h
 *
 *  Created on: 22-Jun-2020
 *      Author:
 */

#ifndef BOOKH
#define BOOKH

#include <string>

using namespace std;

class Book {
public:

	/**
	 * setter function for userTitle
	 */
	void SetTitle(string userTitle);

	/**
	 * getter function to fetch title
	 * @return string title of book
	 */
	string GetTitle();

	/**
	 * setter for author
	 * @param userAuthor to be set
	 */
	void SetAuthor(string userAuthor);

	/**
	 * getter for author
	 * @return string author of book
	 */
	string GetAuthor();

	/**
	 * setter for publisher
	 * @param userPublisher
	 */
	void SetPublisher(string userPublisher);

	/**
	 * getter for publisher
	 * @return string publisher of book
	 */
	string GetPublisher();

	/**
	 * setter for publication date
	 * @param string PublicationDate of book
	 */
	void SetPublicationDate(string userPublicationDate);

	/**
	 * getter for publication date
	 * @return string publication date of book
	 */
	string GetPublicationDate();

	void PrintInfo();

protected:
	string title;
	string author;
	string publisher;
	string publicationDate;
};

#endif

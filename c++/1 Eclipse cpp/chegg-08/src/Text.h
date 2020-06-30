/*
 * Text.h
 *
 *  Created on: 27-Jun-2020
 *      Author:
 */

#ifndef SRC_TEXT_H_
#define SRC_TEXT_H_

class Text {
private:
	char topic[40];
	char owner[30];
	int slides;
public:
	Text();

	/**
	 * sets the title of the book
	 * if string is valid set it to title
	 * otherwise set it to empty string;
	 * @param topic of book
	 */
	void setTopic(const char* x);

	const char* getTopic() const;

	/**
	 * sets author name of the book
	 * if string is valid set to author attribute
	 * otherwise author attribute set to empty
	 * @param author of book to be set
	 */
	void setOwner(const char* x);

	const char* getOwner() const;

	/**
	 * sets the number of pages of book
	 * if number of pages is valid, set it to slide attribute
	 * otherwise set slide attribute to zero
	 */
	void setSlides(const int q);

	int getSlides();

	/**
	 * function to display each attribute
	 */
	void output();
	virtual ~Text();
};

#endif /* SRC_TEXT_H_ */

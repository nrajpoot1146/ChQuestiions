/*
 * main.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author:
 */

#include "Shelf.h"
#include "Text.h"
#include <iostream>

int main(){
	Shelf shelf("North America Center", 2);

	// create a new book
	Text *book1 = new Text();
	book1->setTopic("Dancing learning");
	book1->setOwner("John & Tony");
	book1->setSlides(900);

	// create a new book
	Text *book2 = new Text();
	book2->setTopic("One step at a time");
	book2->setOwner("Robert Hitch");
	book2->setSlides(400);

	// add above books to shelf
	shelf.add(book1, 0);
	shelf.add(book2, 1);

	// display shelf information
	shelf.display();
}



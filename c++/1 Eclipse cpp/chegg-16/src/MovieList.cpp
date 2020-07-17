/*
 * MovieList.cpp
 *
 *  Created on: 08-Jul-2020
 *      Author: naren
 */

#include "MovieList.h"

MovieList::MovieList() {
	this->movies[0].setName("Inception");
	this->movies[0].setGenre("Action");
	this->movies[0].setRating(8.8);

	this->movies[1].setName("Peter Pan");
	this->movies[1].setGenre("Adventure");
	this->movies[1].setRating(7.3);

	this->movies[2].setName("The Dark Knight");
	this->movies[2].setGenre("Crime");
	this->movies[2].setRating(9);

	this->movies[3].setName("Desperado");
	this->movies[3].setGenre("Thriller");
	this->movies[3].setRating(7.2);

	this->movies[4].setName("Pulp");
	this->movies[4].setGenre("Fiction");
	this->movies[4].setRating(8.9);
}

Movie* MovieList::searchByName(std::string name){
	for (int i = 0; i<5; i++){
		if(this->movies[i].getName() == name){
			return &(this->movies[i]);
		}
	}
	return NULL;
}

Movie& MovieList::getHighestRatedMovie(){
	int max = 0;

	for (int i = 1; i < 5; i++){
		if (this->movies[max].getRating() < this->movies[i].getRating()){
			max = i;
		}
	}
	return this->movies[max];
}

void MovieList::printList(){
	for (int i = 0; i < 5; i++){
		this->movies[i].print();
		std::cout<<std::endl;
	}
}

MovieList::~MovieList() {
	// TODO Auto-generated destructor stub
}


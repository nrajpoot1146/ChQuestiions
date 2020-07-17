/*
 * MovieList.h
 *
 *  Created on: 08-Jul-2020
 *      Author: naren
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_

#include "Movie.h"

class MovieList {
public:
	MovieList();

	/**
	 * search movie by name
	 * @param name of movie to search
	 * @return Movie object if found otherwise return null;
	 */
	Movie *searchByName(std::string name);

	/**
	 * get highest rated movie
	 * @return Movie object
	 */
	Movie &getHighestRatedMovie();

	/**
	 * print list of movies
	 */
	void printList();
	virtual ~MovieList();

private:
	Movie movies[5];
};

#endif /* MOVIELIST_H_ */

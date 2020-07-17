/*
 * Movie.h
 *
 *  Created on: 08-Jul-2020
 *      Author: naren
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>

class Movie {
public:
	/**
	 * default constructor
	 */
	Movie();

	/**
	 * parameterize constructor
	 * @param name of movie
	 * @param genre of movie
	 * @param rating IMDB rating of movie
	 */
	Movie(std::string name, std::string genre, float rating);

	/**
	 * get name of movie
	 * @return name of movie
	 */
	std::string getName();

	/**
	 * sets name of movie
	 */
	void setName(std::string name);

	/**
	 * gets genre of movie
	 * @return genre of movie
	 */
	std::string getGenre();

	/**
	 * sets genre of movie
	 * @param genre of movie to set
	 */
	void setGenre(std::string genre);

	/**
	 * gets rating of movie
	 * @return rating of movie
	 */
	float getRating();

	/**
	 * sets rating of movie
	 * @param rating of movie
	 */
	void setRating(float rating);

	/**
	 * details of movie
	 */
	void print();
	virtual ~Movie();

private:
	std::string name;
	std::string genre;
	float rating;
};

#endif /* MOVIE_H_ */

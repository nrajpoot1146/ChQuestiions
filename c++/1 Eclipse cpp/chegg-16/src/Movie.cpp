/*
 * Movie.cpp
 *
 *  Created on: 08-Jul-2020
 *      Author: naren
 */

#include "Movie.h"

Movie::Movie() : name(""), genre(""), rating(0){}

Movie::Movie(std::string name, std::string genre, float rating) : name(name), genre(genre), rating(rating){}

std::string Movie::getName(){
	return this->name;
}

void Movie::setName(std::string name){
	this->name = name;
}

std::string Movie::getGenre(){
	return this->genre;
}

void Movie::setGenre(std::string genre){
	this->genre = genre;
}

float Movie::getRating(){
	return this->rating;
}

void Movie::setRating(float rating){
	this->rating = rating;
}

void Movie::print(){
	std::cout<<"Name : "<<this->name<<", ";
	std::cout<<"Genre : "<<this->genre<", ";
	std::cout<<"Rating : "<<this->rating;
}

Movie::~Movie() {}


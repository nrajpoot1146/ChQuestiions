/*
 * Shelf.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author:
 */

#include "Shelf.h"
#include <string.h>
#include <iostream>

using namespace std;

Shelf::Shelf() {
	strcpy(this->loc, "");
	this->m_text = NULL;
	this->ntext = 0;
}

Shelf::Shelf(const char* loct, int nText){
	if (strlen(loct) > 0 && ( (loct[0] >= 'a' && loct[0] <='z') || (loct[0] >= 'A' || loct[0] <= 'Z'))){
		strcpy(this->loc, loct);
	}

	if(this->ntext > 0){
		this->ntext = nText;
		this->m_text = new Text[this->ntext];
	}
}

void Shelf::add(Text *text, int i){
	if(i < this->ntext){
		const char *topic = text->getTopic();
		const char *owner = text->getOwner();
		int slides = text->getSlides();

		this->m_text[i].setTopic(topic);
		this->m_text[i].setOwner(owner);
		this->m_text[i].setSlides(slides);

	}
}

void Shelf::display(){
	cout<<"The Shelf Details: "<<endl;
	cout<<"Address: "<<this->loc<<endl;
	cout<<"Text: "<<endl;

	for (int i=0; i<this->ntext; i++){
		cout<<i+1<<": ";
		this->m_text[i].output();
		cout<<endl;
	}
}

Shelf::~Shelf() {
	delete this->m_text;
}


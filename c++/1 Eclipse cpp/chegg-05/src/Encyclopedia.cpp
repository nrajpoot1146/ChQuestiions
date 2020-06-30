/*
 * Encyclopedia.cpp
 *
 *  Created on: 22-Jun-2020
 *      Author:
 */

#include "Encyclopedia.h"

Encyclopedia::Encyclopedia() {
	// TODO Auto-generated constructor stub

}

void Encyclopedia::SetEdition(string edition){
	this->edition = edition;
}

void Encyclopedia::SetNumVolumes(int numVolumes){
	this->numVolumes = numVolumes;
}

void Encyclopedia::PrintInfo(){
	Book::PrintInfo();
	cout<<" Edition: "<<this->edition<<endl;
	cout<<" Number of Volumes: "<<this->numVolumes<<endl;
}

Encyclopedia::~Encyclopedia() {
	// TODO Auto-generated destructor stub
}


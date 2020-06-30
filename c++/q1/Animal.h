#ifndef ANIMAL_H_

#define ANIMAL_H_

#include <string>

class Animal

{

public:

Animal();

Animal(std::string, bool domestic=false, bool predator=false);

std::string getName() const;

bool isDomestic() const;

bool isPredator() const;

void setName(std::string);

void setDomestic();

void setPredator();

protected: // protected so that derived class can directly access them

std::string name_;

bool domestic_;

bool predator_;

};

#endif /* ANIMAL_H_ */

//end of Animal.h

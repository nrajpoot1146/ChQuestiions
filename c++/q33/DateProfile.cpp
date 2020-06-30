#ifndef DATE_PROFILE
#define DATE_PROFILE

#define MIN_ROMANCE 1			// min value for romance
#define MAX_ROMANCE 10			// max value for romance
#define MIN_FINANCE 1			// min value for finance
#define MAX_FINANCE 10			// max value for finance
#define MIN_NAME_LEN 4			// min lenth for name
#define MAX_NAME_LEN 50			// max length for name
#define DEFAULT_GEND 'M'		// default value for gender
#define DEFAULT_SEARCH_GEND 'F'	// default value for search profile gender
#define DEFAULT_NAME "person"	// default value for name
#define DEFAULT_ROMANCE 5		// default value for romance
#define DEFAULT_FINANCE 5		// default value for finance


#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class DateProfile{
	private:
		char gender;
		char searchGender;
		int romance;
		int finance;
		string name;
	
		// function to determine gender fit between two profile
		double determineGenderFit(DateProfile partner){
			if(this->gender == partner.gender && this->searchGender == partner.searchGender){
				return 1.0;
			}
			return 0;
		}
		
		// function to determine romance fit between two profile
		double determineRomanceFit(DateProfile partner){
			return (10 - abs(this->romance - partner.romance)) / 10.0;
		}
		
		// function to determine finance fit between two profile
		double determineFinanceFit(DateProfile partner){
			return ( 10 - abs(this->finance - partner.finance)) / 10.0;
		}
		
	public:
		
		// default constructor
		DateProfile(){
			this->setDefault();
		}
		
		// constructor with parameter
		DateProfile(char gender, char searchGender, int romance, int finance, string name){
			this->setAll(gender, searchGender, romance, finance, name);
		}
		
		// function to set all attribute value by passing their value as parameter
		void setAll(char gender, char searchGender, int romance, int finance, string name){
			this->setGender(gender);
			this->setSearchGender(searchGender);
			this->setRomance(romance);
			this->setFinance(finance);
			this->setName(name);
		}
		
		// funtion to set all attribute to their default value
		void setDefault(){
			this->setGender(DEFAULT_GEND);
			this->setSearchGender(DEFAULT_SEARCH_GEND);
			this->setRomance(DEFAULT_ROMANCE);
			this->setFinance(DEFAULT_FINANCE);
			this->setName(DEFAULT_NAME);
		}
		
		// setter for attribute gender
		bool setGender(char g){
			if(g == 'M' || g == 'F'){
				this->gender = g;
				return true;
			}
			this->gender = DEFAULT_GEND;
			return false;
		}
		
		// getter for attribute gender
		char getGender(){
			return this->gender;
		}
		
		// setter for attribure searchGender
		bool setSearchGender(char sg){
			if(sg == 'M' || sg == 'F'){
				this->searchGender = sg;
				return true;
			}
			this->searchGender = DEFAULT_SEARCH_GEND;
			return false;
		}
		
		// getter for attribute searchGender
		char getSearchGender(){
			return this->searchGender;
		}
		
		// setter for attribute romance
		bool setRomance(int r){
			if(r >= MIN_ROMANCE && r <= MAX_ROMANCE){
				this->romance = r;
				return true;
			}
			return false;
		}
		
		// getter for attribute romance
		int getRomance(){
			return this->romance;
		}
		
		// setter for attribute finance
		bool setFinance(int f){
			if(f >= MIN_FINANCE && f <= MAX_FINANCE){
				this->finance = f;
				return true;
			}
			this->finance = DEFAULT_FINANCE;
			return false;
		}
		
		// getter for attribute finance
		int getFinance(){
			return this->finance;
		}
		
		// setter for attribute name
		bool setName(string name){
			if(name.length() >= MIN_NAME_LEN && name.length() <= MAX_NAME_LEN){
				this->name = name;
				return true;
			}
			this->romance = DEFAULT_ROMANCE;
			return false;
		}
		
		// getter for attribute name
		string getName(){
			return this->name;
		}
		
		// function to calculate fit value between two profile
		double fitValue(DateProfile partner){
			double genderFit = this->determineGenderFit(partner);
			double romanceFit = this->determineRomanceFit(partner);
			double financeFit = this->determineFinanceFit(partner);
			
			return ( genderFit + romanceFit + financeFit ) / 3.0;
		}
};

#endif

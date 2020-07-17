/*
 * main.cpp
 *
 *  Created on: 08-Jul-2020
 *      Author: naren
 */

#include <iostream>
#include <vector>
#include "Movie.h"
#include "MovieList.h"
using namespace std;

/**
 * buy movie ticket generate bill
 */
void buyTicket(MovieList &movieList){
	const int ticketmaount = 500;
	vector<string> mName;
	vector<int> mNticket;
	while (true){
		string name;
		int nticket;
		cout<<"Enter name of movie you want to buy ticket: ";
		getline(cin, name); // read movie name
		cout<<"Enter number of tickets : ";
		cin>>nticket; // read number of ticket
		cin.ignore();

		Movie *temp = movieList.searchByName(name);
		if (temp == NULL){
			cout<<"Error : movie with given name not found : \n";
		}else{
			mName.push_back(name);
			mNticket.push_back(nticket);
		}

		cout<<"Do you want to buy more ticket (y/n) : ";
		char op;
		cin>>op;
		while( op != 'y' && op != 'n'){
			cout<<"Do you want to buy more ticket (y/n) : ";
			cin>>op;
		}
		cin.ignore();

		if (op == 'n'){
			break;
		}
	}

	int totalamount = 0;
	cout<<endl;
	cout<<"Bill : \n";
	for (unsigned int i = 0; i < mName.size(); i++){
		cout<<mName[i]<<"\t\t\t"<<mNticket[i]<<"\t"<<mNticket[i]<<" * "<<ticketmaount<<" = "<<mNticket[i] * ticketmaount<<endl;
		totalamount += mNticket[i] * 500;
	}

	cout<<"Total amount = "<<totalamount<<endl;
}

/**
 * print menu
 */
void printMenu(){
	cout<<"Menu : \n";
	cout<<"1. Search movie by name\n";
	cout<<"2. Movie with highest rating\n";
	cout<<"3. See list of movies\n";
	cout<<"4. Buy tickets\n";
	cout<<"5. exit\n";
}

int main(){
	MovieList movieList;
	while (true){
		printMenu();
		int op;
		cin>>op;
		cin.ignore();

		if (op == 1){
			string name;
			cout<<"Enter name of movie: ";
			getline(cin, name); // read movie name
			Movie *movie = movieList.searchByName(name);
			if (movie == NULL){
				cout<<"Error : Movie not found!\n";
				continue;
			}
			movie->print();
			cout<<endl<<endl;
		}else if (op == 2){
			Movie movie = movieList.getHighestRatedMovie();
			movie.print();
			cout<<endl<<endl;
		}else if (op == 3){
			movieList.printList();
			cout<<endl<<endl;
		}else if (op == 4){
			buyTicket(movieList);
			cout<<endl<<endl;
		}else if (op == 5){
			break;
		}else {
			cout<<"Error : Invalid option!\n";
		}
	}
}



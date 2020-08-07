/*
 * Source.cpp
 *
 *  Created on: 27-Jul-2020
 *      Author:
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include "User.h"

using namespace std;

//This Node class is used for linked list that keep users
class Node {
public:
   User* user;
   Node* next;
};

int main()
{
	ifstream ifs;
	ifs.open("data.txt");
	if(!ifs.good()){ // check whether file is successfully opened or not
		cout<<"Error File does not exist!"<<endl;
		return 0;
	}
   //Create a head and tail
	Node *head = NULL;
	Node *tail = NULL;
   // start reading the file and create a pointer to a user (using new [example: User* a = new User("Jose");])
   // and add it to the linked list(create a new node, etc)
   // You have already implemented the queue in the class, you know!
	while(ifs){
		string line;
		getline (ifs, line); // read name of user
		if (ifs.eof())
			break;

		User *usr = new User(line);
		getline(ifs, line); // read number of post
		stringstream ss;
		ss<<line;
		int numPost;
		ss>>numPost; 	// convert number of post string to integer

		for (int i=0; i<numPost; i++){
			getline(ifs, line);
			string value = line.substr(0, line.find(','));
			string time = line.substr(line.find(',')+2);
			usr->addPost(value, time);
		}

		// create new node
		Node *newNode = new Node();
		newNode->user = usr; // set user
		newNode->next = NULL; // set next pointer to Null

		if (head == NULL){ // if user linked list is empty
			head = newNode;
			tail = newNode;
		} else { // if list is not empty
			tail->next = newNode;
			tail = newNode;
		}
	}


	// go through the linked list you created and call showPosts() on each user.
	// Since showPosts print out the content and the time, you are done!
	// show post with username
	Node *temp = head;
	while (temp != NULL){
		temp->user->showPosts();
		temp = temp->next;
	}


   return 0;
}




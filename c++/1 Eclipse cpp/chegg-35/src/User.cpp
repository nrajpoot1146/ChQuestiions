/*
 * User.cpp
 *
 *  Created on: 27-Jul-2020
 *      Author:
 */

#include "User.h"

User::User(string name)
{
   this->name = name;
   numberOfPosts = 0;
}

void User::addPost(string value, string time)
{
   // Create a pointer to a post (use "new"), initialize it [example: Post* q = new Post("Homework","Thu Sep 12 2018");]
   // and then add it to the linked list (create a new node, etc)
   // You have already implemented the queue in the class, you know!

   //TO DO
   Post* temp = new Post(value, time);
   Node *newNode = new Node();
   newNode->p = temp;
   newNode->next = NULL;
   if (this->numberOfPosts == 0){
	   this->numberOfPosts++;
	   this->head_posts = newNode;
	   this->tail_posts = newNode;
	   return;
   }
   this->numberOfPosts++;
   this->tail_posts->next = newNode;
   this->tail_posts = newNode;
}

void User::showPosts()
{
   //Using the head_posts, you can go through the posts and print them out

   Node *curr = this->head_posts;
   while (curr != NULL){
	   cout<<this->name<<" wrote at "<<curr->p->creationDate<<":"<<curr->p->value<<'\n';
	   curr = curr->next;
   }

}


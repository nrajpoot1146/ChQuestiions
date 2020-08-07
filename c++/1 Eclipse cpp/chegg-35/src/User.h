/*
 * User.h
 *
 *  Created on: 27-Jul-2020
 *      Author:
 */

#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "Post.h"
using namespace std;

class User
{


public:
   //This Node class is used for linked list that keep posts
   class Node {
   public:
       Post* p;
       Node* next;
   };

   User(string name);

   /** Create a pointer to a post (use "new") [example: Post* q = new Post("Homework","Thu Sep 12 2018");]
   and then add it to the linked list (create a new node, etc)
   You have already implemented the queue in the class, you know!
   */
   void addPost(string value, string time);

   /**Using the head_posts, you can go through the posts and print them out (cout)
   you should print them out like this:
   "username" wrote "content of the post" at "time of the post"
   For example
   Jose wrote I am a great programmer at Thu Aug 30 14:23 2018.
   */
   void showPosts();


private:
   string name;
   Node* head_posts;
   Node* tail_posts;
   int numberOfPosts;
};

#endif

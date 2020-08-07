/*
 * Post.h
 *
 *  Created on: 27-Jul-2020
 *      Author:
 */

#ifndef POST_H
#define POST_H
#include <string>
using namespace std;


class Post
{
public:

   Post();
   Post(string value, string time);
   //return the content of the post
   string showPost();
   //return the time of the post
   string showTime();

   string value;
   string creationDate;
};

#endif

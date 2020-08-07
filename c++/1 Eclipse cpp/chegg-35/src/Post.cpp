/*
 * Post.cpp
 *
 *  Created on: 27-Jul-2020
 *      Author:
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Post.h"

Post::Post(string value, string time)
{
   this->value = value;
   this->creationDate = time;
}

Post::Post()
{
   value = "";
   creationDate = "";
}

string Post::showPost()
{
   return value;

}

string Post::showTime()
{
   return creationDate;
}


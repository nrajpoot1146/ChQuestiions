// File : mystring2.cpp
// ================
// Implementation file for user-defined String class.
#include "mystring2.h"

String::String()
{
	this->contents = new char[1];
    strcpy(this->contents,"\0");
    len = 0;
}

String::String(const char *s)
{
    len = strlen(s);
    this->contents = new char[len];
    strcpy(this->contents, s);
}

void String::append(const String &str)
{
	char *temp = new char[this->len + str.len];
	strcpy(temp, this->contents);
	delete[] this->contents;
    strcat(temp, str.contents);
    len += strlen(temp);
    this->contents = temp;
}

bool String::operator==(const String &str) const
{
    return strcmp(contents, str.contents) == 0;
}

bool String::operator!=(const String &str) const
{
    return strcmp(contents, str.contents) != 0;
}

bool String::operator>(const String &str) const
{
    return strcmp(contents, str.contents) > 0;
}

bool String::operator<(const String &str) const
{
    return strcmp(this->contents, str.contents) < 0;
}

bool String::operator>=(const String &str) const
{
    return strcmp(contents, str.contents) >= 0;
}

String String::operator+=(const String &str)
{
    append(str);
    return *this;
}

void String::print(ostream &out) const
{
    out << contents;
}

int String::length() const
{
    return len;
}

char String::operator[](int i) const
{
    if (i < 0 || i >= len)
    {
        cerr << "can't access location " << i
             << " of string \"" << contents << "\"" << endl;
        return '\0';
    }
    return contents[i];
}

ostream &operator<<(ostream &out, const String &s) // overload ostream operator "<<" - External!
{
    s.print(out);
    return out;
}

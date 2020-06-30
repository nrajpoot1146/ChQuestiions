//File: mystring2.h
// ================
// Interface file for user-defined String class.

#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <iostream>
#include <cstring> // for strlen(), etc.
using namespace std;

class String
{
public:
    String();
    String(const char *s); // a conversion constructor
    void append(const String &str);

    // Relational operators
    bool operator==(const String &str) const;
    bool operator!=(const String &str) const;
    bool operator>(const String &str) const;
    bool operator<(const String &str) const;
    bool operator>=(const String &str) const;
    String operator+=(const String &str);

    void print(ostream &out) const;
    int length() const;

    char operator[](int i) const; // subscript operator

private:
    char *contents;
    int len;
};

ostream &operator<<(ostream &out, const String &r); // overload ostream operator "<<" - External!

#endif /* not defined _MYSTRING_H */

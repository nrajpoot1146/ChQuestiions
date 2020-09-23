#include <string>
#include <cctype>

using namespace std;

int sumNums(const string &str);

#include <iostream>

int run() {
    cout<< "(sumNums(abc123xyz)->123?) "<< sumNums("abc123xyz")<<endl;
    cout<< "(sumNums(aa11b33)->44?) "<< sumNums("aa11b33")<<endl;
    cout<< "(sumNums(7 11)->18?) "<< sumNums("7 11")<<endl;

    /// new test cases addded
    cout<< "0uiw5x2v8lx->"<< sumNums("0uiw5x2v8lx")<<endl;
    cout<< "93->"<< sumNums("93")<<endl;
    cout<< "d36->"<< sumNums("d36")<<endl;
    cout<< "9l65847y44->"<< sumNums("9l65847y44")<<endl;
    cout<< "dhvj7y365ut85019->"<< sumNums("dhvj7y365ut85019")<<endl;

    return 0;
}

int sumNums(const string &str) {
    int sum = {0};
    int num = {0};

    for (size_t i = {0}, len={str.size()}; i < len; ++i) { // old: for (size_t i = {0}, len={str.size()}; i < len-1; ++i)
        char ch = {str.at(i)};
        // char last = str.back(); removed line

        if(isdigit(ch)) { // old: if (!isdigit(ch))
            int digit = ch - '0';
            num = num * 10 + digit;
        } else {
            sum = sum + num;
            num = 0; // reset num
            // return sum; removed line
        }
    }

    sum = sum + num;
    return sum; // return sum
}

int main () {
    return run();
}
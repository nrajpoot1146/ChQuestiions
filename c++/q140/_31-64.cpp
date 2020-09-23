#include <stdio.h>

// if you are using 32 bit c compiler then it will show 32 bit operating system
// even you are using 64 bit operating system
// this will give you output according to your compiler and compiler will install
// according to your operating system
int main() {
    #ifdef _WIN32 // _define in both 64 bit and 32 bit windows system
        #ifdef _WIN64 // define in only 64 bit windows system
            printf("System is 64bit"); // print message
        #else
            printf("System is 32 bit"); // print message
        #endif
    #endif
}

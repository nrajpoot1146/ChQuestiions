#include <stdlib.h>
#include <stdio.h>

// main program
int main() {
    int exitcode = system("fizzle.exe"); // execute fizzle program
    printf("exit code of fizzle program = %d\n", exitcode); // print exit code of fizzle program
}

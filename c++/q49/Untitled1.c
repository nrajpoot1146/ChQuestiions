#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

int flagSigInt = 1; // flag variable for ctrl+c attack

// a function that handle ctrl+c attack
void handlerForSigInt(int sig_num){
    signal(SIGINT, handlerForSigInt); // reset handler to catch next SIGINT attack
    printf("\n Ctrl+C attack handled successfully.\n");
    fflush(stdout);
}

void main(){
    clock_t start_time = clock(); // start clock
    signal(SIGINT, handlerForSigInt);// start ctrl + c attack handler
    printf("\n Ctrl+c attack handler started and stopped after 5 second.\n");
    while(1){
        clock_t end_time = clock(); // get current clock value
        clock_t timeEla = (end_time - start_time) / CLOCKS_PER_SEC; // calculate seconds
        if (timeEla == 5 && flagSigInt){
            printf("\n Ctrl+c attack handler stopped. now you can press ctrl+c to close program.\n");
            signal(SIGINT,SIG_DFL); // reset SIGINT to default
            flagSigInt = 0; // stop ctrl+c handler
        }
    }
}

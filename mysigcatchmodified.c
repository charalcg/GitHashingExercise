#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// global variable to keep track of SIGINT signals received :
int sigint_count = 0; 

void signal_handler(int sig) {
    if (sig == SIGINT) {
        sigint_count++; 
        printf("\n\nCaught SIGINT (== signal value %d)! Current execution SIGINT-count : %d\n\n", sig, sigint_count);

        if (sigint_count == 2) {
            printf("\nSIGINT was caught twice, restoring default (DFL) behavior..\n");
            printf("The program will now terminate if it receives another SIGINT\n\n");

            signal(SIGINT, SIG_DFL); 
        }
    }
}

int main() {
    
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        printf("Error while registering the signal handler\n");
        return 1;
    }

    printf("At any point during the execution, press Ctrl+C to trigger SIGINT.\n");
    printf("After two SIGINTs, the program will terminate gracefully.\n");

    printf("\n");
    while (1){
        printf("Running... (press Ctrl+C at any moment)\n");
        sleep(1);
    }

    return 0;
}


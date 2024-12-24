#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    switch(sig) {
        case SIGINT: 
            printf("\nSIGINT (== value %d) caught!\n", sig);
            exit(0);
            break;
        case SIGTERM:
            printf("\nSIGTERM caught! Terminating gracefully.\n");
            exit(0);
            break;
        default:
            printf("\nSignal %d caught.\n", sig);
    }
}


int main() {
    // this is where we tell C that when SIGINT is caught by 'signal' => invoke signal_handler
    if(signal(SIGINT, signal_handler) == SIG_ERR){
        printf("Error while registering the signal");
        return 1;
    }

    printf("At any point during the execution, press Ctrl+C to trigger SIGINT and gracefully stop the program.\n\n");

    while(1){
        printf("Running... (press Ctrl+C for graceful exit)\n");
        sleep(1); // pause the execution for one second to give time to the program to catch any potential signals
    }

    return 0;
}


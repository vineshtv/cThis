#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signo)
{
    switch (signo)
    {
        case SIGINT:
        {
            printf("Caught SIGINT, exiting now\n");
            exit(0);
        }
        break;

        case SIGHUP:
        {
            printf("Cauught SIGHUP. Doing nothing now\n");
        }
        break;

        default:
            printf("Error: Caught the wrong signal");
            break;
    }
    if(signo == SIGINT)
    {
        //Printf is generally not safe to use in a signal handler as it is not reentrant.
        printf("SIGINT signal received\n");
    }
}

int main()
{
    if(signal(SIGINT, sig_handler) == SIG_ERR)
    {
        printf("Error: Cannot catch SIGINT.\n"); //Should never happen
    }

    if(signal(SIGHUP, sig_handler) == SIG_ERR)
    {
        printf("Error: Cannot catch SIGHUP.\n"); //Should never happen
    }

    if(signal(SIGKILL, sig_handler) == SIG_ERR)
    {
        printf("Error: Cannot catch SIGKILL.\n"); //Should always happen
        printf("You can never handle SIGKILL anyway... \n");
    }

    while(1)
    {
        sleep(1);
    }
    return 0;
}

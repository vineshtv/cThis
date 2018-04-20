/*
 * A simple program which registers a signal handler function with kernel 
 * using the signal utility. The signal handler handles the SIGINT and SIGHUP signals.
 *
 * Usage:
 *  Compile and run this program.
 *  It prints the PID. Use this pid to send the signals.
 *
 *  kill -HUP <PID>
 *  kill -SIGINT <PID>
 */
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
            // Printfs are a strict no no in signal handlers as they are not reentran or thread safe.
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
}

int main()
{
    printf("My PID is : %d.\n\n", getpid());

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

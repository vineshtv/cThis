/*
 *  A simple eventloop implementation.
 *
 *  Child writes to a pipe and the parent listens to it from an epoll based event loop.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdbool.h>

#define MAXEVENTS 64

int main(int argc, char *argv[])
{
    struct  epoll_event     event;
    struct  epoll_event     *events;
    
    /* For this example the number of messages transferred between the writer and the reader is 5 */
    int     msgCount = 5;

    int     pipeFds[2]; // 0 is the read end and 1 is the write end.
    char    buf[30];

    if(pipe(pipeFds) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid_t   pid = fork();

    if(0 == pid)
    { 
        // Child
        int i;
        for(i = 0; i < msgCount; i++)
        {
            sleep(5);
            write(pipeFds[1], "test", 5);
        }
        exit(0);
    }
    else if(pid > 0)
    {
        // Parent
        int epollFd;
        int s;
        int msgReceived = 0;

        // Create the epoll instance
        epollFd = epoll_create1(0);

        // Allocate events array
        events = calloc(MAXEVENTS, sizeof event);

        // Register read end of pipe using edge-triggered mode.
        event.data.fd = pipeFds[0];
        // EPOLLIN - The associated fd is available for read.
        // EPOLLET - Edge triggered(ET). The default option is LEVEL_TRIGGERED(LT).
        //              The difference between ET and LT is that in case of ET, an event will be returned only if 
        //              there is a change in the monitored fd whereas in case of LT, it will keep returning events
        //              until everything is read for the fd.
        event.events = EPOLLIN | EPOLLET;
        
        s = epoll_ctl(epollFd, EPOLL_CTL_ADD, pipeFds[0], &event);

        if (s == -1)
        {
            fprintf(stderr, "epoll_ctl failed \n");
            return 1;
        }

        bool done = false;
        
        /* The event loop */
        while(1)
        {
            int n, i;

            n = epoll_wait(epollFd, events, MAXEVENTS, -1);

            for(i = 0; i < n; i++)
            {
                int count, s;
                
                count = read(events[i].data.fd, buf, sizeof buf);

                s = write(1, buf, count);

                msgReceived++;
                if (msgReceived == msgCount)
                {
                    done = true;
                }
            }

            if (done)
            {
                free(events);
                close(epollFd);
                break;
            }
        }
    }
    else
    {
        // fork failed
        fprintf(stderr, "fork() failed! \n");
        return 1;
     }

    return 0;
}

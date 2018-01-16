/*
 *  execvExample.c
 *
 *  A simple example which shows how to use execv to replace 
 *  the child process with a different process.
 *  
 *  In this case the target program looks like the following 
 *
 *   #include<stdio.h>
 *   int main(int argc, char *argv[])
 *   {
 *       printf("From target : ");
 *       printf("%s\n", argv[1]);
 *   }
 *
 *  which is compiled as follows
 *      gcc target.c -o target
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() 
{
    // First argument is mandatory and must contain the name of 
    // the executable file for the new process image
    // remaining pointers are passed as arguments to the new process
    // NULL represents the end of the pointer list.
    char *const ptrList[] = {"target", "param1", NULL}; 
    
    pid_t pid = fork();

    if(0 == pid)
    {
        // Child
        execv("target", ptrList);

        // execv replaces the process image with the new process image.
        // So it must not return unless something has gone wrong.
        printf("Return not expected. \n");
    }
    else if (0 < pid)
    {
        // Parent
        printf("From Parent.\n");
    }
    else
    {
        // fork failed
        printf("fork() failed! \n");
        return 1;
    }

    return 0;
}

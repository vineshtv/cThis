/*
 * strcpy() implementation in c. 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* mystrcpy(const char *source, char *dest)
{
    dest = (char*) malloc(sizeof(char) * strlen(source));
    char* destptr = dest;
    while(*source)
    {
        *destptr++ = *source++;
    }
    
    return dest;
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Requires an input string");
        return 1;
    }

    char *dest = mystrcpy(argv[1], dest);

    printf("Copied String = %s\n", dest);

    return 0;
}

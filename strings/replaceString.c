/*
 *  Implements a function which takes in a source string, a char s and a destination string 
 *  and replace all the occurence of the char s in the source string with the destination string.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* stringReplace(char *str, char *s, char* d)
{
    char* result = (char *)malloc(100 * sizeof(char));
    char* resultptr = result;
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == s[0])
        {
            int j;
            for(j = 0; j < strlen(d); j++)
            {
                *resultptr++ = d[j];
                //resultptr++;
            }
        }
        else
        {
            *resultptr++ = str[i];
            //resultptr++;
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        printf("Requires three arguments - Source string, string to be replaced and the string to be replaced with \n");
        return 1;
    }
    
    char* finalString = stringReplace(argv[1], argv[2], argv[3]);

    printf("Final string : %s\n", finalString);
    return 0;
}

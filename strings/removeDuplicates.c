/*
 * A function which removes duplicates from a string in place.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void removeDuplicates(char *str)
{
    //Hash table to check if there is already an entry
    int hash[256] = {0};
    //source and destination pointer.
    int sp = 0, dp = 0;
    char temp;
    
    while(*(str + sp))
    {
        temp = *(str + sp);
        if(hash[temp] == 0)
        {
            //Not a duplicate. 
            hash[temp] = 1;
            *(str + dp) = *(str + sp);
            dp++;
        }
        sp++;
    }

    //Add a '\0' at the end of the string to terminate at the correct point.
    *(str + dp) = '\0';

    int i;
    for(i = 0; i < 256; i++)
    {
        printf("%d ", hash[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("requires an input string.\n");
        return 1;
    }
    removeDuplicates(argv[1]);
    printf("Final String : %s\n", argv[1]);
    return 0;
}

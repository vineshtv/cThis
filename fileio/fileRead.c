#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        printf("Enter a filename as well!!\n");
        return 1;
    }

    char str[1000];
    FILE *fptr;

    //Open the file for read
    fptr = fopen(argv[1], "r");
    
    if(!fptr)
    {
        printf("Error opening file!!!\n");
        exit(1);
    }

    while(fgets(str, sizeof(str), fptr) != NULL)
    {
        printf("%s", str);
    }

    fclose(fptr);

    return 0;
}

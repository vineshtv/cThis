/*
 *  Dynamically allocate a 2D char array and read inputs to the array.
 *  Once read, pass this array to another function which converts all of the 
 *  chars to upper case.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char ** fillArray(int *size)
{
    int n;
    printf("Enter the number of String: ");
    scanf("%d", &n);

    printf("Enter %d strings: \n", n);

    char** s = (char **)malloc(n * sizeof(char *));
    int i;
    for(i = 0; i < n; i++)
    {
        s[i] = (char *) malloc(100 * sizeof(char));
        scanf("%s", s[i]);
    }

    *size = n;
    return s;
}

void changeArray(int n, char** str)
{
    int i;
    for(i = 0; i < n; i++)
    {
        int j;
        for(j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = toupper(str[i][j]);
        }
    }
}

int main()
{
    int size = 0;
    char** s = fillArray(&size);

    changeArray(size, s);

    int i;
    printf("The strings are :\n");
    for(i = 0; i < size; i++)
    {
        printf("%s\n", s[i]);
    }

    return 0;
}

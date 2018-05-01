/*
 * Checks for palindrome. Ignores whitespaces, special characters and cases.
 * i.e. "I am :IronnorI Ma, i" is a palindrome.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

bool checkPalindrome(char* str)
{
    int i = 0, j = strlen(str) - 1;

    bool palindrome = true;
    while(i < j)
    {
        while(!isalnum(str[i]))
        {
            i++;
        }
        while(!isalnum(str[j]))
        {
            j--;
        }
        
        if(i >= j)
        {
            break;
        }

        if(tolower(str[i]) != tolower(str[j]))
        {
            palindrome = false;
            break;
        }
        else
        {
            i++;
            j--;
        }
    }
    
    return palindrome;
}

int main()
{
    char *s;

    printf("Enter the string: ");
    scanf("%[^\n]s", s);

    if(checkPalindrome(s))
    {
        printf("\nEntered string is a palindrome.\n");
    }
    else
    {
        printf("\nEntered string is not a palindrome.\n");
    }
    return 0;
}

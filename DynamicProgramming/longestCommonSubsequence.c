#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for(i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

/*
 * The 2D array L for this example is as follows
    0  0  0  0  0  0  0  0  0
    0  0  0  0  0  0  1  1  1
    0  1  1  1  1  1  1  1  1
    0  1  1  1  1  1  1  1  1
    0  1  1  2  2  2  2  2  2
    0  1  1  2  2  2  3  3  3
    0  1  1  2  2  2  3  3  4

    We backtrack from index (m, n) and travel back in the order of the highest value.
*/
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if(X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            index--;
            i--;
            j--;
        }
        else if(L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("LCS is %s\n", lcs);
    return L[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of the LCS = %d", lcs(X, Y, m, n));
    return 0;
}

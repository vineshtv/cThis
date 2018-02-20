#include <stdio.h>
int fib(int n)
{
    /*
     * This is the normal method using recursion.
    if(n <= 1)
    {
        return n;
    }

    return (fib(n - 1) + fib(n - 2));
    */

    /*
     * Using Dynamic programming
     */
    int f[n+1];
    int i;

    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    return (f[n]);
}

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    printf("\n%dth fibonacci number = %d\n", n, fib(n));
    return 1;
}

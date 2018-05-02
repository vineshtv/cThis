#include<stdio.h>
#include<stdlib.h>

int insertAndFindMedian(int a[], int n)
{
    static int l = 0;
    int i = 0;

    while(i < l && n > a[i])
    {
        i++;
    }

    int j;
    for(j = l; j > i; j--)
    {
        a[j] = a[j - 1];
    }
    a[j] = n;
    l++;

    if(l % 2 == 1)
    {
        return a[l/2];
    }
    else
    {
        return((a[l/2 - 1] + a[l/2]) / 2);
    }
}

int main()
{
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int *num = (int *)malloc(sizeof(int) * n);
    printf("\nEnter %d numbers:\n", n);
    int i;
    for(i = 0; i < n; i++)
    {
        int n1;
        scanf("%d", &n1);
        printf("Current median = %d\n", insertAndFindMedian(num, n1));
    }

    return 0;
}

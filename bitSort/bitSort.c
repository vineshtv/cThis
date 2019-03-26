#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int countBits(int n)
{
    return (int)log2(n)+1;
}

int findMax(int a[], int n)
{
    int max = INT_MIN;
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int partition(int a[], int low, int high, int msbBitPos)
{
    int mask = ~(1 << (msbBitPos - 1));
    int i = low;
    int j = high;

    while(i < j)
    {
        while((a[i] | mask) == mask)
        {
            i++;
            if(i > high)
                break;
        }

        while((a[j] | mask) != mask)
        {
            j--;
            if (j < low)
                break;
        }

        if (i <= j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    return i - 1;
}

void bitSort(int a[], int low, int high, int msbBitPos)
{
    if (msbBitPos == 0){
        return;
    }

    if (low < high)
    {
        int x = partition(a, low, high, msbBitPos);
        
        bitSort(a, low, x, msbBitPos - 1);
        bitSort(a, x + 1, high, msbBitPos - 1);
    }
}

int main(int argv, char** argc)
{
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("\nEnter %d numbers: ", n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max = findMax(a, n);
    int msbBitPos = countBits(max);
    bitSort(a, 0, n - 1, msbBitPos);

    printf("Sorted Numbers : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 * Implement the quicksort algorithm
 */

#include<stdio.h>
#include<stdlib.h>
/*
 * Partition function - This function takes as input a sub array and partitions it. 
 * The partitioning logic is as follows.
 *
 * 1. Choose a pivot. In this case it chooses the last element of the passed in subarray. i.e. a[high]
 * 2. Find the correct position for the pivot element. 
 *      i.e. run through the array and position pivot such that every element less than the pivot 
 *      comes in before the pivot element and every element greater than the pivot comes after the pivot.
 *      (Here we run pointers from either end of the array and reposition the elements accordingly)
 * 3. Return the index of the pivot element after step 2.
 */
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low;
    int j = high - 1;

    /* Run the loop until i and j point to the same location */
    while(i <= j)
    {
        if(a[i] > pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j--;
        }
        else
        {
            i++;
        }
    }

    /* Move the pivot element to the correct position */
    int temp = a[i];
    a[i] = a[high];
    a[high] = temp;

    /* Return the position of the pivot element. */
    return i;
}

/*
 *  The main quicksort function. This is the recursive function which calls the partition function and then recusively 
 *  call the quicksort function on each of the partition.
 */
void quicksort(int a[], int low, int high)
{   
    if(low < high)
    {
        int x = partition(a, low, high);

        quicksort(a, low, x - 1);
        quicksort(a, x + 1, high);
    }
}

int main(int argv, char** argc)
{
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int* a = (int *)malloc(sizeof(int) * n);
    printf("\nEnter %d numbers: ", n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Numbers = ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    
    quicksort(a, 0, n - 1);
    printf("Sorted numbers = ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

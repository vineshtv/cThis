/*
 * This program tries to find the largest contigous sub array sum from an array
 */

#include<limits.h>
#include<stdio.h>
int kadane_max_subarray_sum(int a[], int n)
{
    /*
     *  The name of the algorithm is Kadane's algorithm.
     *  The basic idea is to traverse through the array and find all the 
     *  positive contigous subarrays, and keep track of the one with the largest sum
     *
     *  global_max = INT_MIN
     *  max_till_now = 0
     *
     *  loop through the array - 
     *      max_till_now += current_element
     *      if max_till_now > global_max
     *          global_max = max_till_now
     *
     *      if max_till_now < 0
     *          max_till_now = 0
     *
     *  return global_max
     */
    int global_max = INT_MIN;
    int max_till_now = 0;
    int i;

    for(int i = 0; i < n; i++)
    {
        max_till_now += a[i];

        if(max_till_now > global_max)
        {
            global_max = max_till_now;
        }

        if(max_till_now < 0)
        {
            max_till_now = 0;
        }
    }
    return global_max;
}

int main()
{
    int a1[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int a2[] = {1, 2, 3, 4, 5};
    int a3[] = {-1, -2, -3, -4, -5};

    printf("Max contiguous subarray sum for a1 = %d \n", kadane_max_subarray_sum(a1, sizeof(a1)/sizeof(a1[0])));
    printf("Max contiguous subarray sum for a2 = %d \n", kadane_max_subarray_sum(a2, sizeof(a2)/sizeof(a2[0])));
    printf("Max contiguous subarray sum for a3 = %d \n", kadane_max_subarray_sum(a3, sizeof(a3)/sizeof(a3[0])));

    return 0;
}

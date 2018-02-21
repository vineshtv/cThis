/*
 * This program tries to find the largest contigous sub array sum from an array
 */

#include<limits.h>
#include<stdio.h>
void kadane_max_subarray_sum(int a[], int n)
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
    int start_index = 0; 
    int end_index = 0;
    int temp_start = 0;
    for(int i = 0; i < n; i++)
    {
        max_till_now += a[i];

        if(max_till_now > global_max)
        {
            global_max = max_till_now;
            start_index = temp_start;
            end_index = i;
        }

        if(max_till_now < 0)
        {
            max_till_now = 0;
            temp_start = i + 1;
        }
    }

    printf("Max contiguous subarray sum = %d \n", global_max);
    printf("Start index = %d and end index = %d", start_index, end_index);
}

int main()
{
//    int a1[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int a1[] = {1, 2, -3, -4, 5, -6, 7, -7};
    kadane_max_subarray_sum(a1, sizeof(a1)/sizeof(a1[0]));

    return 0;
}

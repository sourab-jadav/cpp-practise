#include <bits/stdc++.h>
using namespace std;
int maxSubarrayProduct(int arr[], int n)
{
    // max positive product
    // ending at the current position
    int max_ending_here = 1;
    //
    // min negative product ending
    // at the current position
    int min_ending_here = 1;
    // Initialize overall max product
    int max_so_far = 0;
    int flag = 0;
    /* Traverse through the array.
    Following values are
    maintained after the i'th iteration:
    max_ending_here is always 1 or
    some positive product ending with arr[i]
    min_ending_here is always 1 or
    some negative product ending with arr[i] */
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update
        max_ending_here. Update min_ending_here only if
        min_ending_here is negative */
        if (arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);
            flag = 1;
        }
        /* If this element is 0, then the maximum product
        cannot end here, make both max_ending_here and
        min_ending_here 0
        Assumption: Output is always greater than or equal
        to 1. */
        else if (arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }
        /* If element is negative. This is tricky
        max_ending_here can either be 1 or positive.
        min_ending_here can either be 1 or negative.
        next max_ending_here will always be prev.
        min_ending_here * arr[i] ,next min_ending_here
        will be 1 if prev max_ending_here is 1, otherwise
        next min_ending_here will be prev max_ending_here *
        arr[i] */
        else
        {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
        // update max_so_far, if needed
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    if (flag == 0 && max_so_far == 0)
        return 0;
    /* if all the array elements are negative */
    if (max_so_far == 1)
    {
        max_so_far = arr[0];
        for (int i = 1; i < n; i++)
            max_so_far = max(max_so_far, arr[i]);
    }
    return max_so_far;
}
int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}

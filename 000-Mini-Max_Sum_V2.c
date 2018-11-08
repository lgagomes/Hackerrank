/*
https://www.hackerrank.com/challenges/mini-max-sum/problem

Given five positive integers, find the minimum and maximum values that
can be calculated by summing exactly four of the five integers. Then
print the respective minimum and maximum values as a single line of two
space-separated long integers.

Input Format: A single line of five space-separated integers.

Constraints:  Each integer is in the inclusive range [1 ... 10^9].

Output Format: Print two space-separated long integers denoting
the respective minimum and maximum values that can be calculated by
summing exactly four of the five integers. (The output can be greater
than a 32 bit integer.)

Sample Input: 1 2 3 4 5

Sample Output: 10 14

Explanation: Our initial numbers are 1, 2, 3, 4 and 5. We can calculate
the following sums using four of the five integers:

    If we sum everything except 1, our sum is 2+3+4+5 = 14.
    If we sum everything except 2, our sum is 1+3+4+5 = 13.
    If we sum everything except 3, our sum is 1+2+4+5 = 12.
    If we sum everything except 4, our sum is 1+2+3+5 = 11.
    If we sum everything except 5, our sum is 1+2+3+4 = 10.

Hints: Beware of integer overflow! Use 64-bit Integer.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

void miniMaxSum(int arr_size, int64_t* arr) {
    int64_t *sum = malloc(sizeof(int64_t) * arr_size),
        min,
        max;

    int j,
        k,
        index = 0;

    memset(sum, 0, arr_size*sizeof(int64_t));

    min = INT_MAX;
    max = 0;

    for (k=0; k<arr_size; k++)
    {
       for(j=0; j<arr_size; j++)
        {
            if (j == index)
                sum[k] += 0;
            else
                sum[k] += arr[j];
        }
        //printf("%ld\n", sum[k]);

        if (sum[k] < min)
            min = sum[k];

        if (sum[k] > max)
            max = sum[k];

        index++;
    }

    printf("\nmin = %d\n", min);
    printf("max = %d\n", max);

    free(sum);
}

int main() {
    int64_t *arr = malloc(sizeof(int64_t) * 5);

    int arr_i;

    for (arr_i = 0; arr_i < 5; arr_i++) {
       scanf("%ld",&arr[arr_i]);
    }
    miniMaxSum(5, arr);
    return 0;
}

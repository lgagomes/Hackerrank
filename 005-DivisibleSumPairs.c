/*
https://www.hackerrank.com/challenges/divisible-sum-pairs/problem

You are given an array of integers n, a0,a1,...,an-1 and a positive integer k.
Find and print the number of (i,j) pairs where i<j and ai+aj is divisible by k.

Input Format:
The first line contains 2 space-separated integers, n and k.
The second line contains n space-separated integers describing the values of
[a0,a1,...an-1].

Constraints
2 <= n <= 100
1 <= k <= 100
1 <= ai <= 100

Output Format
Print the number of (i,j) pairs where i<j and i+j is evenly divisible by k.

Sample Input
6 3
1 3 2 6 1 2

Sample Output
5

Explanation

Here are the 5 valid pairs when k=3:
(0,2) -> a0 + a2 = 1+2=3
(0,5) -> a0 + a5 = 1+2=3
(1,3) -> a1 + a3 = 3+6=9
(2,4) -> a2 + a4 = 2+1=3
(4,5) -> a4 + a5 = 1+2=3
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int divisibleSumPairs(int n, int k, int* ar) {

    int i=0,
        j,
        result = 0;

    // sums the ith element in ar[] with
    // all subsequents j elements, starting
    // with 0 towards n, always assuring that
    // i < j
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(((ar[i] + ar[j]) % k) == 0)
                result++;
    return result;
}

int main() {
    int n = 6;
    int k = 3;
    int *ar = malloc(sizeof(int) * n);
    int result;

    ar[0] = 1;
    ar[1] = 3;
    ar[2] = 2;
    ar[3] = 6;
    ar[4] = 1;
    ar[5] = 2;

    result = divisibleSumPairs(n, k, ar);
    printf("%d\n", result);
    free(ar);
    return 0;
}

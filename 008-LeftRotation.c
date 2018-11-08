/*
https://www.hackerrank.com/challenges/array-left-rotation/problem

A left rotation operation on an array of size n shifts each of the
array's elements 1 unit to the left. For example, if 2 left rotations
are performed on array [1,2,3,4,5], then the array would become
[3,4,5,1,2].

Given an array of n integers and a number, d, perform d left rotations
on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective
values of n (the number of integers) and (the number of left rotations you must
perform). The second line contains n space-separated integers describing the
respective elements of the array's initial state.

Constraints
1 <= n <= 10^5
1 <= d <= n
1 <= a(i) < 10^6

Output Format
Print a single line of n space-separated integers denoting the final state of
the array after performing d left rotations.

Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4

Explanation
When we perform d = 4 left rotations, the array undergoes the following
sequence of changes:
[1,2,3,4,5] -> [2,3,4,5,1] -> [3,4,5,1,2] -> [4,5,1,2,3] -> [5,1,2,3,4]

Thus, we print the array's final state as a single line of space-separated
values, which is 5 1 2 3 4.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5,
        d = 4,
        i,
        j,
        temp,
        rot;

    int *res = malloc(sizeof(int) * n);
    int *arr = malloc(sizeof(int) * n);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    for(i=0; i<n; i++)
        printf("%d ",arr[i]);

    printf("\n");

    // method 1
    /*
    for(i=0; i<d; i++)
    {
        temp = arr[0];
        for(j=0; j<n; j++)
        {
            if(j == n-1)
                arr[j] = temp;
            else
                arr[j] = arr[j+1];
        }
    }
    */

    // method 2
    for(i=0; i<n; i++)
        res[(i + n - d) % n] = arr[i];

    for(i=0; i<n; i++)
        printf("%d ",res[i]);

    free(res);
    free(arr);
    return 0;
}

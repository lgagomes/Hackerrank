/*
https://www.hackerrank.com/challenges/tutorial-intro/problem

Input Format
There will be three lines of input:

V - the value that has to be searched.
n - the size of the array.
arr - 'n' integers that make up the array arr(a0,a1,... an-1).

Output Format
Output the index of V in the array.

Sample Input
4
6
1 4 5 7 9 12

Sample Output
1

Explanation
V = 4. The value 4 is the 2nd element in the array, but its
index is 1 since in this case, array indexes start from 0

It is guaranteed that 'V' will occur in 'arr' exactly once.
*/

#include <stdio.h>
#include <stdlib.h>

int MyBinarySearch(int V, int arr_size, int* arr) {
    int begin = 0,
        end = arr_size,
        middle = (begin + end) / 2;

    while(begin <= end)
    {
        if(arr[begin] == V)
            return begin;

        else if(arr[middle] == V)
            return middle;

        else if(arr[end] == V)
            return end;

        else
        {
            if(V > arr[middle]) // gets the upper half of the array
                begin = middle;

            else if(V < arr[middle]) // gets the lower half of the array
                end = middle;

            middle = (begin + end) / 2;
        }
    }
    return -1;
}

int main() {
    int V, n, i, arr_i;
    scanf("%i", &V);
    scanf("%i", &n);

    int *arr = malloc(sizeof(int) * n);
    for (arr_i = 0; arr_i < n; arr_i++)
       scanf("%i",&arr[arr_i]);

    int result = MyBinarySearch(V, n, arr);
    printf("%d\n", result);
    return 0;
}

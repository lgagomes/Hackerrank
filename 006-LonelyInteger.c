/*
https://www.hackerrank.com/challenges/lonely-integer/problem

You will be given an array of integers. All of the integers
except one occur twice. That one is unique in the array.Given
an array of integers, find and print the unique element.

Input Format
The first line contains a single integer, n, denoting the
number of integers in the array. The second line contains n
space-separated integers describing the respective values in a.

Constraints
1 <= n <= 100
It is guaranteed that n is an odd number and that there is one unique element.
0 <= a(i) <= 100, where, 0 <= i< n.

Output Format
Print the unique integer in the array.

Sample Input 0
1
1

Sample Output 0
1

Explanation 0
There is only one element in the array, thus it is unique.

Sample Input 1
3
1 1 2

Sample Output 1
2

Explanation 1
We have two 1's, and 2 is unique.

Sample Input 2
5
0 0 1 2 1

Sample Output 2
2

Explanation 2
We have two 0's, two 1's, and one 2. 2 is unique.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lonelyinteger(int a_size, int* a) {

    int unique=0;
    int i;

//  XOR solution
//  if you take a ^ a, you will always get 0.
//  Furthermore, if you take a ^ x ^ a, you
//  will always get x


    for(i=0; i<a_size; i++)
        unique = unique ^ a[i];

// hard-working solution
/*
    int i,
        j,
        unique=0,
        dirty_arr[a_size]; // array of "dirty positions"

    for(i=0; i<a_size; i++)     // copy the original array, to don't mess up
        dirty_arr[i] = a[i];    // the original data

    if(a_size == 1)
        return a[0];
    else
    {
        for(i=0; i<a_size; i++)
            for(j=i+1; j<a_size; j++)
                if(a[i] == a[j])
                {
                    dirty_arr[i] = 101;     //if there are duplicates, we mark the duplicates positions
                    dirty_arr[j] = 101;     // as dirty
                }

    }

    for(i=0; i<a_size; i++)         // search in the dirty array for the "clean" position
        if(dirty_arr[i] != 101)     // the clean position contains the unique number
            unique = dirty_arr[i];
*/
    return unique;
}

int main() {
    int n = 5;
    int *a = malloc(sizeof(int) * n);

    //a[0] = 1;

    /*
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    */

    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    a[4] = 1;


    int result = lonelyinteger(n, a);
    printf("%d\n", result);
    free(a);
    return 0;
}

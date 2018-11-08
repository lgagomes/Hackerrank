/*
https://www.hackerrank.com/challenges/and-product/problem

Consider two non-negative long integers, 'a' and 'b', where a <= b.
The bitwise AND of all long integers in the inclusive range between 'a'
and 'b' can be expressed as:

a & (a+1) & ... (b-1) & b,

where '&' is the bitwise AND operator.

Given 'n' pairs of long integers, a[i] and b[i], compute and print the
bitwise AND of all natural numbers in the inclusive range between a[i] and b[i].

For example, if  = 10 and b=14, the calculation is 10 & 11 & 12 & 13 & 14 = 8

Input Format
The first line contains a single integer 'n', the number of intervals to test.
Each of the next 'n' lines contains two space-separated integers a[i] and b[i].

Constraints
1 <= n <= 200
0 <= a[i] <= b[i] < 2^32

Output Format
For each pair of long integers, print the bitwise AND of all numbers in the
inclusive range between a[i] and b[i] on a new line.

Sample Input 0
3
12 15
2 3
8 13

Sample Output 0
12
2
8

Explanation 0
There are three pairs to compute results for:
1. a= 12, b=15
    12 &13 & 14 & 15 = 12

2. a = 2, b = 3
    2 & 3 = 2

3. a = 8, b = 13
    8 & 9 & 10 & 11 & 12 & 13 = 8
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
https://stackoverflow.com/questions/31949524/bitwise-and-for-range-of-numbers
https://discuss.codechef.com/questions/73655/bitwise-and-for-range-of-numbers
*/

long int andProduct(long int a, long int b) {

    long int step = 1;
    while(a!=b)
    {
        a/=2;
        b/=2;
        step*=2;
    }
    return a*step;
}

int main() {
    int n, a0;
    scanf("%i", &n);
    for(a0 = 0; a0 < n; a0++){
        long int a;
        long int b;
        scanf("%li %li", &a, &b);
        long int result = andProduct(a, b);
        printf(" >>> %ld\n", result);
    }
    return 0;
}

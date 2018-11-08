/*
https://www.hackerrank.com/challenges/birthday-cake-candles/problem

Colleen is having a birthday! She will have a cake with one candle for each year of her age.
When she blows out the candles, she’ll only be able to blow out the tallest ones.
Find and print the number of candles she can successfully blow out.

Input Format:
The first line contains a single integer, n, denoting the number of candles on the cake.
The second line contains n space-separated integers, where each integer i describes the height of candle i.

Constraints:
1 <= n <= 10^5
1 <= height(i) <= 10^7

Output Format:
Print the number of candles the can be blown out on a new line.

Sample Input 0:
4
3 2 1 3

Sample Output 0:
2

Explanation 0:
The maximum candle height is 3 and there are two candles of that height.

Sample Input 1:
10
44 53 31 27 77 60 66 77 26 36

Sample Output 1:
2

Explanation 1:
The maximum candle height is 77 and there are two candles of that height.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int birthdayCakeCandles(int n, int ar_size, int* ar) {

    int i,
        max_value = 0,
        cont = 0;

    for (i=0; i<n; i++)
        if(ar[i] > max_value)
           max_value = ar[i];

    printf("max_value: %d\n",max_value);

    for (i=0; i<n; i++)
        if(ar[i] = max_value)
            cont++;

    return cont;
}

int main() {
    int n, ar_i;

    scanf("%i", &n);

    int *ar = malloc(sizeof(int) * n);
    for(ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = birthdayCakeCandles(n, n, ar);
    printf("\n%d\n", result);
    return 0;
}

/*
https://www.hackerrank.com/challenges/the-birthday-bar/problem

Lily has a chocolate bar consisting of a row of n squares where
each square has an integer written on it. She wants to share it
with Ron for his birthday, which falls on month m and day d.
Lily wants to give Ron a piece of chocolate only if it contains
m consecutive squares whose integers sum to d.

Given m, d, and the sequence of integers written on each square of
Lily's chocolate bar, how many different ways can Lily break off
a piece of chocolate to give to Ron?

For example, if m = 2, d = 3 and the chocolate bar contains squares with the
integers [1,2,1,3,2] written on them from left to right, the following diagram
shows two ways to break off a piece:
1+2=3
2+1=3
1+3=4
3+2=5

Input Format:
The first line contains an integer denoting n (the number of squares in the chocolate bar).
The second line contains n space-separated integers describing the respective values of
s0, s1,...sn-1(the numbers written on each consecutive square of chocolate). The third line contains
two space-separated integers describing the respective values of d (Ron's birth day) and m
(Ron's birth month).

Constraints:
1 <= n <= 100
1 <= si <= 5, where 0 <= i <= n
1 <= d <= 31
1 <= m <= 12

Output Format:
Print an integer denoting the total number of ways that Lily can give a piece of chocolate to Ron.

Sample Input 0:
5
1 2 1 3 2
3 2

Sample Output 0:
2

Explanation 0:
This sample is already explained in the problem statement.

Sample Input 1
6
1 1 1 1 1 1
3 2

Sample Output 1
0

Explanation 1
Lily only wants to give Ron m = 2 consecutive squares of chocolate whose integers sum to
d = 3. There are no possible pieces satisfying these constraints:
[1,1,1,1,1,1]

1+1=2
1+1=2
1+1=2
1+1=2
1+1=2
1+1=2

Thus,
we print 0 as our answer.

Sample Input 2
1
4
4 1

Sample Output 2
1

Explanation 2
Lily only wants to give Ron m = 1 square of chocolate with an integer value of d = 4. Because the only
square of chocolate in the bar satisfies this constraint, we print as 1 our answer.
*/

#include <stdio.h>
#include <stdlib.h>
void solve(int n, int* s, int d, int m){
    /*
    m = number of consecutive integers to sum (size of sliding window)
    d = result of the sum of m integers

    sliding window of size 2 in a array of size 5
    [_ _ _ _ _] initial state (no window)

    [* * _ _ _] 1st sum
    [_ * * _ _] 2nd sum
    [_ _ * * _] 3rd sum
    [_ _ _ * *] 4th sum

    sliding window of size 3 in a array of size 5
    [_ _ _ _ _] initial state (no window)

    [* * * _ _] 1st sum
    [_ * * * _] 2nd sum
    [_ _ * * *] 3rd sum

    sliding window of size 4 in a array of size 5
    [_ _ _ _ _] initial state (no window)

    [* * * * _] 1st sum
    [_ * * * *] 2nd sum

    sliding window of size 2 in a array of size 6
    [_ _ _ _ _ _] initial state (no window)

    [* * _ _ _ _] 1st sum
    [_ * * _ _ _] 2nd sum
    [_ _ * * _ _] 3rd sum
    [_ _ _ * * _] 4th sum
    [_ _ _ _ * *] 5th sum

    sliding window of size 4 in a array of size 6
    [_ _ _ _ _ _] initial state (no window)

    [* * * * _ _] 1st sum
    [_ * * * * _] 2nd sum
    [_ _ * * * *] 3rd sum

    number of sums = (size of array - sliding window size) + 1
    */

    int i,
        result = 0,
        sliding_window[m],
        iterations,
        ctrl_1 = 0,
        ctrl_2,
        cont = 0;

    while(ctrl_2 != n)
    {
        ctrl_2 = ctrl_1;
        for(i=0; i<m; i++)
        {
            sliding_window[i] = s[ctrl_2];
            ctrl_2++;
        }

        for(i=0; i<m; i++)
            result += sliding_window[i];

        if(result == d)
            cont++;
        ctrl_1++;
        result = 0;
    }
    printf("%d\n",cont);
}
/*--------------------------------------------------------------*/
int main() {
    int n = 6;
    int *s = malloc(sizeof(int) * n);
    /*
    s[0] = 1;
    s[1] = 2;
    s[2] = 1;
    s[3] = 3;
    s[4] = 2;
    */

    s[0] = 1;
    s[1] = 1;
    s[2] = 1;
    s[3] = 1;
    s[4] = 1;
    s[5] = 1;

    int d = 3;
    int m = 2;
    solve(n, s, d, m);
    free(s);
    return 0;
}

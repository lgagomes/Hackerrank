/*
https://www.hackerrank.com/challenges/maximum-element/problem

You have an empty sequence, and you will be given N queries. Each
query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.

Input Format
The first line of input contains an integer, N. The next N lines each
contain an above mentioned query. (It is guaranteed that each query
is valid.)

Constraints
1 <= N <= 10^5
1 <= x <= 10^9
1 <= type <= 3

Output Format
For each type 3 query, print the maximum element in the stack on a new line.

Sample Input
10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

Sample Output
26
91
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    stack<int> s;
    int queries, val_1, val_2, maxVal;
    cin >> queries;
    while(queries--)
    {
        cin >> val_1;
        if(val_1 == 1)
        {
            cin >> val_2;

            /* doesn't need to put smaller values on
            the stack than what we already have */
            if(s.size() > 0)
                maxVal = s.top();
            else
                maxVal = val_2;

            s.push(max(val_2, maxVal));
        }
        else if(val_1 == 2)
            s.pop();
        else if(val_1 == 3)
            cout << s.top() << '\n';
    }
    return 0;
}

/*
https://www.hackerrank.com/challenges/equal-stacks/problem

You have three stacks of cylinders where each cylinder has
the same diameter, but they may vary in height. You can
change the height of a stack by removing and discarding
its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all
of the stacks are exactly the same height. This means you must
remove zero or more cylinders from the top of zero or more of
the three stacks until they're all the same height, then print
the height. The removals must be performed in such a way as to
maximize the height.

Note: An empty stack is still a stack.

Input Format
The first line contains three space-separated integers,'n1', 'n2',
and 'n3',describing the respective number of cylinders in stacks 1,
2, and 3. The subsequent lines describe the respective heights of
each cylinder in a stack from top to bottom:

The second line contains 'n1' space-separated integers describing the cylinder heights in stack 1.
The third line contains 'n2' space-separated integers describing the cylinder heights in stack 2.
The fourth line contains 'n3' space-separated integers describing the cylinder heights in stack 3.

Constraints
0 < n1,n2,n3 <= 10^5
0 < height of any cilinder <= 100

Output Format
Print a single integer denoting the maximum height at which
all stacks will be of equal height

Sample Input
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

Sample Output
5

Explanation
Initially, the stacks look like this:

3
2       1
1   4   1
1   3   4
1   2   1

Observe that the three stacks are not all the same height. To make
all stacks of equal height, we remove the first cylinder from stacks 1 and 2,
and then remove the top two cylinders from stack 3 (shown below).

2
1
1   3   4
1   2   1

As a result, the stacks undergo the following change in height:
1: 8 - 3 = 5
2: 9 - 4 = 5
3: 7 - 1 - 1 = 5

All three stacks now have height = 5. Thus, we print 5 as our answer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int i, j , k, l, flag =0,
        temp, sum_1=0, sum_2=0, sum_3=0;

    queue<int> queue_1, queue_2, queue_3;

    cin >> j >> k >> l;

    for(i=0; i<j; i++)
    {
        cin >> temp;
        sum_1+=temp;
        queue_1.push(temp);
    }

    for(i=0; i<k; i++)
    {
        cin >> temp;
        sum_2+=temp;
        queue_2.push(temp);
    }

    for(i=0; i<l; i++)
    {
        cin >> temp;
        sum_3+=temp;
        queue_3.push(temp);
    }

    /*
        after we have the total height of each stack,
        (sum_1, sum_2, sum_3) we subtract from this
        total height the value on top of their
        respective stack. Repeat this until every total
        height value is equal
    */

    while(flag==0)
    {
        if((sum_1 > sum_2) || (sum_1 > sum_3))
        {
            temp = queue_1.front();
            queue_1.pop();
            sum_1 -= temp;
        }

        if((sum_2 > sum_1) || (sum_2 > sum_3))
        {
            temp = queue_2.front();
            queue_2.pop();
            sum_2 -= temp;
        }

        if((sum_3 > sum_1) || (sum_3 > sum_2))
        {
            temp = queue_3.front();
            queue_3.pop();
            sum_3 -= temp;
        }

        if((sum_1 == sum_2) && (sum_2 == sum_3))
            flag = 1;
    }

    cout << sum_1 << endl;
    return 0;
}

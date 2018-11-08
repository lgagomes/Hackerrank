/*
https://www.hackerrank.com/challenges/sherlock-and-squares/problem

Watson likes to challenge Sherlock's math ability. He will provide
a starting and ending value describing a range of integers. Sherlock
must determine the number of square integers within that range,
inclusive of the endpoints.

Note: A square integer is an integer which is the square of an integer,
e.g. 1,4,9,16,25...

For example, the range is a = 24 and b = 49, inclusive. There are three
square integers in the range: 25,36 and 49.

Function Description
Complete the squares function in the editor below. It should return an
integer representing the number of square integers in the inclusive range
from 'a' to 'b'.

Squares has the following parameter(s):

a: an integer, the lower range boundary
b: an integer, the upper range boundary

Input Format
The first line contains 'q', the number of test cases.
Each of the next 'q' lines contains two space-separated integers denoting
'a' and 'b', the starting and ending integers in the ranges.

Constraints
1 <= q <= 100
1 <= a <= b <= 10^9

Output Format
For each test case, print the number of square integers in the range on a
new line.

Sample Input
2
3 9
17 24

Sample Output
2
0

Explanation
Test Case #00: In range [3,9], 4 and 9 are the two square integers.
Test Case #01: In range [17,24], there are no square integers.
*/

#include <iostream>
#include <math.h>

int squares(int a, int b) {

    return (floor(sqrt(b))- ceil(sqrt(a))) + 1;
}

int main() {

    int a,b,q;
    std::cin >> q;

    for(int i=0; i<q; i++)
    {
        std::cin >> a >> b;
        std::cout << squares(a,b);
    }

    return 0;
}

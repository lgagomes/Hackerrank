/*
https://www.hackerrank.com/challenges/sparse-arrays/problem

There is a collection of N strings (There can be multiple occurences
of a particular string). Each string's length is no more 20 than
characters. There are also Q queries. For each query, you are given
a string, and you need to find out how many times this string occurs
in the given collection of N strings.

Input Format
The first line contains N, the number of strings.
The next Nlines each contain a string.
The N+2nd line contains Q, the number of queries.
The following Q lines each contain a query string.

Constraints
1 <= N <= 1000
1 <= Q <= 1000
1 <= length of any string <= 20

Sample Input
4
aba
baba
aba
xzxb
3
aba
xzxb
ab

Sample Output
2
1
0

Explanation
Here, "aba" occurs twice, in the first and third string. The string
"xzxb" occurs once in the fourth string, and "ab" does not occur at all.
*/

#include <iostream>
#include <iterator>
#include <unordered_set>
using namespace std;

int main() {
    int n, q, i;
    string str;
    unordered_multiset<string> s;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> str;
        s.insert(str);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> str;
        cout << s.count(str) << '\n';
    }
}

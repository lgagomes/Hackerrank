/*
https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem

We say that a string contains the word 'hackerrank' if a
subsequence of its characters spell the word 'hackerrank'.
For example, if string s = 'haackkerrankk' it does contain 'hackerrank',
but s = 'haacckkerank' does not. In the second case, the second r is
missing. If we reorder the first string as 'hccaakkerrannkk it no longer
contains the subsequence due to ordering.

More formally, let p[0], p[1], ... p[9] be the respective indices of
h, a, c, k, e, r, r, a, n, k in string s. If p[0] < p[1] < p[2] < ... < p[9]
is true, then 's' contains hackerrank.

For each query, print YES on a new line if the string contains 'hackerrank',
otherwise, print NO.

Input Format

The first line contains an integer 'q', the number of queries.
Each of the next 'q' lines contains a single query string 's'.

Constraints
2 <= q <= 10^2
10 <= |s| <= 10^4

Output Format
For each query, print YES on a new line if contains hackerrank, otherwise, print NO.

Sample Input 0
2
hereiamstackerrank
hackerworld

Sample Output 0
YES
NO

Explanation 0
We perform the following q = 2 queries:

1. s= hereiamstackerrank
Because the string contains all the characters in hackerrank in the same exact order as
they appear in hackerrank, we print YES on a new line.

2. s = hackerworld
Does not contain the last three characters of hackerrank, so we print NO on a new line.
*/

#include <iostream>
#include <string>

using namespace std;

string hackerrankInString(string s) {

    string result, standard = "hackerrank";
    int j=0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == standard[j])
        {
            result += standard[j];
            j++;
            cout << result << endl;
        }
    }

    if(standard == result)
        return "YES";
    else
        return "NO";
}

int main()
{
    //int q;
    //cin >> q;
    string s,result;

    getline(cin, s);
    cout << s << endl;
    result = hackerrankInString(s);
    cout << result << "\n";

    /*
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        cout << result << "\n";
    }
    */
    return 0;
}

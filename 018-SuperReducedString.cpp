/*
https://www.hackerrank.com/challenges/reduced-string/problem

Steve has a string, 's', consisting of 'n'lowercase English alphabetic letters.
In one operation, he can delete any pair of adjacent letters with same value.
For example, string "aabcc" would become either "aab" or "bcc" after 1 operation.

Steve wants to reduce 's' as much as possible. To do this, he will repeat the
above operation as many times as it can be performed. Help Steve out by finding
and printing s's non-reducible form!

Note: If the final string is empty, print Empty String.

Input Format
A single string, 's'.

Constraints
1<= n <= 100

Output Format
If the final string is empty, print Empty String; otherwise, print the final non-reducible string.

Sample Input 0
aaabccddd

Sample Output 0
abd

Explanation 0
Steve can perform the following sequence of operations to get the final string:

aaabccddd -> abccddd
abccddd -> abddd
abddd -> abd

Thus, we print abd.
*/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Complete the super_reduced_string function below.
string super_reduced_string(string s) {

    string upper, lower;

    for(int i=1; i<s.length(); i++)
    {
        if(s[i-1] == s[i])
        {
            if(i == s.length())
            {
                upper = s.substr(0, i-1);
                s = upper;
            }
            else
            {
                upper = s.substr(0, i-1);
                lower = s.substr(i+1, s.length());
                s = upper + lower;
            }
            i = 0;
        }
    }
    if(s.length() == 0)
        return "Empty String";
    else
        return s;
}

int main()
{
    string s;
    getline(cin, s);
    string result = super_reduced_string(s);
    cout << result << "\n";
    return 0;
}

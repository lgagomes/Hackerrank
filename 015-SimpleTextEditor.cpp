/*
https://www.hackerrank.com/challenges/simple-text-editor/problem

In this challenge, you must implement a simple text editor.
Initially, your editor contains an empty string, 'S'. You must
perform 'Q' operations of the following 4 types:

1. append(W) - Append string to 'W' the end of 'S'.
2. delete(k) - Delete the last 'k' characters of 'S'.
3. print(k) - Print the kth character of 'S'.
4. undo() - Undo the last (not previously undone) operation of type
1 or 2, reverting to the state it was in prior to that operation.

Input Format
The first line contains an integer, Q, denoting the number of operations.
Each line 'i' of the Q subsequent lines (where 0 <= i <= Q) defines
an operation to be performed. Each operation starts with a single
integer, 't'(where t = 1, 2, 3 or 4), denoting a type of operation as
defined in the Problem Statement above. If the operation requires
an argument, 't' is followed by its space-separated argument. For example, if t = 1
and W = "abcd", line will be '1 abcd'.

Constraints
1 <= Q <= 10^6
1 <= k <= mod(S)
The sum of the lengths of all 'W' in the input <= 10^6.
The sum of 'k' over all delete operations <= 2*10^6.
All input characters are lowercase English letters.
It is guaranteed that the sequence of operations given as input is possible to perform.

Output Format
Each operation of type 3 must print kth the character on a new line.

Sample Input
8
1 abc
3 3
2 3
1 xy
3 2
4
4
3 1

Sample Output
c
y
a

Explanation
Initially, S is empty. The following sequence of 8 operations are described below:
1. S = "". We append 'abc' to S, so S = "abc".
2. Print the 3rd character on a new line. Currently, the 3rd character is c.
3. Delete the last 3 characters in S(abc), so S = "".
4. Append 'xy' to S, so S = "xy"
5. Print the 2nd character on a new line. Currently the 2nd character is 'y'
6. Undo the last update to S, making empty again (i.e., S = "").
7. Undo the next to last update to S (the deletion of the last 3 characters), making S = "abc".
8. Print the 1st character on a new line. Currently, the 1st character is a 'a'.
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int iterations, op, k;
    stack<string>stk;
    string complete_string, input_string;

    cin>>iterations;
    while(iterations--)
    {
        cin>>op;

        // gets the input string to append, puts it
        // on a stack and updates the string containing
        // the whole text
        if(op==1)
        {
            cin>>input_string;
            stk.push(complete_string);
            complete_string+=input_string;
        }
        else if(op==2)
        {
            // puts the complete text before the deletion
            // into the stack to "save a state" before a
            // possible undo command
            // After, remove the last k characters from the
            // complete text
            cin>>k;
            stk.push(complete_string);
            complete_string.erase(complete_string.size()-k);
        }
        else if(op==3)
        {
            cin>>k;
            cout<<complete_string[k-1]<<endl;
        }
        else
        {
            // the complete text is replaced
            // by the text on the stack before the
            // append or delete commands
            complete_string = stk.top();
            stk.pop();
        }
    }
    return 0;
}

/*
https://www.hackerrank.com/challenges/cut-the-sticks/problem

You are given a number of sticks of varying lengths. You will iteratively cut
the sticks into smaller sticks, discarding the shortest pieces until there are
none left. At each iteration you will determine the length of the shortest stick
remaining, cut that length from each of the longer sticks and then discard all
the pieces of that shortest length. When all the remaining sticks are the same
length, they cannot be shortened so discard them.

Given the lengths of 'n' sticks, print the number of sticks that are left before
each iteration until there are none left. For example, there are n=3 sticks of
lengths arr[1,2,3]. The shortest stick length is 1, so we cut that length from the
longer two and discard the pieces of length 1. Now our lengths are arr=[1,2]. Again,
shortest stick is of length 1, so we cut that amount from the longer stick and discard
those pieces. There is only one stick left, arr=[1], so we discard that stick. Our
lengths are answer=[3,2,1].

Input Format
The first line contains a single integer 'n', the size of arr.
The next line contains 'n' space-separated integers, each an arr[i] where each value
represents the length of the ith stick.

Output Format
For each operation, print the number of sticks that are present before the operation on separate lines.

Constraints
1 <= n <= 1000
1 <= arr[i] <= 1000

Sample Input 0
6
5 4 4 2 2 8

Sample Output 0
6
4
2
1

Explanation 0
sticks-length      length-of-cut   sticks-cut
5 4 4 2 2 8             2               6
3 2 2 _ _ 6             2               4
1 _ _ _ _ 4             1               2
_ _ _ _ _ 3             3               1
_ _ _ _ _ _           DONE            DONE

Sample Input 1
8
1 2 3 4 3 3 2 1

Sample Output 1
8
6
4
1

Explanation 1
sticks-length       length-of-cut   sticks-cut
1 2 3 4 3 3 2 1         1               8
_ 1 2 3 2 2 1 _         1               6
_ _ 1 2 1 1 _ _         1               4
_ _ _ 1 _ _ _ _         1               1
_ _ _ _ _ _ _ _       DONE            DONE
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printArray(vector<int> arr)
{
    //cout << endl;
    for (int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> cutTheSticks(vector<int> arr) {

    vector<int> result, sticksLength = arr;
    int sticksCut, minimumValue;

    sort(sticksLength.begin(), sticksLength.end());
    for(int i=0; i<sticksLength.size(); i++)
    {
        minimumValue = 1001;
        for(int j=i; j<sticksLength.size(); j++)
        {
            if(sticksLength[j] != 0)
                minimumValue = min(minimumValue,sticksLength[j]);
        }

        sticksCut = 0;
        for(int k=i; k<sticksLength.size(); k++)
        {
            if(sticksLength[k] != 0)
            {
                sticksLength[k] = sticksLength[k] - minimumValue;
                sticksCut++;
            }
        }
        //cout << minimumValue << endl;
        //printArray(sticksLength);

        if(sticksCut)
            result.push_back(sticksCut);

        if(all_of(sticksLength.begin(), sticksLength.end(),[](int l) {return l == 0; }))
            break;
    }
    return result;
}

int main() {

    int n;
    cin >> n;

    vector<int>sticksLength(n), result;
    for (int i=0; i<n; i++)
    {
        cin >> sticksLength[i];
    }
    cout << endl;

    result = cutTheSticks(sticksLength);
    printArray(result);
    return 0;
}

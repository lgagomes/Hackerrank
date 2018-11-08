/*
https://www.hackerrank.com/challenges/insertionsort1/problem

Insert element into sorted list:
Given a sorted list with an unsorted number 'e' in the
rightmost cell, can you write some simple code to insert 'e'
into the array so that it remains sorted?

Since this is a learning exercise, it won't be the most efficient
way of performing the insertion. It will instead demonstrate the
brute-force method in detail.

Assume you are given the array arr=[1,2,4,5,3] indexed 0...4.
Store the value of arr[4]. Now test lower index values successively
from 0 to 3 until you reach a value that is lower than arr[4], arr[1]
in this case. Each time your test fails, copy the value at the lower
index to the current index and print your array. When the next lower
indexed value is smaller than arr[4] insert the stored value at the
current index and print the entire array.

The results of operations on the example array is:

Starting array: [1,2,4,5,3]
Store the value of arr[4] = 3. Do the tests and print interim results:

1 2 4 5 5
1 2 4 4 5
1 2 3 4 5

Input Format
The first line contains the integer 'n', the size of the array 'arr'.
The next line contains 'n' space-separated integers arr[0] ... arr[4].

Constraints
1 <= n <= 1000
-1000 <= arr[i] <= 1000

Output Format

Print the array as a row of space-separated integers each time there is a shift or insertion.

Sample Input
5
2 4 6 8 3

Sample Output
2 4 6 8 8
2 4 6 6 8
2 4 4 6 8
2 3 4 6 8

Explanation

3 is removed from the end of the array.
In the 1st line 8 > 3, so 8 is shifted one cell to the right.
In the 2nd line 6 > 3, so 6 is shifted one cell to the right.
In the 3rd line 4 > 3, so 4 is shifted one cell to the right.
In the 4th line 2 < 3, so 3 is placed at position 1.
*/

#include <iostream>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

void printArray(int n, int arr[])
{

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void insertionSort1 (int n, int arr[])
{
    if(n == 1)
        printArray(n, arr);

    int target = arr[n-1];

    for(int i=n-2; i<n; i--)
    {
        if(i == -1)
        {
            arr[0] = target;
            printArray(n, arr);
            break;
        }
        if(arr[i] > target)
        {
            arr[i+1] = arr[i];
            printArray(n, arr);
        }
        else
        {
            arr[i+1] = target;
            printArray(n, arr);
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr_i[n];

    for (int i = 0; i < n; i++)
       cin >> arr_i[i];

    insertionSort1(n,arr_i);
    return 0;
}

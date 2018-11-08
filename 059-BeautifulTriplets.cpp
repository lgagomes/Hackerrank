/*
https://www.hackerrank.com/challenges/beautiful-triplets/problem

Given a sequence of integers 'a', a triplet (a[i],a[j],a[k]) is beautiful if:
- i < j < k
- a[j] - a[i] = a[k] - a[j] = d

Given an increasing sequenc of integers and the value of 'd', count the number of
beautiful triplets in the sequence.

For example, the sequence arr = [2,2,3,4,5] and d = 1. There are three beautiful
triplets, by index:
[i,j,k] = [0,2,3],[1,2,3],[2,3,4]

Function Description
Complete the beautifulTriplets function in the editor below. It must return an integer
that represents the number of beautiful triplets in the sequence.

beautifulTriplets has the following parameters:
- d: an integer
- arr: an array of integers, sorted ascending

Input Format
The first line contains 2 space-separated integers 'n' and 'd', the length of the sequence
and the beautiful difference.
The second line contains 'n' space-separated integers 'arr[i]'.

Constraints
1 <= n <= 10^4
1 <= d <= 20
0 <= arr[i] <= 2x10^4
arr[i] > arr[i-1]

Output Format
Print a single line denoting the number of beautiful triplets in the sequence.

Sample Input
7 3
1 2 4 5 7 8 10

Sample Output
3

Explanation

The input sequence is 1 2 4 5 7 8 10, and our beautiful difference d = 3. There are many
possible triplets (a[i],a[j],a[k]), but our only beautiful triplets are (1,4,7), (4,7,10)
and (2,5,8) by value not index. Please see the equations below:

7-4 = 4-1 = 3
10-7 = 7-4 = 3
8-5 = 5-2 = 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int binarySearch(std::vector<int> arr,int target)
{
    int begin = 0,
        end = arr.size()-1;

    while (begin <= end)
    {
        int middle = begin + (end-begin)/2;

        if (arr[middle] == target)  return arr[middle]; // Check if target is present at middle
        if (arr[middle] < target)   begin = middle + 1; // If target greater, ignore left half
        else    end = middle - 1;                       // If target is smaller, ignore right half
    }
    return -1;  // if we reach here, then element was not present
}

int beautifulTriplets(int d, std::vector<int> arr) {

    int element2, element3, triplets = 0;
    std::vector<int> secCopy = arr;

    for(int i=0; i<arr.size(); i++)
    {
        element2 = binarySearch(secCopy,arr[i]+d);
        element3 = binarySearch(secCopy,arr[i]+2*d);

        if((element2 != -1) && (element3 != -1))
        {
            std::cout << "beautiful triplet found: (" << arr[i] << "," << element2 << "," << element3 << ")\n";
            triplets++;
        }
    }
    return triplets;
}

int main() {

    int n,d;

    std::cin >> n >> d;
    std::vector<int> arr(n);

    for(int i=0; i<n; i++)
        std::cin >> arr[i];

    //std::cout << binarySearch(arr,8) << "\n";
    std::cout << "total triplets = " << beautifulTriplets(d, arr) << "\n";
    return 0;
}

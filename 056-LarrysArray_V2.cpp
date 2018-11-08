/*
https://www.hackerrank.com/challenges/larrys-array/problem

Explanation in:
https://www.hackerrank.com/challenges/larrys-array/forum/comments/464188

Used method in:
https://www.geeksforgeeks.org/counting-inversions-using-set-in-c-stl/

Larry has been given a permutation of a sequence of natural numbers incrementing
from 1 as an array. He must determine whether the array can be sorted using the
following operation any number of times:

- Choose any 3 consecutive indices and rotate their elements in such a way that
ABC -> BCA -> CAB -> ABC.

For example, if A = [1,6,5,2,4,3]
    A		    rotate
[1,6,5,2,4,3]	[6,5,2]
[1,5,2,6,4,3]	[5,2,6]
[1,2,6,5,4,3]	[5,4,3]
[1,2,6,3,5,4]	[6,3,5]
[1,2,3,5,6,4]	[5,6,4]
[1,2,3,4,5,6]

YES

On a new line for each test case, print YES if 'A' can be fully sorted.
Otherwise, print NO.

Function Description:
Complete the larrysArray function in the editor below. It must return a string,
either YES or NO.

larrysArray has the following parameter(s):
- A: an array of integers

Input Format
The first line contains an integer 't', the number of test cases.
The next 't' pairs of lines are as follows:
- The first line contains an integer 'n', the length of 'A'
- The next line contains 'n' space-separated integers A[i].

Constraints
1 <= t <= 10
3 <= n <= 1000
1 <= A[i] <= n
A_sorted =  integers that increment by 1 from 1 to n

Output Format

For each test case, print YES if 'A' can be fully sorted. Otherwise, print NO.

Sample Input
3
3
3 1 2
4
1 3 4 2
5
1 2 3 5 4

Sample Output
YES
YES
NO

Explanation
In the explanation below, the subscript of 'A' denotes the number of operations
performed.

Test Case 0:
A0 = [3,1,2] -> rotate(3,1,2) -> A1 = [1,2,3]
'A' is now sorted, so we print YES on a new line.

Test Case 1:
A0 = [1,3,4,2] -> rotate(3,4,2) -> A1 = [1,4,2,3]
A1 = [1,4,2,3] -> rotate(4,2,3) -> A1 = [1,2,3,4]
'A' is now sorted, so we print YES on a new line.

Test Case 2:
No sequence of rotations will result in a sorted 'A'. Thus, we print NO on a new line.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

std::string larrysArray(std::vector<int> arr)
{
    // Create an empty set and insert first element in it
    std::set<int> set1;
    set1.insert(arr[0]);

    int invcount = 0; // Initialize result

    std::set<int>::iterator itset1; // Iterator for the set

    // Traverse all elements starting from second
    for (int i=1; i<arr.size(); i++)
    {
        // Insert arr[i] in set (Note that set maintains sorted order)
        set1.insert(arr[i]);

        // Set the iterator to first greater element than arr[i] in set (Note that set stores arr[0],.., arr[i-1]
        itset1 = set1.upper_bound(arr[i]);

        // Get distance of first greater element from end and this distance is count of greater elements
        // on left side of arr[i]
        invcount += distance(itset1, set1.end());
    }
    std::cout << invcount << " ";
    if((invcount % 2) == 0)
        return "YES";
    else
        return "NO";
}

int main() {

    //std::vector<int> A = {85,84,75,80,46};
    //std::vector<int> A ={80,34,84,85,76,14};
    //std::vector<int> A ={42,93,24,7,14,80,81};
    //std::vector<int> A ={80,75,57,79,66,16,92,26};
    //std::vector<int> A ={1, 20, 6, 4, 5};
    //std::vector<int> A ={1,2,3,5,4};
    //std::vector<int> A ={1,6,5,2,4,3};
    //std::vector<int> A ={3,1,2};
    //std::vector<int> A ={1,3,4,2};
    //std::cout << larrysArray(A) << "\n";


    int t, n, temp;
    std::vector<int> A;
    std::cin >> t;

    for(int i=0; i<t; i++)
    {
        std::cin >> n;
        A.clear();
        for(int j=0; j<n; j++)
        {
            std::cin >> temp;
            A.push_back(temp);
        }
        std::cout << larrysArray(A) << "\n";
    }

    return 0;
}

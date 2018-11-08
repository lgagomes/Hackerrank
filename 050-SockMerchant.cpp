/*
https://www.hackerrank.com/challenges/sock-merchant/problem

9
10 20 20 10 10 30 50 10 20

10
1 1 3 1 2 1 3 3 3 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int sockMerchant(std::vector<int> ar) {

    std::sort(ar.begin(), ar.end());

    // the algorithm fails if the last 2 elements of the array are
    // equal (there's no check for that condition (laziness)), so I
    // added a '0' at the end of the array to ensure the last 2
    // elements are different, thus, is guaranteed that the 'else'
    // statement inside the 'for' it's entered, so the calculation
    // is correct
    ar.push_back(0);

    int totalPairs = 0,
        counter = 1,
        toSearch = ar[0];

    for(int i=0; i<ar.size()-1; i++)
    {
        if(toSearch == ar[i+1])
            counter++;
        else
        {
            totalPairs += (counter/ 2);
            counter = 1;
            toSearch = ar[i+1];
        }
    }
    return totalPairs;
}

int main(){

    int n;
    std::cin >> n;

    std::vector<int> ar(n);
    for(int i=0; i<n; i++)
        std::cin >> ar[i];

    std::cout << sockMerchant(ar) << "\n";
    return 0;
}

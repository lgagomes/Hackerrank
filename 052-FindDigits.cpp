/*
https://www.hackerrank.com/challenges/find-digits/problem
https://codereview.stackexchange.com/questions/66823/output-digits-of-a-number
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {

    vector<int> digits;
    int number = n,
        ret = 0,
        i = 0;

    while(number)
    {
        digits.push_back(number%10);

        if((digits[i] != 0) && ((n%digits[i]) == 0))
            ret ++;

        number /= 10;
        i++;
    }

    return ret;
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        int result = findDigits(n);
        cout << result << "\n";
    }

    return 0;
}

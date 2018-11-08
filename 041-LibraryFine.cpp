/*
https://www.hackerrank.com/challenges/library-fine/problem

9 6 2015
6 6 2015

2 7 1014
1 1 1015
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <stdlib.h>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {

    // d1, m1, y1 corresponds to the date on which the book WAS returned.
    // d2, m2, y2 corresponds to the date on which the book WAS DUE to be returned.


    if(y1 > y2)         // If the book is returned after the calendar year
        return 10000;   // in which it was expected, there is a fixed fine of 10000 hackos
    else
    {
        if((m1 > m2) && (y1>=y2))   // If the book is returned after the expected return month but still within the same
            return (m1 - m2) * 500; // calendar year as the expected return date, the fine = 500 hackos * (number of months later)
        else
        {
            if((d1 > d2) && (m1 >= m2) && (y1 >= y2))  // If the book is returned after the expected return day but still within the same
                return (d1 - d2) * 15;                 // calendar month and year as the expected return date, fine = 15 hackos * (number of days later)
            else
                return 0; // If the book is returned on or before the expected return date, no fine will be charged
        }
    }
}

int main(){
    int d1, m1, y1, d2, m2, y2;

    std::cin >> d1 >> m1 >> y1;
    std::cin >> d2 >> m2 >> y2;

    std::cout << "Fine is " << libraryFine(d1, m1, y1, d2, m2, y2) << " hackos\n";
    return 0;
}

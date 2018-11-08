/*
https://www.hackerrank.com/challenges/insertionsort2/problem

https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
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

void insertionSort2 (int n, int arr[])
{
    int i,j,temp;

    for(i=1; i<n; i++)
    {
        j = i;
        while(arr[j] < arr[j-1])
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            if(j > 1)
                j--;
            //cout << "switched " << arr[j] << " with " << arr[j-1] << endl;
        }
        printArray(n,arr);
    }
}

int main() {
    int n;
    cin >> n;
    int arr_i[n];

    for (int i = 0; i < n; i++)
       cin >> arr_i[i];

    cout << "--------------------" << endl;
    insertionSort2(n,arr_i);
    return 0;
}

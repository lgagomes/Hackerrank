/*
https://www.hackerrank.com/challenges/service-lane/problem

*/

#include <cmath>
#include <iostream>

using namespace std;

int min(int arr[],int a,int b)
{
    int min=9999999;
    for(int i=a;i<=b;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    return min;
}

int main()
{
    int n,cases;
    cin>>n>>cases;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    while(cases--)
    {
        int a,b;
        cin>>a>>b;
        cout<<min(arr,a,b)<<endl;
    }
}

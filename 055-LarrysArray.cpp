/*
https://www.hackerrank.com/challenges/larrys-array/problem

Explanation in:
https://www.hackerrank.com/challenges/larrys-array/forum/comments/464188

Used method in:
https://stackoverflow.com/a/6424847
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
/*
void printArray(std::vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
*/
/*
int _merge(std::vector<int> arr, std::vector<int> left, std::vector<int> right) {
    int i = 0,
        j = 0,
        count = 0;

    while (i < left.size() || j < right.size())
    {
        if (i == left.size())
        {
            arr[i+j] = right[j];
            j++;
        }
        else if (j == right.size())
        {
            arr[i+j] = left[i];
            i++;
        }
        else if (left[i] <= right[j])
        {
            arr[i+j] = left[i];
            i++;
        }
        else
        {
            arr[i+j] = right[j];
            count += left.size()-i;
            j++;
        }
    }
    return count;
}
*/
/*
int split(std::vector<int> A) {

    int m;
    std::vector<int>::const_iterator index1;
    std::vector<int>::const_iterator index2;
    std::vector<int>::const_iterator index3;

    if(A.size() < 2)
        return 0;

    else
    {
        m = (A.size() + 1) / 2;
        index1 = A.begin();
        index2 = A.begin() + m;
        index3 = A.begin() + A.size();

        std::vector<int> left(index1, index2);
        std::vector<int> right(index2, index3);

        return split(left) + split(right) + _merge(A,left,right);
    }
}
*/
/*
void larrysArray(std::vector<int> A) {

    int inversions = split(A);

    std::cout << inversions << " ";
    if((inversions % 2) == 0)
        std::cout << " YES\n";
    else
        std::cout << " NO\n";
}
*/


// This function merges two sorted arrays and returns inversion count in the arrays.
int merge(std::vector<int> arr, std::vector<int> temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(std::vector<int> arr, std::vector<int> temp, int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        //Divide the array into two parts and call _mergeSort() for each of the parts
        mid = (right + left) / 2;

        // Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging */
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        //Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int mergeSort(std::vector<int> arr)
{
    std::vector<int> temp(arr.size());
    return _mergeSort(arr, temp, 0, arr.size() - 1);
}

int main() {

    //std::vector<int> A = {85,84,75,80,46};
    //std::vector<int> A ={80,34,84,85,76,14};
    std::vector<int> A ={42,93,24,7,14,80,81};
    //std::vector<int> A ={1, 20, 6, 4, 5};
    //std::vector<int> A ={1,2,3,5,4};
    //std::vector<int> A ={1,6,5,2,4,3};
    //std::vector<int> A ={3,1,2};
    //std::vector<int> A ={1,3,4,2};
    std::cout << mergeSort(A);

    //larrysArray(A);
    /*
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
        larrysArray(A);
    }
    */
    return 0;
}

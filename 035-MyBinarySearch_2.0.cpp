
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <math.h>

using namespace std;

int MyBinarySearch(vector<int> vec, int value) {
    int start = 0,
        stop = vec.size()-1,
        middle = floor((start + stop) / 2);

    while((vec[middle] != value) && (start < stop))
    {
        /*
        cout << "Start = " << start << endl;
        cout << "Middle = " << middle << endl;
        cout << "Stop = " << stop << endl << endl;
        */
        if(value > vec[middle])
            stop = middle -1;
        else
            start = middle+1;

        middle = floor((start + stop) / 2);
    }

    if(vec[middle] != value)
        return middle + 2;
    else
        return middle + 1;

}

int main() {

    vector<int> vec = {100, 50, 40, 20, 10};
    vector<int> inputs = {5, 25, 50, 120};
    /*
    vector<int> vec = {100, 90, 80, 75, 60};
    vector<int> inputs = {50, 65, 77, 90, 102};
    */
    for(int i = 0; i<inputs.size(); i++)
    {
      if((i==inputs.size()-1) && (inputs[i] > vec[vec.size()-1]))
            cout << 1 << endl;
        else
            cout << MyBinarySearch(vec,inputs[i])<< endl;
    }

    return 0;
}

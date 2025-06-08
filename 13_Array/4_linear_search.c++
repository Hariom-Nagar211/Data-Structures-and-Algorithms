#include<iostream>
#include<vector>
using namespace std;

// Que: do a linear search

int linerSearch(vector<int> arr, int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;

}

int main()
{
    cout << "req index is: " << linerSearch({1,2,3,4,5}, 5, 3);

}
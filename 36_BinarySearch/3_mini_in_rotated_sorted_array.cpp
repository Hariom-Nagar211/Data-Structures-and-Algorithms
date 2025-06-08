#include<bits/stdc++.h>
using namespace std;

// Find minimum element in rotated sorted array(unique).

int Optimal(vector<int> arr, int n)
{
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;

    while(low <= high)
    {
        int mid = (low + high)/2;
        
        // left sorted
        if(arr[low] <= arr[mid] && arr[mid] > arr[high]) 
        {
            mini = min(mini, arr[mid]);
            low = mid+1;
        }
        // right sorted
        else
        {
            mini = min(mini, arr[mid]);
            high = mid-1;
        }
    }
    return mini;

    // Logic: From a particular point the array is either left or right sorted.
    // TC: log(2,n)
}

int main()
{
    vector<int> arr = {7,8,1,2,3,4,5,6}; // (5,6,7,8,1,2,3,4)
    int n = arr.size();

    cout << Optimal(arr, n);
}
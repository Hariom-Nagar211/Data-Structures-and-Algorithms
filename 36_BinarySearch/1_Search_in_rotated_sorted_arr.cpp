#include<bits/stdc++.h>
using namespace std;

// Que: Find index of target element in an rotated sorted array[unique].

int Optimal(vector<int> arr, int n, int t)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == t) return mid;

        // left sorted
        if(arr[low] <= arr[mid-1])
        {
            if((t >= arr[low]) && (t <= arr[mid-1])) 
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right sorted
        else
        {
            if((t >= arr[mid+1]) && (t <= arr[high]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }    
    return -1;    
    
}

int main()
{
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int n = arr.size();
    int t = 1;

    cout << Optimal(arr, n, t);
}
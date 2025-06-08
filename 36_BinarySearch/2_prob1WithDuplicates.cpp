#include<bits/stdc++.h>
using namespace std;

// Que: Find target element in an rotated sorted array[may contain duplicates].

bool Optimal(vector<int> arr, int n, int t)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == t) return true;

        // special case
        if((arr[low] == arr[mid]) && (arr[high] == arr[mid]))
        {
            low++;
            high--;
            continue;
        }

        // left sorted
        if(arr[low] <= arr[mid-1])
        {
            if((t >= arr[low]) && (t <= arr[mid])) // if arr like 1(mid, low),2(high)
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
            if((t >= arr[mid]) && (t <= arr[high]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }    
    return false;    
    
}

int main()
{
    vector<int> arr = {3,1,2,3,3,3,3};
    int n = arr.size();
    int t = 2;

    cout << Optimal(arr, n, t);
}
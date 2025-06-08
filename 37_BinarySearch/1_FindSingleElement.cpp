#include<bits/stdc++.h>
using namespace std;

// Que: Find the single element in an sorted array where all the elements 
//      are appearing twice except one element.

int Optimal(vector<int> arr)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;

    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == arr[mid-1])
        {
            if((mid-low+1)%2 != 0) high = mid;
            else low = mid+1;
        }
        else if(arr[mid] == arr[mid+1])
        {
            if((high-mid+1)%2 != 0) low = mid;
            else high = mid-1;
        }
        else return arr[mid];
    }

    // Logic: element repeating side + index of mid.
    //    TC: log(2,n)
}

int main()
{
    vector<int> arr = {1,2,2,3,3,4,4,5,5,6,6};

    cout << Optimal(arr);
}
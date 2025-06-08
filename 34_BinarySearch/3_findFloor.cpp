#include<iostream>
using namespace std;

// Que: (Floor problrm)return the index of largest no in array such that arr[index] <= x.

int Optimal(int arr[], int n, int x)
{
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;

    // TC: log(2,n)
    // SC: 1
}

int main()
{
    int n = 10;
    int arr[] = {1,2,3,3,7,8,9,9,9,11};
    int x = 9;

    cout << Optimal(arr, n, x);
}
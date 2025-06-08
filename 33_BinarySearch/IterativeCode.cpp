#include<iostream>
using namespace std;

// TC: log2(n)
// SC: 1

int BinarySearch(int arr[], int n, int t)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == t) return mid;
        else if(arr[mid] < t) low = mid+1;
        else high = mid - 1; 
    }
    return -1;
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,4,6,8};
    int t = 6;

    cout << BinarySearch(arr, n, t); 
}
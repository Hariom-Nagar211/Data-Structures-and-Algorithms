#include<iostream>
using namespace std;

// TC: log2(n)
// SC: 1

int BinarySearch(int arr[], int t, int low, int high)
{
    if(low > high) return -1;

    int mid = (low + high)/2;
    if(arr[mid] == t) return mid;
    else if(arr[mid] < t) return BinarySearch(arr, t, mid+1, high);
    else return BinarySearch(arr, t, low, mid-1);

}

int main()
{
    int n = 5;
    int arr[n] = {1,2,4,6,8};
    int t = 6;

    cout << BinarySearch(arr, t, 0, n-1);
}
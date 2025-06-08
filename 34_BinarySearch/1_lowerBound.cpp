#include<iostream> 
#include<vector>
using namespace std;

// Que: (ceiling problem) return the minimum index such that arr[index] >= x.
// (you are given a sorted array).
// if you will not find any such index then return size of array.

// Brute
// LC: Linear Search
// TC: N
// SC: 1

// Optimal-1,2
// LC: Binary Search
// TC: log2(N)
// SC: 1

// Optimal-3
// LC: STL
// TC: log2(N)
// SC: 1

int Brute(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] >= x) return i;
    }
    return n;

}

// Application: It can be used as to find the index at which x can be inserted in a sorted 
// array.
int Optimal1(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] >= x)
        {
            if(arr[mid - 1] >= x) high = mid - 1;
            else return mid;
        }
        else low = mid + 1;
    }
    return n;

}

int Optimal2(int arr[], int n, int x)
{
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int Optimal3(vector<int> arr, int n, int x)
{
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    return lb;
}

int main()
{
    int n = 10;
    int arr[] = {1,2,3,3,7,8,9,9,9,11};
    vector<int> v = {1,2,3,3,7,8,9,9,9,11};
    int x = 9;

    cout << Brute(arr, n, x);
    cout << endl;
    cout << Optimal1(arr, n, x);
    cout << endl;
    cout << Optimal2(arr, n, x);
    cout << endl;
    cout << Optimal3(v, n, x);
}
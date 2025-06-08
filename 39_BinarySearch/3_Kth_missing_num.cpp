#include<bits/stdc++.h>
using namespace std;

// Que: Return the kth missing number, from the given increasing array of +ve integers.

int Brute(vector<int> arr, int k)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(arr[i] <= k) k++;
        else break;
    }
    return k;

    // Logic: Write the two arrays(1-arr[n-1] and arr) and observe them.
    //    TC: n
}

int Optimal(vector<int> arr, int k)
{
    int n = arr.size();

    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return low + k; // arr[high] + more = arr[high] + (k-missing) 
                    // = arr[high] + [k - (arr[high] -(high + 1))]

    // TC: lon(2,n)
}

int main()
{
    vector<int> arr = {2,3,4,7,11};
                    // 1,2,3,4,5,6,7,8,9,10,11
    int k = 5;

    cout << Brute(arr, k);
    cout << endl;
    cout << Optimal(arr, k);
}
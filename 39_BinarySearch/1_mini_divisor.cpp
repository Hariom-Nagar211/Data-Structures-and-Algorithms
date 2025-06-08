#include<bits/stdc++.h>
using namespace std;

// Que: Return the minimum divisor such thar it is <= threashold.

bool is_possible(vector<int> arr, int t, int div)
{
    int n = arr.size();
    long long ans = 0;

    for(int i=0; i<n; i++)
    {
        ans += ceil(arr[i]/div);
    }
    return ans <= t;
}

int Brute(vector<int> arr, int t)
{
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for(int i = mini; i <= maxi; i++)
    {
        if(is_possible(arr, t, i) == 1)
        {
            return i;
        }
    }
    return -1;

    // TC: n + (maxi-mini+1)*n
}

int Optimal(vector<int> arr, int t)
{
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini;
    int high = maxi;
    int ans = -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(is_possible(arr, t, mid) == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;

    // TC: n + log(2, maxi-mini+1)*n
}

int main()
{
    vector<int> arr = {6,5,7,4};
    int t = 5;

    cout << Brute(arr, t);
    cout << endl;
    cout << Optimal(arr, t);
}
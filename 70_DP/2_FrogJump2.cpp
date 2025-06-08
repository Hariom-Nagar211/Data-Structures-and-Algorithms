#include<bits/stdc++.h>
using namespace std;

// QUE : Frog can jump upto k steps.

// Recursion
int f(vector<int> arr, int k, int ind)
{
    if(ind == 0) return 0;

    int mini = INT_MAX;
    for(int i=1; i<=k; i++)
    {
        if(ind-i >= 0)
        {
            int jump = abs(arr[ind] - arr[ind-i]) + f(arr, k, ind-i);
            mini = min(jump, mini);
        }
        
    }
    return mini;

}

// Recursion + Memoization
int f2(vector<int> arr, int k, int ind, vector<int> dp)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int mini = INT_MAX;
    for(int i=1; i<=k; i++)
    {
        if(ind-i >= 0)
        {
            int jump = abs(arr[ind] - arr[ind-i]) + f2(arr, k, ind-i, dp);
            mini = min(jump, mini);
        }
        
    }
    return dp[ind] = mini;
}

// Tabulation
// Required Correction
int f3(vector<int> arr, int n, int k, vector<int> dp)
{
    dp[0] = 0;

    for(int i=0; i<n; i++)
    {
        int mini = INT_MAX;
        for(int j=1; j<=k; j++) 
        {
            if(i-j >= 0)
            {
                int jump = abs(arr[j] - arr[i-j]) + dp[i-j];
                mini = min(jump, mini);
            }
            
        }
        return dp[i] = mini;
    }
    return dp[n-1];

}

int main()
{
    vector<int> arr = {10,20,30,10,40,60,50,20,10,90};
    int n = arr.size();
    int k = 2;

    cout << f(arr, k, n-1) << endl;

    vector<int> dp(n, -1);
    cout << f2(arr, k, n-1, dp) << endl;

    cout << f3(arr, n, k, dp) << endl;
}
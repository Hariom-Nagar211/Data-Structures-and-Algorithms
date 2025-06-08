#include<bits/stdc++.h>
using namespace std;

// QUE :  Burst Balloons

// Recursion
int f(vector<int> arr, int i, int j)
{
    if(i > j) return 0;

    int maxi = INT_MIN;
    for(int ind=i; ind<=j; ind++)
    {
        int cost = (arr[i-1]*arr[ind]*arr[j+1]) + f(arr, i, ind-1) + f(arr, ind+1, j);
        maxi = max(maxi, cost);
    }

    return maxi;
}

// Recursion + DP(Memoization)
int f2(vector<int> arr, int i, int j, vector<vector<int>> dp)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;
    for(int ind=i; ind<=j; ind++)
    {
        int cost = (arr[i-1]*arr[ind]*arr[j+1]) + f2(arr, i, ind-1, dp) + f2(arr, ind+1, j, dp);
        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

// Recursion + DP(Tabulation)
int f3(vector<int> arr, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=n-2; i>=1; i--)
    {
        for(int j=1; j<=n-2; j++)
        {
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int ind=i; ind<=j; ind++)
            {
                int cost = (arr[i-1]*arr[ind]*arr[j+1]) + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[1][n-2];

    
}

int main()
{
    vector<int> arr = {3,1,5,8};
    
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    int n = arr.size();
    cout << f(arr, 1, n-2) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f2(arr, 1, n-2, dp) << endl;

    cout << f3(arr, n);
}
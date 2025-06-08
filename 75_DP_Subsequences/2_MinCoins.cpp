#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum coins required to sum up the target

// Recursion
int f(vector<int> arr, int ind, int t)
{
    if(ind == arr.size()-1)
    {
        if(t%arr[ind] == 0) return t/arr[ind];
        else return 1e9;
    }

    int not_take = 0 + f(arr, ind+1, t);
    int take = INT_MAX;
    if(t >= arr[ind]) take = 1 + f(arr, ind, t-arr[ind]);

    return min(take, not_take);

    // TC : Exponential
    // SC : O(target)
}

// Recursion + DP(Memoization)
int f2(vector<int> arr, int ind, int t, vector<vector<int>> dp)
{
    if(ind == arr.size()-1)
    {
        if(t%arr[ind] == 0) return t/arr[ind];
        else return 1e9;
    }

    if(dp[ind][t] != -1) return dp[ind][t];

    int not_take = 0 + f(arr, ind+1, t);
    int take = INT_MAX;
    if(t >= arr[ind]) take = 1 + f(arr, ind, t-arr[ind]);

    return dp[ind][t] = min(take, not_take);

    // TC : N x T
    // SC : O(N x T) + O(T)
}

// Recursion + DP(Tabulation)
int f3(vector<int> arr, int n, int t)
{
    vector<vector<int>> dp(n, vector<int>(t+1, 0));

    for(int tar=0; tar<=t; tar++)
    {
        if(tar%arr[0] == 0) dp[0][tar] = tar/arr[0];
        else dp[0][tar] = 1e8;
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int tar=0; tar<=t; tar++)
        {
            int not_take = 0 + dp[ind-1][tar];
            int take = 1e8;
            if(tar >= arr[ind]) take = 1 + dp[ind][tar-arr[ind]];

            dp[ind][tar] = min(take, not_take);
        }
    }

    return dp[n-1][t];

    
}

int main()
{
    vector<int> arr = {1,2,3,5};
    int t = 7;
    int n = arr.size();

    cout << f(arr, n-1, t) << endl;

    vector<vector<int>> dp(n, vector<int>(t+1, -1));
    cout << f2(arr, n-1, t, dp) << endl;

    cout << f3(arr, n, t);
}
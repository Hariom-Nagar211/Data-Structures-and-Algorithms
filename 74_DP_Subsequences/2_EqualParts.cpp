#include<bits/stdc++.h>
using namespace std;

// QUE : Array ---> Break in two Subarrays ---> if Sum of Subset1 == Subset2, return true else false.

// Recursion
bool f(int ind, vector<int> arr, int n, int t) // t = t_sum/2
{
    if(t == 0) return true;
    if(ind == n-1) return (arr[ind] == t);

    bool not_take = f(ind+1, arr, n, t);
    bool take = false;
    if(t >= arr[ind]) f(ind+1, arr, n, t-arr[ind]);

    return (not_take || take);

    // TC : 2^n
    // SC : n

}

// Recursion + DP(memoization)
bool f2(int ind, vector<int> arr, int n, int t, vector<bool> &dp)
{
    if(t == 0) return true;
    if(ind == n-1) return (arr[ind] == t);

    if(dp[ind][t] != -1) return dp[ind];

    bool not_take = f2(ind+1, arr, n, t, dp);
    bool take = false;
    if(t >= arr[ind]) f2(ind+1, arr, n, t-arr[ind], dp);

    return dp[ind][t] = (not_take || take);
}

// DP(Tabulation)
bool f3(vector<int> arr, int n, int t)
{
    vector<vector<bool>> dp(n, vector<bool>(t+1, false));

    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= t) dp[0][arr[0]] = true;

    for(int ind=1; ind<n; ind++)
    {
        for(int tar=1; tar<=t; tar++)
        {
            int not_take = dp[ind-1][tar];
            int take = false;
            if(tar >= arr[ind]) take = dp[ind-1][tar - arr[ind]];

            dp[ind][tar] = not_take || take;
        }
    }
    return dp[n-1][t];
}
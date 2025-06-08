#include<bits/stdc++.h>
using namespace std;

// QUE :  https://bit.ly/33Kd8o2

// Recursion
int f(vector<int> arr, int ind, int t)
{
    if(ind == arr.size()-1)
    {
        if(t%arr[0] == 0) return 1;
        else return 0;
    }

    int not_take = 0 + f(arr, ind+1, t);
    int take = 0;
    if(t >= arr[ind]) take = f(arr, ind, t-arr[ind]);

    return take + not_take;

}

// Recursion + DP(Memoization)
int f2(vector<int> arr, int ind, int t, vector<vector<int>> dp)
{
    if(ind == arr.size()-1)
    {
        if(t%arr[0] == 0) return 1;
        else return 0;
    }

    if(dp[ind][t] != -1) return dp[ind][t];

    int not_take = 0 + f2(arr, ind+1, t);
    int take = 0;
    if(t >= arr[ind]) take = f2(arr, ind, t-arr[ind]);

    return dp[ind][t] = take + not_take;

    // TC : N x T
    // SC : O(N x T) + O(T)
}

// Recursion + DP(Tabulation)
int f3(vector<int> arr, int n, int t)
{
    vector<vector<int>> dp(n, vector<int>(t+1, 0));

    for(int tar=0; tar<=t; tar++)
    {
        if(tar%arr[0] == 0) dp[0][tar] = 1;
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int tar=0; tar<=t; tar++)
        {
            int not_take = dp[ind-1][tar];
            int take = 0;
            if(tar >= arr[ind]) take = dp[ind][tar-arr[ind]];

            dp[ind][tar] = take + not_take;
        }
    }

    return dp[n-1][t];

    
}

int main()
{
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int t = 4;

    cout << f(arr, n-1, t);
}
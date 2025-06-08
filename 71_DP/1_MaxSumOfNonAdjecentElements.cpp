#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement :           
Given an array of 'N' positive integers, we need to return the maximum sum of the subsequence such
that no two elements of the subsequence are adjecent elements in the array. 
*/
 
// Recursion + DP(Memoization)
int f(int ind, vector<int> &arr, vector<int> dp) 
{
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + f(ind-2, arr, dp);
    int notPick = 0 + f(ind-1, arr, dp);

    return dp[ind] = max(pick, notPick);

    // TC : n
    // SC : n + n
}

// Tabulation
int f2(int n, vector<int> arr, vector<int> dp2)
{
    dp2[0] = arr[0];

    for(int i=1; i<n; i++)
    {
        int take = arr[i]; if(i > 1) take += dp2[i-2];
        int nonTake = 0 + dp2[i-1];

        dp2[i] = max(take, nonTake);
    }

    return dp2[n-1];

    // TC : n
    // SC : n
}

// Tabulation with Space Optimization
int f3(int n, vector<int> arr)
{
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1; i<n; i++)
    {
        int take = arr[i]; if(i > 1) take += prev2;
        int nonTake = 0 + prev;

        int curr = max(take, nonTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;

    // TC : n
    // SC : 1
}

int main()
{
    vector<int> arr = {2,1,4,9};
    int n = arr.size();

    vector<int> dp(n, -1);
    cout << f(n-1, arr, dp) << endl;

    vector<int> dp2(n, 0);
    cout << f2(n, arr, dp2) << endl;

    cout << f3(n, arr);

}

   


#include<bits/stdc++.h>
using namespace std;

// QUE: Count the number of subsets with sum equal t.

// Recursion
int f(vector<int> arr, int n, int ind, int t)
{
    if(t == 0) return 1;
    if(ind == n-1)
    {
        if(arr[ind-1] == t) return 1;
        else return 0;
    } 

    int take = f(arr, n, ind+1, t);
    int not_take = 0;
    if(t >= arr[ind]) not_take = f(arr, n, ind+1, t-arr[ind]);

    return (not_take + take);
}

// Recursion + DP(Memoiztion)
int f2(vector<int> arr, int n, int ind, int t, vector<int> dp)
{
    if(t == 0) return 1;
    if(ind == n-1)
    {
        if(arr[ind-1] == t) return 1;
        else return 0;
    } 

    if(dp[ind] != -1) return dp[ind];

    int take = f2(arr, n, ind+1, t, dp);
    int not_take = 0;
    if(t >= arr[ind]) not_take = f2(arr, n, ind+1, t-arr[ind], dp);

    return dp[ind] = (not_take + take);
}

// Recursion + DP(Tabulation)


int main()
{
    vector<int> arr = {1,2,2,3};
    int n = arr.size();
    int t = 3;

    cout << f(arr, n-1, t) << endl;

    vector<int> dp(t+1, -1);
    cout << f2(arr, n-1, t, dp) << endl;
}
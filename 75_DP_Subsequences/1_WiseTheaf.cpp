#include<bits/stdc++.h>
using namespace std;

// QUE : 

// Recursion
int f(vector<int> wt, vector<int> val, int ind, int W)
{
    if(ind == val.size()-1)
    {
        if(wt[ind] <= W) return val[ind];
        else return 0;
    }

    int not_take = 0 + f(wt, val, ind+1, W);
    int take = 0;
    if(wt[ind] <= W) take = val[ind] + f(wt, val, ind+1, W-wt[ind]);

    return max(not_take, take);

}

// Recursion + DP(Memoization)
int f2(vector<int> wt, vector<int> val, int ind, int W, vector<int> dp)
{
    if(ind == val.size()-1)
    {
        if(wt[ind] <= W) return val[ind];
        else return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int not_take = 0 + f(wt, val, ind+1, W);
    int take = 0;
    if(wt[ind] <= W) take = val[ind] + f(wt, val, ind+1, W-wt[ind]);

    return dp[ind][W] = max(not_take, take);

}

// Recursion + DP(Tabulation)
int f3(vector<int> wt, vector<int> val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W+1, 0));

    for(int j=wt[0]; j<=W; j++) dp[0][j] = val[0];

    for(int ind=1; ind<n; ind++)
    {
        for(int w=1; w<=W; w++)
        {
            int not_take = dp[ind-1][w];
            int take = 0;
            if(wt[ind] <= w) take = val[ind] + dp[ind-1][w - wt[ind]];

            dp[ind][w] = max(take, not_take);
        }
    }
    return dp[n-1][W];

}

int main()
{
    vector<int> wt = {2,3,5};
    vector<int> val = {30,30,50};
    int n = wt.size();
    int W = 5;

    cout << f(wt, val, n-1, W) << endl;

    vector<int> dp(n*(W+1), -1);
    cout << f2(wt, val, n-1, W, dp) << endl;

    cout << f3(wt, val, n, W);
}
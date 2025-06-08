#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum Cost to Cut the Stick

// Recursion
int f(vector<int> cuts, int i, int j)
{
    if(i > j) return 0;

    int mini = 1e9;
    for(int k=i; k<=j; k++)
    {
        int cost = cuts[j+1] - cuts[i-1] + f(cuts, i, k-1) + f(cuts, k+1, j);
        mini = min(mini, cost);
    }

    return mini;
}

// Recursion + DP(Memoization)
int f2(vector<int> cuts, int i, int j, vector<vector<int>> &dp)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<=j; k++)
    {
        int cost = cuts[j+1] - cuts[i-1] + f2(cuts, i, k-1, dp) + f2(cuts, k+1, j, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

// Recursion + DP(Tabulation)
int f3(vector<int> cuts, int c, int n)
{
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    
    for(int i=c; i>=1; i--)
    {
        for(int j=1; j<=c; j++)
        {
            if(i > j) continue;
            int mini = 1e9;
            for(int k=i; k<=j; k++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}


int main()
{
    vector<int> cuts = {1,3,4,5};
    int n = 7;
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    cout << f(cuts, 1, c) << endl;

    vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
    cout << f2(cuts, 1, c, dp) << endl;

    cout << f3(cuts, c, n);
}
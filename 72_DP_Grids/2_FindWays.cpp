#include<bits/stdc++.h>
using namespace std;

// QUE : Find total number of ways to reach from point A(top left) to B(bottom right), 
//       only right and down movement is allowed.

// Recursion
int f(int i, int j, int n, int m)
{
    if(i == n-1 && j == m-1) return 1;
    if(i > n-1 || j > m-1) return 0;

    int right = f(i, j+1, n, m);
    int down = f(i+1, j, n, m);

    return right + down;

    // TC : pow(2, m*n)
    // SC : path length
}

// Recursion + DP(Memoization)
int f2(int i, int j, int n, int m, vector<vector<int>> dp)
{
    if(i == n-1 && j == m-1) return 1;
    if(i > n-1 || j > m-1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int right = f2(i, j+1, n, m, dp);
    int down = f2(i+1, j, n, m, dp);

    return dp[i][j] = right + down;

    // TC : M x N
    // SC : path length + N x M
}

// Recursion + DP(Tabulation)
int f3(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i == 0 && j == 0) dp[0][0] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];

    // TC : M x N
    // SC : N x M
}

// Recursion + DP(Tabulation) with Space Optimization
int f4()

int main()
{
    int n = 3;
    int m = 3;
    cout << f(0, 0, n, m) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << f2(0, 0, n, m, dp) << endl;

    cout << TotalWays3(n, m) << endl;
}
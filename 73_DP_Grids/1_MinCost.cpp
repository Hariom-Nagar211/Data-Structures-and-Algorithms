#include<bits/stdc++.h>
using namespace std;

// QUE : Buy minimum cost path on NinjaIsland from point A(top left) to B(bottom right).

// Recursion
int f(int i, int j, vector<vector<int>> NinjaIsland, int n, int m)
{
    if(i == n-1 && j == m-1) return NinjaIsland[i][j];
    if(i > n-1 || j > m-1) return 1e9;

    int right = NinjaIsland[i][j] + f(i, j+1, n, m);
    int down = NinjaIsland[i][j] + f(i+1, j, n, m);

    return min(right, down);
    
}

// Recursion + DP(Memoization)
int f(int i, int j, vector<vector<int>> NinjaIsland, int n, int m, vector<vector<int>> dp)
{
    if(i == n-1 && j == m-1) return NinjaIsland[i][j];
    if(i > n-1 || j > m-1) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int right = NinjaIsland[i][j] + f(i, j+1, n, m);
    int down = NinjaIsland[i][j] + f(i+1, j, n, m);

    return dp[i][j] = min(right, down);
    
}

// Recusion + DP(Tabulation)
long long int f3(vector<vector<int>> NinjaIsland, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = NinjaIsland[0][0];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i == 0 && j == 0) dp[0][0] = NinjaIsland[0][0];
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

// Tabulation Optimised

int main()
{
    int n = 3;
    int m = 3;

    vector<vector<int>> NinjaIsland = {{10 , 5  , 15},
                                       {25 , 10 , 5 },
                                       {50 , 25 , 5 }};

    cout << f(n-1, m-1, NinjaIsland) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << f2(n-1, m-1, NinjaIsland, dp) << endl;

    cout << f3(n, m, NinjaIsland) << endl;                                   

}
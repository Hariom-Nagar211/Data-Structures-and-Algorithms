#include<bits/stdc++.h>
using namespace std;

// QUE : Find minimum sum to reach from top row to bottom row in triangle

// We can't apply greedy because there is no uniformity in triangle values

// Recursion
int f(int i, int j, vector<vector<int>> triangle, int n)
{
    if(i == n-1) return triangle[i][j];

    int down = triangle[i][j] + f(i+1, j, triangle, n); 
    int digonal = triangle[i][j] + f(i+1, j+1, triangle, n);

    return min(down, digonal);
}

// Recursion + DP(Memoization)
int f2(int i, int j, vector<vector<int>> triangle, int n, vector<vector<int>> dp)
{
    if(i == n-1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + f2(i+1, j, triangle, n, dp);
    int digonal = triangle[i][j] + f2(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(down, digonal);
}

// Recursion + DP(Tabulation)
int f3(vector<vector<int>> triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = triangle[0][0];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = triangle[0][0];
            else
            {
                int up = 1e9;
                int digonal = 1e9;
                if(i > 0) up = dp[i-1][j];
                if(i > 0 && j > 0) digonal = dp[i-1][j-1];

                dp[i][j] = min(up, digonal);
            }
        }
    }
    return dp[n-1][n-1];
}    

int main()
{
    int n = 4;
    vector<vector<int>> triangle = {{1},
                                    {2 , 3},
                                    {3 , 6 , 7},
                                    {8 , 9 , 6 , 10}};

    cout << f(0, 0, triangle) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f2(0, 0, triangle, dp) << endl;

    cout << f3(n, triangle);
}
#include<bits/stdc++.h>
using namespace std;

// QUE : Find the maximum path sum starting from first row and end to last row in the given matrix.
//       you can move to another cell directly below that row, or digonally below left or right.

// Recursion
int f(int i, int j, vector<vector<int>> mat, int n, int  m)
{
    if(j < 0 || j > m-1 || i > n-1) return -1e9;
    if(i == n-1 && j < m) return mat[i][j];

    int ld = -1e9;
    if(i > 0) ld = mat[i][j] + f(i+1, j-1, mat, n, m);

    int d = mat[i][j] + f(i+1, j, mat, n, m);

    int rd = -1e9;
    if(j < m-1) rd = mat[i][j] + f(i+1, j+1, mat, n, m);

    return max(ld, max(d, rd));

}

// Recursion + DP(Memoization)
int f(int i, int j, vector<vector<int>> mat, int n, int  m, 
    vector<vector<int>> dp)
{
    if(j < 0 || j > m-1 || i > n-1) return -1e9;
    if(i == n-1 && j < m) return mat[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int ld = -1e9;
    if(i > 0) ld = mat[i][j] + f(i+1, j-1, mat, n, m);

    int d = mat[i][j] + f(i+1, j, mat, n, m);

    int rd = -1e9;
    if(j < m-1) rd = mat[i][j] + f(i+1, j+1, mat, n, m);

    return dp[i][j] = max(ld, max(d, rd));

}

// DP(Tabulation)
int f3(vector<vector<int>> mat, int n, int  m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j=0; j<m; j++) dp[0][j] = mat[0][j];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int ld = -1e9;
            if(j > 0) ld = dp[i-1][j-1] + mat[i][j];

            int u = dp[i-1][j] + mat[i][j];

            int rd = -1e9;
            if(j < m-1) rd = dp[i-1][j+1] + mat[i][j];

            dp[i][j] = max(ld, max(u, rd));
        }
    }

    int ans = 0;
    for(int j=0; j<m; j++)
    {
        ans = max(ans, dp[n-1][j]);
    }
    return ans;

}

int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> matrix = {{1   , 2 , 10 , 4},
                                  {100 , 3 , 2  , 1},
                                  {1   , 1 , 20 , 200},
                                  {1   , 2 , 2  , 1}};
    
    int ans = 0;                                  
    for(int i=0; i<m; i++)
    {
        ans = max(ans, f(0, i, matrix, n, m));
    }
    cout << ans << endl;  
    
    cout << f3(matrix, n, m) << endl;
}
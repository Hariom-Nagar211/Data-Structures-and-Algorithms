#include<bits/stdc++.h>
using namespace std;

// QUE : Matrix Chain Multiplication

// Recursion
int f(vector<int> arr, int i, int j)
{
    if(i == j) return 0;

    int mini = 1e9;
    for(int k=i; k<=j-1; k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(arr, i, k) + f(arr, k+1, j);
        mini = min(mini, steps);
    }

    return mini;

    // TC : exp
    // SC : N
}

// Recursion + DP(Memoization)
int f2(vector<int> arr, int i, int j, vector<vector<int>> dp)
{
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<=j-1; k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j]) + f2(arr, i, k, dp) + f2(arr, k+1, j, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;

    // TC : n*n*n
    // SC : n*n + n
}

// Recursion + DP(Tabulation)
int f3(vector<int> arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=1; i<n; i++) dp[i][i] = 0;
    
    for(int i=n-1; i>=1; i--)
    {
        for(int j=i+1; j<=n-1; j++)
        {
            int mini = 1e9;
            for(int k=i; k<j; k++)
            {
                int steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];

    // TC : n*n*n
    // SC : n*n
}


int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    cout << f(arr, 1, n-1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f2(arr, 1, n-1, dp) << endl;

    cout << f3(arr, n) << endl;


}

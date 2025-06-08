#include<bits/stdc++.h>
using namespace std;

// QUE : Count Square Submatrices with All Ones

int f(vector<vector<int>> arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int ans = 0;
    for(int i=0; i<n; i++) dp[i][0] = arr[i][0], ans += arr[i][0];
    for(int j=1; j<m; j++) dp[0][j] = arr[0][j], ans += arr[0][j];
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(arr[i][j] == 0) dp[i][j] = 0;
            else
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            ans += dp[i][j];
        }
    }

    return ans;    
}

int main()
{
    vector<vector<int>> arr = {{1,0,1,0,0},
                               {1,0,1,1,1},
                               {1,1,1,1,1},
                               {1,0,0,1,0}};
    int n = arr.size();
    int m = arr[0].size();

    cout << f(arr, n, m) << endl;
}
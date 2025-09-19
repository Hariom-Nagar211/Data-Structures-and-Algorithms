#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum Insertions/Deletions to Convert String A to String B
// Link : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution {
  private:
    // return length of LCS
    int f(string &s1, string &s2, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        if(s1[0] == s2[0]) dp[0][0] = 1;
        for(int j=1; j<m; j++)
        {
            if(s1[0] == s2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }
        for(int i=1; i<n; i++)
        {
            if(s2[0] == s1[i]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n = s1.size();
        int m = s2.size();
        
        int lcs = f(s1, s2, n, m);
        
        return (n - lcs) + (m - lcs);
    }
};
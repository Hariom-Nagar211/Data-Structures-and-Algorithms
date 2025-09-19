#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum Insertions to Make String Palindrome
// Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
private:
    // return longest palindromic subsequence
    int f(string s1, string s2, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        if(s1[0] == s2[0]) dp[0][0] = 1;
        for(int j=1; j<n; j++)
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
            for(int j=1; j<n; j++)
            {
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][n-1];
    }

public:
    int minInsertions(string s) {

        int n = s.size();

        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        return (n - f(s1, s2, n));
        
    }
};
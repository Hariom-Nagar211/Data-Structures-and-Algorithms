#include<bits/stdc++.h>
using namespace std;

// QUE : Find the longest comman string among the two given strings.
// Link : https://leetcode.com/problems/longest-common-subsequence/
// megaLink : https://claude.ai/chat/ef30eece-bee4-4bee-b93c-907d3832e3a7

class Solution {
private:
    int f(int ind1, int ind2, string text1, string text2, int n1, int n2)
    {
        if(ind1 == n1 || ind2 == n2) return 0;

        if(text1[ind1] == text2[ind2]) return 1 + f(ind1+1, ind2+1, text1, text2, n1, n2);
        else return max(f(ind1+1, ind2, text1, text2, n1, n2), f(ind1, ind2+1, text1, text2, n1, n2));
    }

    int f2(int ind1, int ind2, string text1, string text2, int n1, int n2, vector<vector<int>> &dp)
    {
        if(ind1 == n1 || ind2 == n2) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(text1[ind1] == text2[ind2]) return 1 + f2(ind1+1, ind2+1, text1, text2, n1, n2, dp);
        else return dp[ind1][ind2] = max(f2(ind1+1, ind2, text1, text2, n1, n2, dp), f2(ind1, ind2+1, text1, text2, n1, n2, dp));
    }

    int f3(string text1, string text2, int n1, int n2)
    {
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        if(text1[0] == text2[0]) dp[0][0] = 1;
        for(int j=1; j<n2; j++) 
        {
            if(text1[0] == text2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }
        for(int i=1; i<n1; i++)
        {
            if(text1[i] == text2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }

        for(int i=1; i<n1; i++)
        {
            for(int j=1; j<n2; j++)
            {
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1-1][n2-1];
    }

public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return f3(text1, text2, n1, n2);
    }
};
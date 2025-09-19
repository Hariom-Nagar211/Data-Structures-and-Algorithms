#include<bits/stdc++.h>
using namespace std;

// QUE : Shortest Common Supersequence
// Link : https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
private:
    string f(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        if(s1[0] == s2[0]) dp[1][1] = 1;
        for(int j=2; j<=m; j++) 
        {
            if(s1[0] == s2[j-1]) dp[1][j] = 1;
            else dp[1][j] = dp[1][j-1];
        }
        for(int i=2; i<=n; i++)
        {
            if(s1[i-1] == s2[0]) dp[i][1] = 1;
            else dp[i][1] = dp[i-1][1];
        }

        for(int i=2; i<=n; i++)
        {
            for(int j=2; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string lcs = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1]) 
            {
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }

        return lcs;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        string lcs = f(str1, str2, n, m);
        int l = lcs.size();

        string s = "";
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n && j < m)
        {
            if(k < l && str1[i] == str2[j] && str1[i] == lcs[k])
            {
                s += str1[i];
                i++;
                j++;
                k++;
            }
            else if(k < l && str1[i] == lcs[k])
            {
                while(str2[j] != lcs[k])
                {
                    s += str2[j];
                    j++;
                }
                s += lcs[k];
                i++;
                j++;
                k++;
            }
            else if(k < l && str2[j] == lcs[k])
            {
                while(str1[i] != lcs[k]) 
                {
                    s += str1[i];
                    i++;
                }
                s += lcs[k];
                j++;
                i++;
                k++;
            }
            else
            {
                s += str1[i];
                s += str2[j];
                i++;
                j++;
            }

        }
        while(i < n)
        {
            s += str1[i];
            i++;
        }
        while(j < m)
        {
            s += str2[j];
            j++;
        }
        return s;       
    }
};
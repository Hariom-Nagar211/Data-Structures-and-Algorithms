#include<bits/stdc++.h>
using namespace std;

// QUE : https://bit.ly/3qXtORt

// Recursion
bool f(string s1, string s2, int i, int j)
{
    if(i < 0 && j < 0) return true;
    if(i < 0 && j >= 0) return false;
    if(j < 0 && i >= 0)
    {
        for(int ii=0; ii<=i; ii++)
        {
            if(s1[ii] != '*') return false;
        }
        return true;
    }

    if(s1[i] == s2[j] || s1[i] == '?') return f(s1,s2,i-1,j-1);
    if(s1[i] == '*') return (f(s1,s2,i-1,j) || f(s1,s2,i,j-1));
    return false;

    // TC : exp
    // SC : n+m
}

// Recursion + DP(Memoization)

// Recursion + DP(Tabulation)
bool f3(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;
    for(int j=1; j<=m; j++) dp[0][j] = false;
    for(int i=1; i<=n; i++)
    {
        int flag = true;
        for(int ii=1; ii<=i; ii++)
        {
            if(s1[ii-1] != '*')
            {
                flag = false;
                break;
            }

        }
        dp[i][0] = flag;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i] == s2[j] || s1[i] == '?') dp[i][j] = dp[i-1][j-1];
            else if(s1[i] == '*') dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            else dp[i][j] = false;
        }
    }

    return dp[n][m];

    // TC : n*m
    // SC : n*m

}

int main()
{
    string s1 = "ab*cd";  
    string s2 = "abdbfcd"; 
    int n = s1.size();
    int m = s2.size();

    cout << f(s1,s2,n-1,m-1) << endl;
    cout << f3(s1, s2);
}
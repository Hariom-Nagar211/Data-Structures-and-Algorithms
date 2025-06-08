#include<bits/stdc++.h>
using namespace std;

// QUE : Distinct Subsequences

// Recursion
int f(string s1, string s2, int i, int j)
{
    if(j < 0) return 1;
    if(i < 0) return 0; 

    if(s1[i] == s2[j]) return (f(s1,s2,i-1,j-1) + f(s1,s2,i-1,j));
    else return f(s1,s2,i-1,j);

    // TC : exp
    // SC : O(n+m)

}

// Recursion + DP(Memoization)


// Recursion + DP(Tabulation)
int f3(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=m; j++) dp[0][j] = 0;  // error chance

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][m];
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";
    int n = s1.size();
    int m = s2.size();

    cout << f(s1,s2,n-1,m-1) << endl;

    cout << f3(s1,s2);
}
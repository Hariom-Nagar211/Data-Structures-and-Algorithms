#include<bits/stdc++.h>
using namespace std;

// QUE : Return minimum operations(insert,remove,replace) required to convert s1 to s2.

// Recursion
int f(string s1, string s2, int i, int j)
{
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s1[i] == s2[j]) return 0 + f(s1,s2,i-1,j-1);
    else
    {
        return 1 + min(
                f(s1,s2,i,j-1),          // Insert
            min(f(s1,s2,i-1,j),          // Remove
                f(s1,s2,i-1,j-1))        // Replace
        );
    }

    // TC : exp
    // SC : O(n+m)

}

// Recursion + DP(Memoization)

// Recursion + DP(Tabulation)
int f3(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m, 0));

    for(int j=0; j<=m; j++) dp[0][j] = j;
    for(int i=0; i<=n; i++) dp[i][0] = i;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else
            {
                dp[i][j] = 1 + min(
                        dp[i][j-1],          // Insert
                    min(dp[i-1][j],          // Remove
                        dp[i-1][j-1])        // Replace
                );
            }
        }
    }

    return dp[n][m];


}

int main()
{
    string s1 = "horse";
    string s2 = "ros";
    int n = s1.size();
    int m = s2.size();

    cout << f(s1,s2,n-1,m-1) << endl;

    cout << f3(s1,s2);
}
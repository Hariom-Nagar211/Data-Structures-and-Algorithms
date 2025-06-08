#include<bits/stdc++.h>
using namespace std;

// QUE : Find the longest comman string among the two given strings.

// Recursion
int f(string str1, string str2, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(str1[ind1] == str2[ind2]) return 1 + f(str1, str2, ind1-1, ind2-1);

    else return 0 + max(f(str1, str2, ind1-1, ind2), f(str1, str2, ind1, ind2-1));

    // TC : pow(2,n1)*pow(2,n2)
    // SC : n1 + n2    
}

// Recursion + DP(Memoization)
int f2(string str1, string str2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(str1[ind1] == str2[ind2]) return 1 + f2(str1, str2, ind1-1, ind2-1, dp);

    else return dp[ind1][ind2] = 0 + max(f2(str1, str2, ind1-1, ind2, dp), f2(str1, str2, ind1, ind2-1, dp));

    // TC : n1*n2
    // SC : O(n1 + n2) + O(n1*n2)     
}

int f3(string str1, string str2)
{
    int n1 = str1.size();
    int n2 = str2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=0; i<=n1; i++) dp[i][0] = 0;
    for(int j=0; j<=n2; j++) dp[0][j] = 0;

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n1][n2];

    // TC : n1*n2
    // SC : O(n1*n2)
}

int main()
{
    string str1 = "ecd";
    string str2 = "ced";
    int n1 = str1.size();
    int n2 = str2.size();

    cout << f(str1, str2, n1-1, n2-1) << endl;

    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout << f2(str1, str2, n1-1, n2-1, dp) << endl;

    cout << f3(str1, str2);

}
#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum Insertions/Deletions to Convert String A to String B

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
    string s1 = "abcd";
    string s2 = "anc";
    int n = s1.size();
    int m = s2.size();

    // idea : (n-LCS)+(m-LCS)

    int LCS = f3(s1, s2);
    cout << (n-LCS)+(m-LCS);

}
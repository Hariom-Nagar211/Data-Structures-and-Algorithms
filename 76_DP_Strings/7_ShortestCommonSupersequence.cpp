#include<bits/stdc++.h>
using namespace std;

// QUE : Shortest Common Supersequence

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

string f4(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=0; i<=n1; i++) dp[i][0] = 0;
    for(int j=0; j<=n2; j++) dp[0][j] = 0;

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n1;
    int j = n2;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            s += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
        {
            s += s1[i-1];
            i--;
        }
        else
        {
            s += s2[j-1];
            j--;
        }
    }

    while(i > 0)
    {
        s += s1[i-1];
        i--;
    } 
    while(j > 0)
    {
        s += s2[j-1];
        j--;
    } 

    reverse(s.begin(), s.end());

    return s;
}


int main()
{
    string s1 = "brute";
    string s2 = "groot";  
    int n = s1.size();
    int m = s2.size();

    // Length
    int LCS = f3(s1, s2);
    cout << "length : " << (n+m-LCS) << endl;

    // Printing the string
    string LCS_ = f4(s1, s2);
    cout << "string : " << LCS_;

}
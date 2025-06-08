#include<bits/stdc++.h>
using namespace std;

// QUE : Find the longest comman string among the two given strings.

// Recursion
string f(string str1, string str2, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return "";

    if(str1[ind1] == str2[ind2]) return str1[ind1] + f(str1, str2, ind1-1, ind2-1);
    else return "" + max(f(str1, str2, ind1-1, ind2), f(str1, str2, ind1, ind2-1));
}
string f3(string str1, string str2)
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

    int i = n1;
    int j = n2;
    string s = "";
    int len = dp[n1][n2];
    for(int i=0; i<len; i++) s += '$';
    int ind = len-1;

    while(i > 0 && j > 0)
    {
        if(str1[i-1] == str2[j-1])
        {
            s[ind] = str1[i-1];
            ind--;
            i = i-1;
            j = j-1;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i = i-1;
        }
        else
        {
            j = j-1;
        }
    }

    return s;
    
}

int main()
{
    string str1 = "ecd";
    string str2 = "ced";
    int n1 = str1.size();
    int n2 = str2.size();

    cout << f(str1, str2, n1-1, n2-1) << endl;
    cout << f3(str1, str2) << endl;
}
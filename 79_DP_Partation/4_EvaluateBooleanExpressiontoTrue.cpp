#include<bits/stdc++.h>
using namespace std;

// Evaluate Boolean Expression to True

// Recursion
int f(string exp, int i, int j, int isTrue)
{
    if(i > j) return 0;
    if(i == j) 
    {
        if(isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    int ways = 0;
    for(int ind=i+1; ind<=j-1; ind+=2)
    {
        int LT = f(exp, i, ind-1, 1);
        int LF = f(exp, i, ind-1, 0);
        int RT = f(exp, ind+1, j, 1);
        int RF = f(exp, ind+1, j, 0);

        if(exp[ind] == '&')
        {
            if(isTrue) ways += LT*RT;
            else ways += LT*RF + RT*LF + LF*RF;
        }
        else if(exp[ind] == '|')
        {
            if(isTrue) ways += LF*RT + LT*RF + LT*RT;
            else ways += LF*RF;
        }
        else
        {
            if(isTrue) ways += LT*RF + LF*RT;
            else ways += LT*RT + LF*RF;
        } 
    }

    return ways;
}

// Recursion + DP(Memoization)
int f2(string exp, int i, int j, int isTrue, vector<vector<vector<int>>> dp)
{
    if(i > j) return 0;
    if(i == j) 
    {
        if(isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for(int ind=i+1; ind<=j-1; ind+=2)
    {
        int LT = f2(exp, i, ind-1, 1, dp);
        int LF = f2(exp, i, ind-1, 0, dp);
        int RT = f2(exp, ind+1, j, 1, dp);
        int RF = f2(exp, ind+1, j, 0, dp);

        if(exp[ind] == '&')
        {
            if(isTrue) ways += LT*RT;
            else ways += LT*RF + RT*LF + LF*RF;
        }
        else if(exp[ind] == '|')
        {
            if(isTrue) ways += LF*RT + LT*RF + LT*RT;
            else ways += LF*RF;
        }
        else
        {
            if(isTrue) ways += LT*RF + LF*RT;
            else ways += LT*RT + LF*RF;
        } 
    }

    return dp[i][j][isTrue] = ways;
}

int main()
{
    string exp = "F|T^F";
    int n = exp.size();

    cout << f(exp, 0, n-1, 1) << endl;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    cout << f2(exp, 0, n-1, 1, dp) << endl;
}
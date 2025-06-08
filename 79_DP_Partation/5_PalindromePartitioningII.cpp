#include<bits/stdc++.h>
using namespace std;

// QUE : Palindrome Partitioning - II

bool isPalindrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursion
int f(string s, int n, int i)
{
    if(i == n) return 0;

    int minParts = INT_MAX;
    for(int j=i; j<n; j++)
    {
        if(isPalindrome(s, i, j))
        {
            int cost = 1 + f(s, n, j+1);
            minParts = min(minParts, cost);
        }
    }
    return minParts;
}

// Recursion + DP(Memoization)
int f2(string s, int n, int i, vector<int> dp)
{
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int minParts = INT_MAX;
    for(int j=i; j<n; j++)
    {
        if(isPalindrome(s, i, j))
        {
            int cost = 1 + f2(s, n, j+1, dp);
            minParts = min(minParts, cost);
        }
    }
    return dp[i] = minParts;
}

// Recursion + DP(Tabulation)
int f3(string s, int n)
{
    vector<int> dp(n+1, 0);

    dp[n] = 0;

    for(int i=n-1; i>=0; i--)
    {
        int minParts = INT_MAX;
        for(int j=i; j<n; j++)
        {
            if(isPalindrome(s, i, j))
            {
                int cost = 1 + dp[j+1];
                minParts = min(minParts, cost);
            }
        }
        dp[i] = minParts;
    }

    return dp[0];
}

int main()
{
    string s = "abc";
    int n = s.size();

    cout << f(s, n, 0)-1 << endl;

    vector<int> dp(n, -1);
    cout << f2(s, n, 0, dp)-1 << endl;

    cout << f3(s, n)-1 << endl;

}
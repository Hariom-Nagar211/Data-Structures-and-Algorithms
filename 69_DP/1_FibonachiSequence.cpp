#include<bits/stdc++.h>
using namespace std;

// QUE : Print Nth Fibonachi Number.(0 , 1 , 1 , 2 , 3 , 5...)

// Recursion
int f(int n) 
{
    if(n <= 2) return n-1;

    return f(n-1) + f(n-2);

    // TC : n + ...
    // SC : n 
}

// Recursion + DP
int f2(int n, vector<int> dp) 
{
    if(n <= 2) return n-1; // Base Case

    // Top-Down
    if(dp[n] != -1) return dp[n];

    return dp[n] = f2(n-1, dp) + f2(n-2, dp);

    // TC : n
    // SC : n + n

}

// Tabulation
int f3(int n, vector<int> dp) 
{
    // Base Case
    dp[1] = 0;
    dp[2] = 1;

    // Bottom-Up
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

    // TC : n
    // SC : n

} 

// Tabulation with SC Optimised
int f4(int n) 
{
    int prev2 = 0;
    int prev = 1;
    int curr = (n-1);

    for(int i=3; i<=n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;

    // TC : n
    // SC : 1

} 


int main()
{
    int n = 5;

    cout << f(n) << endl;
    
    vector<int> dp(n+1, -1);
    cout << f2(n, dp) << endl; 

    cout << f3(n, dp) << endl;

    cout << f4(n); 

}
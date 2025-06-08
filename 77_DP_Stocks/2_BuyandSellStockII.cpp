#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stock 

// Recursion
int f(vector<int> price, int ind, int buy)
{
    if(ind == price.size()) return 0;

    int profit = 0;
    if(buy)
    {
        profit = max(-price[ind] + f(price, ind+1, 0), 0 + f(price, ind+1, 1));
    }
    else
    {
        profit = max(price[ind] + f(price, ind+1, 1), 0 + f(price, ind+1, 0));
    }  
    return profit;

    // TC : pow(2,n)
    // SC : N
}

// Recursion + DP(Memoization)
int f2(vector<int> price, int ind, int buy, vector<vector<int>> dp)
{
    if(ind == price.size()) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy)
    {
        profit = max(-price[ind] + f2(price, ind+1, 0, dp), 0 + f2(price, ind+1, 1, dp));
    }
    else
    {
        profit = max(price[ind] + f2(price, ind+1, 1, dp), 0 + f2(price, ind+1, 0, dp));
    }  
    return dp[ind][buy] = profit;

    // TC : n*2
    // SC : N*2 + N
}

// Recursion + DP(Tabulation)
int f3(vector<int> price)
{
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            if(j) profit = max(-price[i] + dp[i+1][0], 0 + dp[i+1][1]);
            else profit = max(price[i] + dp[i+1][1], 0 + dp[i+1][0]);
            dp[i][j] = profit;
        }
    }
    return dp[0][1];

    // TC : n*2
    // SC : N*2 
}

// Recursion + DP(Tabulation) + Space Optimization
int f4(vector<int> price) 
{
    int n = price.size();
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = 0;
    ahead[1] = 0;

    int profit = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            if(j) profit = max(-price[i] + ahead[0], 0 + ahead[1]);
            else profit = max(price[i] + ahead[1], 0 + ahead[0]);
            curr[j] = profit;
        }
        ahead = curr;
    }
    return ahead[1];

    // TC : n*2
    // SC : 1
}

int main()
{
    vector<int> price = {7,1,5,3,6,4};
    int n = price.size();

    cout << f(price, 0, 1) << endl;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << f2(price, 0, 1, dp) << endl;

    cout << f3(price) << endl;
    cout << f4(price) << endl;

}

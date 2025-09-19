#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks III with at max two transctions
// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
private:
    int f(int ind, vector<int>& prices, int n, int hold, int tr, vector<vector<vector<int>>> &dp)
    {
        if(ind == n || tr >= 2) return 0;

        if(dp[ind][hold][tr] != -1) return dp[ind][hold][tr];

        int profit = 0;
        if(hold == 0)
        {
            profit = max(-prices[ind] + f(ind+1, prices, n, 1, tr, dp), f(ind+1, prices, n, 0, tr, dp));
        }
        else
        {
            profit = max(prices[ind] + f(ind+1, prices, n, 0, tr+1, dp), f(ind+1, prices, n, 1, tr, dp));
        }
        return dp[ind][hold][tr] = profit;

    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, prices, n, 0, 0, dp);
        
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

// Per your request, I'm using this namespace.
using namespace std;

int f3(vector<int>& prices, int n)
{
    if (n == 0) {
        return 0;
    }

    // dp[ind][0] -> Max profit at the end of day 'ind', NOT holding a stock.
    // dp[ind][1] -> Max profit at the end of day 'ind', HOLDING a stock.
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // FIX #1: Correct the base case.
    // It's impossible to hold a stock before day 1, so profit must be very low.
    dp[0][1] = -100001;

    for (int ind = 1; ind <= n; ind++)
    {
        for (int holding = 0; holding <= 1; holding++)
        {
            // FIX #2: Corrected state transition logic.
            if (holding == 0) // Calculate max profit for day 'ind' NOT holding a stock.
            {
                // Options: Rest (from not holding) OR Sell (from holding).
                dp[ind][0] = max(dp[ind-1][0], dp[ind-1][1] + prices[ind-1]);
            }
            else // holding == 1. Calculate max profit for day 'ind' HOLDING a stock.
            {
                // Options: Hold (from holding) OR Buy (from not holding).
                dp[ind][1] = max(dp[ind-1][1], dp[ind-1][0] - prices[ind-1]);
            }
        }
    }

    // FIX #3: Return the correct final state.
    // The max profit is on the last day when you are not holding any stock.
    return dp[n][0];
}
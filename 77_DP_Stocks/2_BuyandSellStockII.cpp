#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stock 
// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
private:
    int f(int ind, vector<int>& prices, int n, bool holding)
    {
        if(ind == n) return 0;

        int profit = 0;
        if(holding == false)
        {
            profit = max(-prices[ind] + f(ind+1, prices, n, true), f(ind+1, prices, n, false));
        }
        else
        {
            profit = max(prices[ind] + f(ind+1, prices, n, false), 0 + f(ind+1, prices, n, true));
        }
        return profit;
    }

    int f2(int ind, vector<int>& prices, int n, bool holding, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;

        if(dp[ind][holding] != -1) return dp[ind][holding];

        int profit = 0;
        if(holding == false)
        {
            profit = max(-prices[ind] + f2(ind+1, prices, n, true, dp), f2(ind+1, prices, n, false, dp));
        }
        else
        {
            profit = max(prices[ind] + f2(ind+1, prices, n, false, dp), 0 + f2(ind+1, prices, n, true, dp));
        }
        return dp[ind][holding] = profit;
    }

    int f3(vector<int>& prices, int n)
    {
    // dp[ind][0] -> max profit on day 'ind' if NOT holding a stock.
    // dp[ind][1] -> max profit on day 'ind' if HOLDING a stock.
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Base Case: At the end (after the last day), profit is 0 regardless of holding.
    // dp[n][0] = 0; // Already initialized
    // dp[n][1] = 0; // Already initialized

    // Loop backwards from n-1 to 0, filling the table.
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // Loop through the 'holding' states (0 for false, 1 for true)
        for (int holding = 0; holding <= 1; holding++)
        {
            int profit = 0;
            if (holding == 0) // We are NOT holding a stock
            {
                // The recursive calls f2(ind+1, ...) become lookups in our dp table dp[ind+1][...].
                // Choice: Buy (-prices[ind]) or Rest (0).
                profit = max(-prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            else // We ARE holding a stock
            {
                // Choice: Sell (+prices[ind]) or Hold (0).
                profit = max(prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            dp[ind][holding] = profit;
        }
    }

    // The answer is the max profit on day 0, starting with the ability to buy (not holding).
    return dp[0][0];
}

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return f2(0, prices, n, false, dp);

        return f3(prices, n);
        
    }
};

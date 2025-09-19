# include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks With Cooldown(can't sell and then buy on 
//                                                   consucative  days)
// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
private:
    int f(int ind, vector<int>& prices, int n, int hold)
    {
        if(ind >= n) return 0;

        int profit = 0;
        if(hold == 0)
        {
            profit = max(-prices[ind] + f(ind+1, prices, n, 1), f(ind+1, prices, n, 0));
        }
        else
        {
            profit = max(prices[ind] + f(ind+2, prices, n, 0), f(ind+1, prices, n, 1));
        }
        return profit;
    }

    int f2(int ind, vector<int>& prices, int n, int hold, vector<vector<int>> &dp)
    {
        if(ind >= n) return 0;

        if(dp[ind][hold] != -1) return dp[ind][hold];

        int profit = 0;
        if(hold == 0)
        {
            profit = max(-prices[ind] + f2(ind+1, prices, n, 1, dp), f2(ind+1, prices, n, 0, dp));
        }
        else
        {
            profit = max(prices[ind] + f2(ind+2, prices, n, 0, dp), f2(ind+1, prices, n, 1, dp));
        }
        return dp[ind][hold] = profit;
    }


public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f2(0, prices, n, 0, dp);
        
    }
};

#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks III with at max k transctions
// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
private:
    int f(int ind, vector<int>& prices, int n, int k, int tr, int hold)
    {
        if(ind == n || tr == k) return 0;

        int profit = 0;
        if(hold == 0)
        {
            profit = max(-prices[ind] + f(ind+1, prices, n, k, tr, 1), f(ind+1, prices, n, k, tr, 0));
        }
        else
        {
            profit = max(prices[ind] + f(ind+1, prices, n, k, tr+1, 0), f(ind+1, prices, n, k, tr, 1));
        }
        return profit;
    }

    int f2(int ind, vector<int>& prices, int n, int k, int tr, int hold, vector<vector<vector<int>>> &dp)
    {
        if(ind == n || tr >= k) return 0;

        if(dp[ind][hold][tr] != -1) return dp[ind][hold][tr];

        int profit = 0;
        if(hold == 0)
        {
            profit = max(-prices[ind] + f2(ind+1, prices, n, k, tr, 1, dp), f2(ind+1, prices, n, k, tr, 0, dp));
        }
        else
        {
            profit = max(prices[ind] + f2(ind+1, prices, n, k, tr+1,  0, dp), f2(ind+1, prices, n, k, tr, 1, dp));
        }
        return dp[ind][hold][tr] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f2(0, prices, n, k, 0, 0, dp);

        
    }
};

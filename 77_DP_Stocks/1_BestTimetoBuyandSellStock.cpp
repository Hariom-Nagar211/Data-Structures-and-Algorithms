#include<bits/stdc++.h>
using namespace std;

// QUE : Best Time to Buy and Sell Stocks
// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int buying_price = prices[0];
        int max_profit = 0;
        for(int i=1; i<n; i++)
        {
            if(prices[i] > buying_price)
            {
                max_profit = max(max_profit, prices[i] - buying_price);
            }
            else buying_price = prices[i];
        }
        return max_profit;
        
    }
};


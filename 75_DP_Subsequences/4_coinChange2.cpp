
// Link : https://leetcode.com/problems/coin-change-ii/

class Solution {
private:
    int f3(vector<int>& coins, int amount, int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

        for(int amt=0; amt<=amount; amt++)
        {
            if(amt%coins[0] == 0) dp[0][amt] = 1;
        }

        for(int ind=1; ind<n; ind++)
        {
            for(int amt=0; amt<=amount; amt++)
            {
                int not_take = dp[ind-1][amt];
                int take = 0;
                if(coins[ind] <= amt) take = dp[ind][amt-coins[ind]];

                dp[ind][amt] = take;
                dp[ind][amt] %= INT_MAX;
                dp[ind][amt] += not_take;
            }
        }
        return dp[n-1][amount];
    }

public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        return f3(coins, amount, n);
        
    }
};

// Link : https://leetcode.com/problems/coin-change/

class Solution {
private:
    int f(int ind, vector<int>& coins, int amount, int n)
    {
        if(amount == 0) return 0;
        if(ind == n) return 1e8;

        int not_take = f(ind+1, coins, amount, n);
        int take = 1e8;
        if(coins[ind] <= amount) take = 1 + f(ind+1, coins, amount-coins[ind], n);

        return min(take, not_take);
    }    

    int f2(int ind, vector<int>& coins, int amount, int n, vector<vector<int>> &dp)
    {
        if(amount == 0) return 0;
        if(ind == n) return 1e8;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int not_take = f2(ind+1, coins, amount, n, dp);
        int take = 1e8;
        if(coins[ind] <= amount) take = 1 + f2(ind, coins, amount-coins[ind], n, dp);

        return dp[ind][amount] = min(take, not_take);
    } 

    int f3(vector<int>& coins, int amount, int n)
    {
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e8));

        for(int amt=0; amt<=amount; amt++)
        {
            if(amt%coins[0] == 0) dp[0][amt] = amt/coins[0];
        }

        for(int ind=1; ind<n; ind++)
        {
            for(int amt=0; amt<=amount; amt++)
            {
                int not_take = dp[ind-1][amt];
                int take = 1e8;
                if(coins[ind] <= amt) take = 1 + dp[ind][amt-coins[ind]];

                dp[ind][amt] = min(take, not_take);
            }
        }
        return dp[n-1][amount];
    }


public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int result = f3(coins, amount, n);
        if(result >= 1e8) return -1;
        else return result;
        
    }
};
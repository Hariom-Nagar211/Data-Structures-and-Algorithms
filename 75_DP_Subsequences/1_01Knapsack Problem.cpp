
// Link : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  private:
    int f(int ind, int W, vector<int> &val, vector<int> &wt, int n)
    {
        if(ind == n) return 0; 
        
        int not_take = f(ind+1, W, val, wt, n);
        int take = 0;
        if(wt[ind] <= W) take = val[ind] + f(ind+1, W-wt[ind], val, wt, n);
        
        return max(take, not_take);
    }
    
    int f2(int ind, int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp)
    {
        if(ind == n) return 0; 
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int not_take = f2(ind+1, W, val, wt, n, dp);
        int take = 0;
        if(wt[ind] <= W) take = val[ind] + f2(ind+1, W-wt[ind], val, wt, n, dp);
        
        return dp[ind][W] = max(take, not_take);
    }
    
    int f3(int W, vector<int> &val, vector<int> &wt, int n)
    {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
        
        for(int ind=1; ind<n; ind++)
        {
            for(int w=0; w<=W; w++)
            {
                int not_take = dp[ind-1][w];
                int take = 0;
                if(wt[ind] <= w) take = val[ind] + dp[ind-1][w - wt[ind]];
                
                dp[ind][w] = max(take, not_take);
            }
        }
        return dp[n-1][W];
    }
    
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return f2(0, W, val, wt, n, dp);
        
        return f3(W, val, wt, n);
        
    }
};
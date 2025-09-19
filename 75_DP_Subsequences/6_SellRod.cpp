
// Link : https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution {
  private:
    int f(int ind, int l, vector<int> &price, int n)
    {
        if(l == 0) return 0;
        if(ind == n) return 0;
        
        int not_take = f(ind+1, l, price, n);
        int take = 0;
        if(ind+1 <= l) take = price[ind] + f(ind+1, l-(ind+1), price, n);
        
        return max(not_take, take);
    }
    
    int f2(int ind, int l, vector<int> &price, int n, vector<vector<int>> &dp)
    {
        if(l == 0) return 0;
        if(ind == n) return INT_MIN;
        
        if(dp[ind][l] != -1) return dp[ind][l];
        
        int not_take = f2(ind+1, l, price, n, dp);
        int take = INT_MIN;
        if(ind+1 <= l) take = price[ind] + f2(ind, l-(ind+1), price, n, dp);
        
        return dp[ind][l] = max(not_take, take);
    }
    
    
    int f3(int l, vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(l+1, 0));
        
        for(int j=1; j<=l; j++) dp[0][j] = j*price[0];
        
        for(int ind=1; ind<n; ind++)
        {
            for(int len=1; len<=l; len++)
            {
                int not_take = dp[ind-1][len];
                int take = INT_MIN;
                if(ind+1 <= len) take = price[ind] + dp[ind][len-(ind+1)];
                
                dp[ind][len] = max(not_take, take);
            }
        }
        return dp[n-1][l];
    }
    
  public:
    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f2(0, n, price, n, dp);
        
        return f3(n, price, n);
        
    }
};
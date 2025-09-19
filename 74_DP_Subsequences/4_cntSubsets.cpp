
// Link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution {
  private:
    int f(int ind, vector<int>& arr, int n, int t)
    {
        if(ind == n)
        {
            if(t == 0) return 1;
            else return 0;
        }
        
        int not_take = f(ind+1, arr, n, t);
        int take = 0;
        if(arr[ind] <= t) take = f(ind+1, arr, n, t - arr[ind]);
        
        return (take + not_take);
    }
    
    int f2(int ind, vector<int>& arr, int n, int t, vector<vector<int>> &dp)
    {
        if(ind == n)
        {
            if(t == 0) return 1;
            else return 0;
        }
        
        if(dp[ind][t] != -1) return dp[ind][t];
        
        int not_take = f2(ind+1, arr, n, t, dp);
        int take = 0;
        if(arr[ind] <= t) take = f2(ind+1, arr, n, t - arr[ind], dp);
        
        return dp[ind][t] = (take + not_take);
    }
    
    int f3(vector<int> &arr, int n, int t)
    {
        vector<vector<int>> dp(n, vector<int>(t+1, 0));
        
        // Base case: one subset (empty set) makes sum 0
        dp[0][0] = 1;
    
        // Handle first element
        if(arr[0] <= t) dp[0][arr[0]] += 1;   // subset with arr[0]
        if(arr[0] == 0) dp[0][0] = 2;         // {}, {0}
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=t; tar++)
            {
                int not_take = dp[ind-1][tar];
                int take = 0;
                if(arr[ind] <= tar) take = dp[ind-1][tar - arr[ind]];
                
                dp[ind][tar] = (take + not_take);
            }
        }
        return dp[n-1][t];
        
    }
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return f2(0, arr, n, target, dp);
        
        return f3(arr, n, target);
        
        
    }
};
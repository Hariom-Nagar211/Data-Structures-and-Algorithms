
// Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  private:
    int f(int i, int j, vector<int> &arr)
    {
        if(i+1 == j) return 0;
        
        int mini = 1e9;
        for(int k=i+1; k<j; k++)
        {
            int val = (arr[i]*arr[k]*arr[j]) + f(i, k, arr) + f(k, j, arr);
            mini = min(mini, val);
        }
        return mini;
    }
    
    int f2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(i+1 == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k=i+1; k<j; k++)
        {
            int val = (arr[i]*arr[k]*arr[j]) + f2(i, k, arr, dp) + f2(k, j, arr, dp);
            mini = min(mini, val);
        }
        return dp[i][j] = mini;
    }
    
    int f3(vector<int> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+2; j<=n-1; j++)
            {
                int mini = 1e9;
                for(int k=i+1; k<j; k++)
                {
                    int val = (arr[i]*arr[k]*arr[j]) + dp[i][k] + dp[k][j];
                    mini = min(mini, val);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n-1];
    }
    
    
    
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f2(0, arr.size()-1, arr, dp);
        
        return f3(arr, n);
        
        
        
    }
};
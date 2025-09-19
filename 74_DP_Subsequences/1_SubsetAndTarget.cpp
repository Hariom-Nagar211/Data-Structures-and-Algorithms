
// Link : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{ 
private:
    bool f(int ind, vector<int> &arr, int n, int t)
    {
        if(t == 0) return true;
        if(ind >= n) return false;
        
        bool not_take = f(ind+1, arr, n, t);
        bool take = false;
        if(arr[ind] <= t) take = f(ind+1, arr, n, t-arr[ind]);

        return take || not_take;
    }

    bool f2(int ind, vector<int> &arr, int n, int t, vector<vector<bool>> &dp)
    {
        if(t == 0) return true;
        if(ind >= n) return false;
        
        if (dp[ind][t] != -1) return dp[ind][t];

        bool not_take = f(ind+1, arr, n, t, dp);
        bool take = false;
        if(arr[ind] <= t) take = f(ind+1, arr, n, t-arr[ind], dp);

        return dp[ind][t] = take || not_take;
    }

    bool f3(vector<int> &arr, int n, int t)
    {
        vector<vector<bool>> dp(n, vector<int>(t+1, false));

        for(int i=0; i<n; i++) dp[i][0] = true;
        for(int j=1; j<=t; j++) if(arr[j] == j) dp[0][j] = true;

        for(int ind=1; ind<n; ind++)
        {
            for(int tar=1; tar<=t; tar++)
            {
                bool not_take = dp[ind-1][tar];
                bool take = false;
                if(arr[ind] <= tar) take = dp[ind-1][tar - arr[ind]];

                return dp[ind][tar] = take || not_take;
            }
        }
        return dp[n-1][t];

    }
};
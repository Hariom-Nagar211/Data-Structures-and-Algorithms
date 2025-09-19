
// Que : Print the LIS

class Solution {
private:
    int f(int ind, vector<int>& nums, int n, int prev_ind, int len)
    {
        if(ind == n) return 0;

        if(prev_ind != -1 && nums[ind] <= nums[prev_ind]) return f(ind+1, nums, n, prev_ind, len);
        else
        {
            int take = 1 + f(ind+1, nums, n, ind, len+1);
            int not_take = 0 + f(ind+1, nums, n, prev_ind, len);

            return max(take, not_take);
        }
    }

    int f2(int ind, vector<int>& nums, int n, int prev_ind, int len, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;

        if(dp[ind][prev_ind] != -1) return dp[ind][prev_ind];

        if(prev_ind != 0 && nums[ind] <= nums[prev_ind-1]) return f2(ind+1, nums, n, prev_ind, len, dp);
        else
        {
            int take = 1 + f2(ind+1, nums, n, ind+1, len+1, dp);
            int not_take = 0 + f2(ind+1, nums, n, prev_ind, len, dp);

            return dp[ind][prev_ind] = max(take, not_take);
        }
    }

    // without dp solution
    int f3(vector<int> &nums, int n)
    {
        vector<int> dp(n, 1);

        for(int ind=0; ind<n; ind++)
        {
            for(int prev_ind=0; prev_ind<ind; prev_ind++)
            {
                if(nums[prev_ind] < nums[ind]) dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
            }
        }
        
        int maxi = 1;
        for(int i=0; i<n; i++) maxi = max(dp[i], maxi);
        return maxi;
    }

    // printing the LIS
    int f4(vector<int> &nums, int n)
    {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(i=0; i<n; i++) hash[i] = i;

        for(int ind=0; ind<n; ind++)
        {
            for(int prev_ind=0; prev_ind<ind; prev_ind++)
            {
                if(nums[prev_ind] < nums[ind]) 
                {
                    if(dp[ind] < 1 + dp[prev_ind])
                    {
                        dp[ind] = 1 + dp[prev_ind];
                        hash[ind] = prev_ind;
                    }
                }
            }
        }
        
        int maxi = 1;
        int last_ind = 1;
        for(int i=0; i<n; i++) 
        {
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                last_ind = i;
            }
        }
        return maxi;
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        return f3(nums, n);
        
    }
};
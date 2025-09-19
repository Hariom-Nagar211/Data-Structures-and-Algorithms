#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Increasing Subsequence
// Link : https://leetcode.com/problems/longest-increasing-subsequence/

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

    int f3(vector<int>& nums, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));

        
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f2(0, nums, n, 0, 0, dp);
        
    }
};
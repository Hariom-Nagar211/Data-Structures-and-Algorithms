#include<bits/stdc++.h>
using namespace std;

// QUE : Array ---> Break in two Subarrays ---> if Sum of Subset1 == Subset2, return true else false.
// create target = total_sum/2
// Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
private:
    bool f(int ind, vector<int>& arr, int n, int sum, int totalSum)
    {
        if(sum == totalSum-sum) return true;
        if(ind >= n) return false;

        bool not_take = f(ind+1, arr, n, sum, totalSum);
        bool take = false;
        if(sum < totalSum-sum) take = f(ind+1, arr, n, sum+arr[ind], totalSum);

        return take | not_take;
    }

    bool f2(int ind, vector<int>& arr, int n, int sum, int totalSum, vector<vector<int>> &dp)
    {
        if(sum == totalSum-sum) return true;
        if(ind >= n) return false;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        bool not_take = f2(ind+1, arr, n, sum, totalSum, dp);
        bool take = false;
        if(sum < totalSum-sum) take = f2(ind+1, arr, n, sum+arr[ind], totalSum, dp);

        return dp[ind][sum] = take || not_take;
    }

    bool f3(vector<int> &arr, int n, int t)
    {
        vector<vector<bool>> dp(n, vector<bool>(t+1, false));

        for(int i=0; i<n; i++) dp[i][0] = true;
        if (arr[0] <= t) dp[0][arr[0]] = true;

        for(int ind=1; ind<n; ind++)
        {
            for(int tar=1; tar<=t; tar++)
            {
                bool not_take = dp[ind-1][tar];
                bool take = false;
                if(arr[ind] <= tar) take = dp[ind-1][tar - arr[ind]];

                dp[ind][tar] = take || not_take;
            }
        }
        return dp[n-1][t];

    }



public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += nums[i];
        
        // vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
        // return f2(0, nums, n, 0, totalSum, dp);

        if(totalSum%2 == 0)
        {
            return f3(nums, n, totalSum/2);
        }
        else return false;
    }
};
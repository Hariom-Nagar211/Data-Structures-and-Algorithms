#include<bits/stdc++.h>
using namespace std;

// QUE : Array ---> Break in two Subsets ---> return minimum difference (Subset1 - Subset2).
// Link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

class Solution {
private:
    int f(int ind, vector<int> &arr, int n, int s1Sum, int totalSum, int s1Length)
    {
        if(ind == n) 
        {
            if(s1Length == n/2) return abs((totalSum-s1Sum) - s1Sum);
            else return INT_MAX;
        }

        int not_take = f(ind+1, arr, n, s1Sum, totalSum, s1Length);
        int take = f(ind+1, arr, n, s1Sum+arr[ind], totalSum, s1Length+1);

        return min(not_take, take);
    }

    int f2(int ind, vector<int> &arr, int n, int s1Sum, int totalSum, int s1Length,
           vector<vector<vector<int>>> &dp)
    {
        if (s1Length > n/2) return 1e9; // prune
        if (ind == n) 
        {
            if (s1Length == n/2) return abs((totalSum - s1Sum) - s1Sum);
            return 1e9;
        }

        int &cached = dp[ind][s1Length][s1Sum];
        if (cached != -1) return cached;

        int not_take = f2(ind+1, arr, n, s1Sum, totalSum, s1Length, dp);
        int take = f2(ind+1, arr, n, s1Sum + arr[ind], totalSum, s1Length + 1, dp);

        return cached = min(not_take, take);
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int maxK = n / 2;
        // dp[ind][s1Length][s1Sum]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxK + 1, vector<int>(totalSum + 1, -1)));
        return f2(0, nums, n, 0, totalSum, 0, dp);
    }
};
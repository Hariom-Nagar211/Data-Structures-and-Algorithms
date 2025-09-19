#include<bits/stdc++.h>
using namespace std;

// QUE : Largest Divisible Subset
// Link : https://leetcode.com/problems/largest-divisible-subset/

class Solution {
private:
    vector<int> f(vector<int>& nums, int n)
    {
        vector<int> len(n, 1);
        vector<int> hash(n);
        for(int i=0; i<n; i++) hash[i] = i;

        sort(nums.begin(), nums.end());

        for(int ind=0; ind<n; ind++)
        {
            for(int prev_ind=0; prev_ind<ind; prev_ind++)
            {
                if(nums[ind]%nums[prev_ind] == 0)
                {
                    if(len[ind] < len[prev_ind]+1)
                    {
                        len[ind] = len[prev_ind]+1;
                        hash[ind] = prev_ind;
                    }
                }
            }
        }

        int last_ind = -1;
        int max_len = 0;
        for(int i=0; i<n; i++)
        {
            if(len[i] > max_len)
            {
                max_len = len[i];
                last_ind = i;
            }
        }

        vector<int> ans;
        int prev_ind = last_ind;
        while(hash[prev_ind] != prev_ind)
        {
            ans.push_back(nums[prev_ind]);
            prev_ind = hash[prev_ind];
        }
        ans.push_back(nums[prev_ind]);
        return ans;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        return f(nums, n);
        
    }
};

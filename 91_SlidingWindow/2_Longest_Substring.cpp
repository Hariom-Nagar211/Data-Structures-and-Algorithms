#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Substring Without Repeating Characters.
// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<int, int> mpp; // element , index
        int n = s.size();
        int maxLen = 0;

        int i = 0;
        int j = 0;
        while(j < n)
        {
            if(mpp.find(s[j]) != mpp.end())
            {
                if(mpp[s[j]] >= i) i = mpp[s[j]] + 1;
            }
            maxLen = max(maxLen, j-i+1);
            mpp[s[j]] = j;
            j++;
        }
        return maxLen;
        
    }
};
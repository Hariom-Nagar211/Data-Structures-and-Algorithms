
// link : https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        map<char, int> mpp;
        int maxFreq = 0;
        int maxLen = 0;

        int l = 0;
        int r = 0;
        while(r < n)
        {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            while(r-l+1 - maxFreq > k)
            {
                mpp[s[l]]--; 
                l++;
            }

            if(r-l+1 - maxFreq <= k) maxLen = max(maxLen, r-l+1);

            r++;
        }
        return maxLen;
            
        
    }
};
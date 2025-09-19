
// Link : https://leetcode.com/problems/longest-string-chain/description/

class Solution {
private:
    static bool myComp(string &a, string &b)
    {
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }

    bool predecessor(string a, string b)
    {
        if(a.size()+1 == b.size())
        {
            for(int i=0; i<b.size(); i++)
            {
                string temp = b;
                temp.erase(i, 1);

                if(a == temp) return true;
            }            
        }
        return false;
    }

public:
    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(), words.end(), myComp);

        vector<int> len(n, 1);
        
        for(int ind=0; ind<n; ind++)
        {
            for(int prev_ind=0; prev_ind<ind; prev_ind++)
            {
                if(predecessor(words[prev_ind], words[ind]))
                {
                    len[ind] = max(len[ind], 1+len[prev_ind]);
                }
            }
        }

        int max_len = 0;
        for(int i=0; i<n; i++)
        {
            max_len = max(max_len, len[i]);
        }
        return max_len;
        
    }
};
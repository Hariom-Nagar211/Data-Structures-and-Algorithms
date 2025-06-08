#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Substring Without Repeating Characters.

// Brute 
int f(string s, int n)
{
    int maxLen = 0;
    for(int i=0; i<n; i++)
    {
        string sub = "";
        unordered_map<char,int> mpp;
        for(int j=i; j<n; j++)
        {
            if(mpp[s[j]] >= 1)
            {
                maxLen = max(maxLen, (int)sub.size());
                break;
            }
            else
            {
                mpp[s[j]]++;
                sub += s[j];
            }
        }
    }
    return maxLen;

    // LC : Generating all Substrings + Frequency Map
    // TC : N*N
    // SC : 256
}

// Using Sliding Window
int f2(string s, int n)
{
    int maxLen = 0;
    unordered_map<char,int> mpp;
    int i = 0;
    int j = 0;

    while(j < n)
    {
        mpp[s[j]]++;

        while(mpp[s[j]] > 1)
        {
            mpp[s[i]]--;
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
        
        j++;
    }
    return maxLen;

    // LC : Sliding Window + Freq Map
    // TC : 2*N
    // SC : 256
}

int main()
{
    string s = "cadbzabcd";
    int n = s.size();

    cout << f(s, n) << endl;
    cout << f2(s, n) << endl;
}

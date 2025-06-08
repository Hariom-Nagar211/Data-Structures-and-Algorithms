#include<iostream>
#include<unordered_map>
using namespace std;

int f(string s = "AABABBA", int n = 7, int k = 2)
{
    int maxLen = 0;
    int maxFreq = 0;
    unordered_map<char, int> mpp;
    int i = 0;
    int j = 0;

    // Transformations = Total - maxFreq
    while(j < n)
    {
        mpp[s[j]]++;
        maxFreq = max(maxFreq, mpp[s[j]]);

        while(j-i+1 - maxFreq > k)
        {
            mpp[s[i]]--; 

            maxFreq = 0;
            for(int i=0; i<26; i++) maxFreq = max(maxFreq, mpp[i]);
            
            i++;
        }

        if(j-i+1 - maxFreq <= k) maxLen = max(maxLen, j-i+1);

        j++;
    }
    return maxLen;
}

int main()
{
    cout << f() << endl;
}
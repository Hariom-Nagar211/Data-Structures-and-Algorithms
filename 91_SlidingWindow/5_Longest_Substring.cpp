#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Que : Find the longest substring with atmost K distinct characters

int f(string s, int n, int k)
{
    int i = 0;
    int j = 0;
    unordered_map<char, int> mpp;
    int unqCnts = 0;
    int maxLen = 0;

    while(j < n)
    {
        mpp[s[j]]++;
        unqCnts = mpp.size();

        while(unqCnts > k)
        {
            if(mpp[s[i]] == 1)
            {
                mpp.erase(s[i]); 
                unqCnts--;
            } 
            else mpp[s[i]]--;
            i++;
        }

        maxLen = max(j-i+1, maxLen);

        j++;
    }
    return maxLen;
}

int main()
{
    string s = "aaabbccd";
    int n = s.size();
    int k = 2;

    cout << f(s, n, k) << endl;
}
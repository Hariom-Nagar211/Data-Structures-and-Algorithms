#include<bits/stdc++.h>
using namespace std;

// Problem Statement: You are given a string s and a string t. 
// You have to return the number of substrings in s that contain all the characters of string t.
// Link : https://leetcode.com/problems/minimum-window-substring/submissions/1830086004/

// LC:
// TC: 
// SC: 

int f(string s, int n, string t, int m) 
{
    vector<int> required(26, 0), window(26, 0);
    
    for (char c : t) required[c - 'a']++;

    int i = 0, j = 0, count = 0, matched = 0;
    
    while (j < n) 
    {
        // Expand the window
        if (required[s[j] - 'a'] > 0) 
        {
            window[s[j] - 'a']++;
            if (window[s[j] - 'a'] == required[s[j] - 'a']) matched++;
        }

        // Shrink the window if all characters are matched
        while (matched == m) 
        {
            count += (n - j); // Count valid substrings
            
            if (required[s[i] - 'a'] > 0) 
            {
                if (window[s[i] - 'a'] == required[s[i] - 'a']) matched--;
                window[s[i] - 'a']--;
            }
            i++;
        }

        j++;
    }
    return count;
}

int main()
{
    string s = "ddaaabbca";
    int n = s.size();
    string t = "abc";
    int m = t.size();

    cout << f(s, n, t, m);
}
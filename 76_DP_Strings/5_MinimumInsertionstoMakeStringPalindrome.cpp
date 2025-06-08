#include<bits/stdc++.h>
using namespace std;

// QUE : Minimum Insertions to Make String Palindrome

int f(string s, int i, int j)
{
    if(i == j) return 0;
    if(s[i] == s[j] && j == i+1) return 0;

    if(s[i] == s[j]) return 0 + f(s, i+1, j-1);
    else return min(1 + f(s, i, j-1), 1 + f(s, i+1, j));
}

// Method 2
// n - Longest Palindromic Subsequence

int main()
{
    string s = "ymzzwh";
    int n = s.size();

    cout << f(s, 0, n-1);
}
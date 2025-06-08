#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Palindromic Subsequence

string f(string str1, string str2, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return "";

    if(str1[ind1] == str2[ind2]) return str1[ind1] + f(str1, str2, ind1-1, ind2-1);
    else return "" + max(f(str1, str2, ind1-1, ind2), f(str1, str2, ind1, ind2-1));
}

int main()
{
    string s1 = "bbabab";
    int n = s1.size();

    string s2 = s1;
    reverse(s2.begin(), s2.end());

    cout << f(s1, s2, n-1, n-1);
}
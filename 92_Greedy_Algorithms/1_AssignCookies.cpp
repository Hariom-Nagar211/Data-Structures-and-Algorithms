#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given two arrays representing children’s green factor and cookie sizes, 
// the goal is to maximise the number of content children.

// LC: Greedy Algorithm(Sorting)
// TC: O(n log n + m log m)
// SC: O(1) 

int AssignCookies(vector<int> greed, vector<int> cookiesSize)
{
    int n = greed.size();
    int m = cookiesSize.size();

    sort(greed.begin(), greed.end());
    sort(cookiesSize.begin(), cookiesSize.end());

    int i = 0; // greed
    int j = 0; // cookiesSize
    while(i < n && j < m)
    {
        if(greed[i] <= cookiesSize[j]) i++;

        j++;
    }
    return j;
}
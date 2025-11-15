#include<bits/stdc++.h>
using namespace std;

// Que: Given an array of integers, find the number of subarrays with exactly k different integers.
// Link : https://leetcode.com/problems/subarrays-with-k-different-integers/

// LC: Sliding Window
// TC: O(n)
// SC: O(k)

int atMostKDistinct(vector<int> arr, int n, int k)
{
    unordered_map<int, int> mpp; // element, frequency
    
    int cnt = 0;
    int uniqueElements = 0;
    int i = 0;
    int j = 0;

    while(j < n)
    {
        if(mpp[arr[j]] == 0) uniqueElements++;
        mpp[arr[j]]++;

        while(uniqueElements > k)
        {
            mpp[arr[i]]--;
            if(mpp[arr[i]] == 0) uniqueElements--;
            i++;
        }

        cnt += (j - i + 1); // Count all subarrays ending at j

        j++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1,2,1,3,4};
    int n = 5;
    int k = 3;

    cout << atMostKDistinct(arr, n, k) - atMostKDistinct(arr, n, k-1) << endl;
}
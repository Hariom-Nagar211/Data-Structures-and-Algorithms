#include<bits/stdc++.h>
using namespace std;

// QUE : Maximum Points You Can Obtain from k Cards consucatively from front, back or both.
// Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1824780154/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;

        for(int i=0; i<k; i++) lsum += cardPoints[i];

        maxSum = lsum;

        int t = 1;
        for(int i=n-1; i>= n-k; i--)
        {
            lsum = lsum - cardPoints[k - t];
            t++;

            rsum += cardPoints[i];

            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
        
    }
};
#include<bits/stdc++.h> 
using namespace std;

// Que: Find maximum subarray sum in an array.

// Brute Force
// LC : Try out all sub arrays
// TC : O(n*n)  
// SC : O(1)

// Optimal
// LC : Kadane's Algorithm
// TC : O(n)
// SC : O(1)

int maxSubArraySum(vector<int>& arr) {
    int current_sum = 0;
    int max_sum = INT_MIN;

    for (int num : arr) 
    {
        current_sum = max(num, current_sum + num); // Include or start new subarray
        max_sum = max(max_sum, current_sum);       // Update max_sum if needed
    }
    return max_sum;
}
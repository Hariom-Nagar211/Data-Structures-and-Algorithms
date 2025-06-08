#include<bits/stdc++.h>
using namespace std;

// Que : Find the length of longest subarray with sum k

void logic()
{
    // brute: Variables(Sum, Max_len) Two Pointer Approach(j=i)
    //    TC: O(n*n), SC: O(1)

    // better: Variables(Map, preSum, Max_len, rem = preSum - k)  
    //     TC: O(nlog(n)), if unordered map O(n), SC: O(n)

    // optimal: Move ---> Exceeds --->  Shrink (Sliding Window)
    //          Two Pointer Approach
    //          Variables(Max_len, Sum)
    //      TC: O(2n), SC: O(1)

    
}

int brute(vector<int> arr, int n, int k)
{
    int sum = 0;
    int max_len = 0;
    for(int i=0; i<n; i++)
    {
        sum = 0;
        for(int j=i; j<n; j++)
        {
            if(sum < k)
            {
                sum = sum + arr[j];
            }
            else if(sum == k)
            {
                max_len = max(max_len, j+1-i-1);
                break;
            }
            else
            {
                break;
            }
        }
    }
    return max_len;
}

int better(vector<int> arr, int n, int k)
{
    map<int, int> mpp;
    int preSum = 0;
    int max_len = 0;

    for(int i=0; i<n; i++)
    {
        preSum = preSum + arr[i]; 
        if(preSum == k)
        {
            max_len = i+1;
        }
        else
        {
            int rem = preSum - k;
            if(mpp.find(rem) != mpp.end())
            {
                max_len = max(max_len, i - mpp[rem]);
            }
        }
        if(mpp.find(preSum) == mpp.end())
        {
            mpp[preSum] = i;
        }
        return max_len;
  
    }

}

int optimal(vector<int> arr, int n, int k)
{
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int max_len = 0;

    while(right < n)
    {
        while(left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if(sum == k)
        {
            max_len = max(max_len, right - left + 1);
        }
        right++;
        if(right < n)
        {
            sum += arr[right];
        }

        return max_len;

    }

}

int main()
{
    cout << "size: " << brute({1,2,3,0,0,1,1,4,2,3}, 10, 5) << endl;

    cout << "size: " << brute({1,2,3,0,0,1,1,4,2,3}, 10, 5) << endl;

    cout << "size: " << optimal({1,2,3,0,0,1,1,4,2,3}, 10, 5);

}
#include<iostream>
#include<vector>
using namespace std;

// Que: You are given a binary array, count the total number of subarrays with sum 2.

// LC: Sliding Window
// TC: N
// SC: 1

// Count the subarrays having sum <= k
int helper(vector<int> arr, int n, int k) // 1 0 1 0 1
{
    int cnt = 0;
    int sum = 0;
    int i = 0;
    int j = 0;

    while(j < n)
    {
        sum += arr[j]; 

        while(sum > k)
        {
            sum -= arr[i];
            i++;
        }

        cnt += (j - i + 1);

        j++;
    }
    return cnt;
}

// Count the subarrays having sum = 2
int f(vector<int> arr, int n)
{
    return (helper(arr, n, 2) - helper(arr, n, 1));
}

int main()
{
    vector<int> arr = {1,0,1,0,1};
    int n = arr.size();

    cout << f(arr, n) << endl;
}
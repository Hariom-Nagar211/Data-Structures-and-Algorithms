#include<bits/stdc++.h>
using namespace std;

// Que : Find the minimum energy required to the frog from jump(1 step or 2 steps)
//       1 to n-1 stairs, energy = |arr[i] - arr[i+1]| or |arr[i] - arr[i+2]|

// Recursion
int f(vector<int> arr, int ind)
{
    if(ind == 0) return 0;

    int left = abs(arr[ind] - arr[ind-1]) + f(arr, ind-1);
    int right = 1e8;
    if(ind > 1) right = abs(arr[ind] - arr[ind-2]) + f(arr, ind-2);

    return min(left, right);

}

// Recursion + Memoization
int f2(vector<int> arr, int ind, vector<int> dp)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int left = abs(arr[ind] - arr[ind-1]) + f(arr, ind-1);
    int right = 1e8;
    if(ind > 1) right = abs(arr[ind] - arr[ind-2]) + f(arr, ind-2);

    return dp[ind] = min(left, right);
}

// Tabulation
int f3(vector<int> arr, int n, vector<int> dp2)
{
    dp2[0] = 0;

    for(int i=1; i<n; i++)
    {
        int left = abs(arr[i] - arr[i-1]) + dp2[i - 1];
        int right = 1e8;
        if(i > 1) right = abs(arr[i] - arr[i-2]) + dp2[i-2];

        dp2[i] = min(left, right);
    }
    return dp2[n-1];

}

int main()
{
    vector<int> arr = {10,20,30,10,40,60,50,20,10,90};
    int n = arr.size();

    cout << f(arr, n-1) << endl;

    vector<int> dp(n, -1);
    cout << f2(arr, n-1, dp) << endl;
    
    vector<int> dp2(n, 0);
    cout << f3(arr, n, dp2) << endl;
}
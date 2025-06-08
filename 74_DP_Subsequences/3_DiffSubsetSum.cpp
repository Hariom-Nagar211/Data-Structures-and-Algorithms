#include<bits/stdc++.h>
using namespace std;

// QUE : Array ---> Break in two Subsets ---> return minimum difference (Subset1 - Subset2).

// Recursion
int f(int ind, int sum, vector<int>& arr, int total) 
{
    if (ind == arr.size()) 
    {
        return abs((total - sum) - sum);
    }
    
    int not_take = f(ind + 1, sum, arr, total);
    int take = f(ind + 1, sum + arr[ind], arr, total);
    
    return min(take, not_take);
}

// Tabulation
int f3(vector<int> arr, int n)
{
    int total = 0;
    for(int i=0; i<n; i++) total += arr[i];
    int t = total;

    vector<vector<bool>> dp(n, vector<bool>(t+1, false));

    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= t) dp[0][arr[0]] = true;

    for(int ind=1; ind<n; ind++)
    {
        for(int tar=1; tar<=t; tar++)
        {
            int not_take = dp[ind-1][tar];
            int take = false;
            if(tar >= arr[ind]) take = dp[ind-1][tar - arr[ind]];

            dp[ind][tar] = not_take || take;
        }
    }
    
    int mini = 1e9;
    for(int s1=0; s1<=total/2; s1++)
    {
        if(dp[n-1][s1] == true)
        {
            mini = min(mini, abs((total-s1)-s1));
        }
    }
    return mini;

}

int main()
{
    vector<int> arr = {3,6,2,1,7,8};
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    
    cout << f(0, 0, arr, total) << endl;

    cout << f3(arr, n);
}
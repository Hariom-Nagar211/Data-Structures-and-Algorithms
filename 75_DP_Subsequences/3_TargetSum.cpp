#include<bits/stdc++.h>
using namespace std;

// QUE : https://bit.ly/3swy5uL
// Logic: |S1 - S2| = t

// Recursion
int f(vector<int> arr, int ind, int sum1, int toSum, int t)
{
    if((sum1 - (toSum-sum1)) == t) return 1;
    if(ind == arr.size()) return 0;

    int not_take = f(arr, ind+1, sum1, toSum, t);
    int take = f(arr, ind+1, sum1+arr[ind], toSum, t);

    return (not_take + take);
}

// error
// Recursion + DP(Memoization)
int f2(vector<int> arr, int ind, int sum1, int toSum, int t, vector<vector<int>> &dp)
{
    if((sum1 - (toSum-sum1)) == t) return 1;
    if(ind == arr.size()) return 0;

    int not_take = f(arr, ind+1, sum1, toSum, t);
    int take = f(arr, ind+1, sum1+arr[ind], toSum, t);

    return (not_take + take);

}



int main()
{
    vector<int> arr = {1,2,3,1};
    int n  = arr.size();
    int t = 3;

    cout << f(arr, 0, 0, t) << endl;

    int toSum = 0;
    for(int i=0; i<n; i++) toSum += arr[i];
    vector<vector<int>> dp(n, vector<int>(toSum+1, -1));
    cout << f2(arr, 0, 0, t, dp) << endl;
}
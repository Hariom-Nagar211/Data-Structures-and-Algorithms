#include<bits/stdc++.h>
using namespace std;

// Error
// QUE : 

// Recursion + DP(memoization)
int f(int ind, vector<int> arr)
{
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    int take = INT_MIN;
    if(ind != 0) take = arr[ind] + f(ind-2, arr);
    int notTake = 0 + f(ind-1, arr);

    return max(take, notTake);
}

int main()
{
    vector<int> arr = {1,2,4,9};
    int n = arr.size();

    cout << f(n-1, arr);
}
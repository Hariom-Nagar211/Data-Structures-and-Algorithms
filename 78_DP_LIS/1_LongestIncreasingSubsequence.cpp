#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Increasing Subsequence

// Recursion
int f(vector<int> arr, int ind, int prev_ind)
{
    int n = arr.size();
    if(ind == n) return 0;

    int len = 0 + f(arr, ind+1, prev_ind);
    if(prev_ind == -1 || arr[prev_ind] < arr[ind]) len = max(1 + f(arr, ind+1, ind), len);

    return len;
        
}

// Recursion + DP(Memoization)
int f2(vector<int> arr, int ind, int prev_ind, vector<vector<int>> dp)
{
    if(ind < 0) return 0;

    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

    int len = 0 + f2(arr, ind+1, prev_ind, dp);
    if(prev_ind == -1 || arr[prev_ind] < arr[ind]) len = max(1 + f2(arr, ind+1, ind, dp), len);

    return dp[ind][prev_ind+1] = len;
}

// Recursion + DP(Tabulation)
int f3(vector<int> arr, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind=n-1; ind>=0; ind--)
    {
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--)
        {
            int len = 0 + dp[ind+1][prev_ind+1];
            if(prev_ind == -1 || arr[prev_ind] < arr[ind]) 
                len = max(1 + dp[ind+1][ind+1], len);
        }
    }
    return dp[0][-1+1];
}

// unique solution to print LCS

int f4(vector<int> arr, int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int i=0; i<n; i++)
    {
        for(int prev=0; prev<i; prev++)
        {
            if(arr[prev] < arr[i])
                dp[i] = max(1 + dp[prev], dp[i]); 
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
    
}

// printing the string
void f5(vector<int> arr, int n)
{
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    
    for(int i=0; i<=n-1; i++){
        
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    cout<<"The subsequence elements are ";
    
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    
    return ans;
}

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();

    cout << f(arr, 0, -1) << endl;

    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << f2(arr, 0, -1, dp) << endl;

    cout << f3(arr, n);

}
#include<bits/stdc++.h>
using namespace std;

// QUE : https://bit.ly/3H10kYJ

// Recursion
int f(vector<int> length, vector<int> price, int ind, int len)
{
    if(ind == price.size()-1)
    {
        if(len >= length[ind]) return (len/length[0])*price[ind];  
        else return 0;      
    }

    int not_take = 0 + f(length, price, ind+1, len);
    int take = INT_MIN;
    if(len >= length[ind]) take = price[ind] + f(length, price, ind, len-length[ind]);

    return max(take, not_take);

}

// Recursion + DP(Memoiztion)
int f(vector<int> length, vector<int> price, int ind, int len, vector<vector<int>> &dp)
{
    if(ind == price.size()-1)
    {
        if(len >= length[ind]) return (len/length[0])*price[ind];  
        else return 0;      
    }

    if(dp[ind][len] != -1) return dp[ind][len];

    int not_take = 0 + f(length, price, ind+1, len);
    int take = INT_MIN;
    if(len >= length[ind]) take = price[ind] + f(length, price, ind, len-length[ind]);

    return dp[ind][len] = max(take, not_take);

}



int main()
{
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {3,5,8,9,10,17,17,20};
    int n = length.size();
    int len = 8;

    cout << f(length, price, n-1, len);
}
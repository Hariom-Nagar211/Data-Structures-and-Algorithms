# include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks With Cooldown(can't sell and then buy on 
//                                                   consucative  days)

// Recursion + DP(Tabulation)
int f3(vector<int> price)
{
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            if(j) profit = max(-price[i] + dp[i+1][0], 0 + dp[i+1][1]);
            else profit = max(price[i] + dp[i+2][1], 0 + dp[i+1][0]);
            dp[i][j] = profit;
        }
    }
    return dp[0][1];

    // TC : n*2
    // SC : N*2 
}

int main()
{
    vector<int> price = {7,1,5,3,6,4};
    int n = price.size();

    cout << f3(price) << endl;

}

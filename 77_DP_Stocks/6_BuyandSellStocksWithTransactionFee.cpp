#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks With Transaction Fee

// Recursion
int f(vector<int> price, int trFee, int ind, int buy)
{
    if(ind == price.size()) return 0;

    int profit = 0;
    if(buy)
    {
        profit = max(-price[ind] + f(price, trFee, ind+1, 0), 0 + f(price, trFee, ind+1, 1));
    }
    else
    {
        profit = max(price[ind] + f(price, trFee, ind+1, 1)-trFee, 0 + f(price, trFee, ind+1, 0));
    }  
    return profit;

}

int main()
{
    vector<int> price = {7,1,5,3,6,4};
    int n = price.size();

    cout << f(price, 2, 0, 1) << endl;

}

#include<bits/stdc++.h>
using namespace std;

// QUE : Buy and Sell Stocks III with at max k transctions

// Recursion
int f(vector<int> price, int ind ,int buy, int tr)
{
    if(ind == price.size()) return 0;
    if(tr == 0) return 0;

    int profit = 0;
    if(buy) profit = max(-price[ind] + f(price, ind+1, 0, tr), 0 + f(price, ind+1, 1, tr));
    else profit = max(price[ind] + f(price, ind+1, 1, tr-1), 0 + f(price, ind+1, 0, tr));

    return profit;
}

int main()
{
    vector<int> price = {3,3,5,0,0,3,1,4};
    int n = price.size();

    int k = 4;

    cout << f(price, 0, 1, k);
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Problem: Fractional Knapsack
// Given items with values and weights, maximize the total value in a bag with a weight limit.
// Items can be divided into fractions to achieve the optimal solution.

// LC: Greedy + Sorting
// TC: NlogN
// SC: 1

int f(vector<pair<int,int>> items, int bagWt)
{
    int n = items.size();

    sort(items.begin(), items.end() , [](const pair<int,int> &a, const pair<int,int> &b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    
    int wt = 0;
    int val = 0;
    for(int i=0; i<n; i++)
    {
        if(items[i].second <= (bagWt-wt))
        {
            wt += items[i].second;
            val += items[i].first;
        }
        else
        {
            val += ((double)items[i].first / items[i].second) * (bagWt - wt);
            break;
        }
    }
    return val;
}

int main()
{
    vector<pair<int, int>> items = {{100,20}, {60,10}, {100,50}, {200,50}};
    int bagWt = 90;
    cout << f(items, bagWt) << endl;
}
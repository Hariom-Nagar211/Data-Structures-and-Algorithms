#include<bits/stdc++.h>
using namespace std;

// QUE : Best Time to Buy and Sell Stocks

int main()
{
    vector<int> arr = {6,20,5,7,8,9};
    int n = arr.size();
    
    if (n == 0) cout << 0 << endl;
    
    int mini = arr[0]; // store minimum buying price so far
    int maxProfit = 0; 
    for(int i=1; i<n; i++)
    {
        int profit = arr[i] - mini; // profit if selled in arr[i] 
        maxProfit = max(profit, maxProfit); 
        mini = min(arr[i], mini); // minimum buying price so far
    }
    cout << maxProfit << endl;
}


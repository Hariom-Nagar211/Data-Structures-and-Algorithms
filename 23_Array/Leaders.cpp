#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Find all the leaders in an array.
// A leader is an element that is strictly greater than all the elements to its right.
// For example, in the array {10, 22, 12, 3, 0, 6}, the leaders are 22, 12, 6.

// Brute
// LC: Select and iterate in rest array
// TC: O(n*n)
// SC: 1

// Optimal
// LC: Print Maxi from last to first
// TC: O(n)
// SC: 1

void Optimal(vector<int> arr)
{
    vector<int> ans;
    int maxi = INT_MIN;

    for(int i = arr.size()-1; i>=0; i--)
    {
        if(arr[i] >= maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    for(int i=ans.size()-1; i>=0; i--)
    {
        cout << ans[i] << " ";
    }

    
}

int main()
{
    vector<int> arr = {10,22,12,3,0,6};
    vector<int> res;

    int maxi = arr[0];
    int index = 0;
    int i = 0;

    while(i != arr.size())
    {
        while(i<arr.size())
        {
            if(maxi <= arr[i])
            {
                maxi = arr[i];
                index = i;
            }
            i++;
        }
        res.push_back(maxi);
        maxi = -1;
        i = index + 1;
    }

    for(int j=0; j<res.size(); j++)
    {
        cout << res[j] << " ";
    }

    cout << endl;

    Optimal(arr);
}

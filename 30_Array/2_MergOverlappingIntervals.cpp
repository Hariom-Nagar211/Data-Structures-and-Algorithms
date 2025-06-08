#include<bits/stdc++.h>
using namespace std;

// Que: Merg all the overlapping intervals of an array of intervals.

void f(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    int temp[2];

    sort(arr.begin(), arr.end());

    temp[0] = arr[0][0];
    temp[1] = arr[0][1];
    for(int i=0; i<n; i++)
    {
        if(arr[i][0] <= temp[1])
        {
            if(temp[1] < arr[i][1]) temp[1] = arr[i][1];
        }
        else
        {
            ans.push_back({temp[0],temp[1]});
            temp[0] = arr[i][0];
            temp[1] = arr[i][1];
        }
    }
    ans.push_back({temp[0],temp[1]});

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

   
}

int main()
{
    vector<vector<int>> arr = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
                           // {1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}

    f(arr);                         
}

// TC: n
// SC: 1
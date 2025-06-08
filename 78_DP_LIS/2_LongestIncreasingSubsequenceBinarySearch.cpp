#include<bits/stdc++.h>
using namespace std;

// QUE : Longest Increasing Subsequence

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();

    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else 
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout << len;

}

// 1, 4, 7, 8, 16  ---> 1, 4, 8, 16
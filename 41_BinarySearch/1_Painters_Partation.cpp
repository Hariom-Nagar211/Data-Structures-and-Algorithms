#include<bits/stdc++.h>
using namespace std;

// Que: https://bit.ly/3XM8oFS

int f(vector<int> arr, int time)
{
    int n = arr.size();
    int cnt_ptrs = 1, cnt_time = 0;

    for(int i=0; i<n; i++)
    {
        if(cnt_time + arr[i] <= time) cnt_time += arr[i];
        else
        {
            cnt_ptrs++;
            cnt_time = arr[i];           
        }
    }
    return cnt_ptrs;
}

int Brute(vector<int> arr, int ptrs)
{
    int n = arr.size();
    int mini = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    for(int time=mini; time<=maxi; time++)
    {
        int cnt_ptrs = f(arr, time);
        if(cnt_ptrs == ptrs) return time;
    }
}

int Optimal(vector<int> arr, int ptrs)
{
    int n = arr.size();
    int mini = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    int ans = 0;
    int low = mini;
    int high = maxi;
    while(low <= high)
    {
        int time = (low + high)/2;
        int cnt_ptrs = f(arr, time);
        if(cnt_ptrs > ptrs) low = time + 1;
        else high = time - 1, ans = time;
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int ptrs = 2;

    cout << Brute(arr, ptrs);
    cout << endl;
    cout << Optimal(arr, ptrs);
}
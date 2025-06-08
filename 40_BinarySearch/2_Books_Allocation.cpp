#include <bits/stdc++.h>
using namespace std;

// Que: https://bit.ly/3MZQOct

int f(vector<int> arr, int pgs)
{
    int n = arr.size();
    int cnt_std = 1, pgs_std = 0;
    for (int i = 0; i < n; i++)
    {
        if(pgs_std + arr[i] <= pgs)
        {
            pgs_std += arr[i];
        }
        else
        {
            cnt_std++;
            pgs_std = arr[i];
        }
    }
    return cnt_std;
}

int Brute(vector<int> arr, int std)
{
    int n = arr.size();
    int mini = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    for (int pgs = mini; pgs <= maxi; pgs++)
    {
        int cnt_std = f(arr, pgs);
        if (cnt_std == std) return pgs;
    }
}

int Optimal(vector<int> arr, int std)
{
    int n = arr.size();
    int mini = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    int low = mini;
    int high = maxi;
    while(low <= high)
    {
        int pgs = (low + high)/2;
        int cnt_std = f(arr, pgs);
        if(cnt_std > std) low = pgs + 1;
        else high = pgs - 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int std = 4;

    cout << Brute(arr, std);
    cout << endl;
    cout << Optimal(arr, std);
}
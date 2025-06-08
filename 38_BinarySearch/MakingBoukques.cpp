#include <bits/stdc++.h>
using namespace std;

// Link: https://bit.ly/43ScDRY
// Que: Find minimum number of days to make m boukets from k adjecent bloomed flowers.
//      you are given array nth day at which flower will bloom.

bool possible(vector<int> arr, int val, int m, int k)
{
    int n = arr.size();
    int cnt = 0;
    int bks = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= val)
            cnt++;
        else
        {
            bks += (cnt / k);
            cnt = 0;
        }
    }

    bks += (cnt / k);

    if(bks >= m) return true;
    else return false;

}

int Brute(vector<int> arr, int m, int k)
{
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    if (m * k > n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }

    for(int i=mini; i<=maxi; i++)
    {
        if(possible(arr, i, m, k) == 1) return i;
    }
    return -1;

    // TC: n + (maxi-mini)*n
}      

int Optimal(vector<int> arr, int m, int k)
{
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int ans = INT_MAX;

    if (m * k > n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }

    int low = mini;
    int high = maxi;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(possible(arr, mid, m, k) == 0) low = mid + 1;
        else
        {
            ans = min(ans, mid);
            high = mid - 1;
        } 
    }
    return ans;

    // Logic: BinarySearch because we can select one side of array on the basis of a particular value.
    //    TC: n + log(2,maxi-mini+1)*n
}        

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 12, 11, 7}; // 7,8,9,10,11,12,13
    int m = 2;
    int k = 3;

    cout << Brute(arr, m, k);
    cout << endl;
    cout << Optimal(arr, m, k);
}
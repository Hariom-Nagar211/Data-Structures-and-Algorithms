#include<bits/stdc++.h>
using namespace std;

// Que: count the number of subarrays with xor k.

void Logic()
{
    /*
    Brute: Cheaq for all the subarrays.
       TC: n*n
       SC: 1

    Optimal: using x  = xor_^k
         TC: nlogn
         SC: n   
    */
}

void Brute(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        int xor_ = 0;
        for(int j=i; j<n; j++)
        {
            xor_ = xor_^arr[j];
            if(xor_ == k)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}

void Optimal(vector<int> arr, int k)
{
    int cnt = 0;
    map<int, int> mpp;
    int xor_ = 0;
    mpp[xor_]++;

    for(int i=0; i<arr.size(); i++)
    {
        xor_ = xor_^arr[i];
        int x = xor_^k;
        cnt += mpp[x];
        mpp[xor_]++;
    }
    cout << cnt;

}

int main()
{
    vector<int> arr = {4,2,2,6,4};// x = xor_^k
    int k = 6;

    Brute(arr, k);
    cout << endl;
    Optimal(arr, k);
}
#include<bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/max-consecutive-ones/submissions/1825704231/

void f(vector<int> arr, int n, int k)
{
    int i = 0;
    int j = 0;
    int cnt_0 = 0;
    int max_size = 0;
    while(j < n)
    {
        if(arr[j] == 0) cnt_0++;

        while(cnt_0 > k)
        {
            if(arr[i] == 0) cnt_0--;
            i++;
        }

        max_size = max(max_size, j-i+1);

        j++;
    }
    cout << max_size << endl;

    // LC : Sliding Window
    // TC : 2N
    // SC : 1
}

int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int n = arr.size();
    int k = 2;

    f(arr, n, k);
}
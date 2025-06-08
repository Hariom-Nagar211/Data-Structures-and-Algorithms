#include<bits/stdc++.h>
using namespace std;

void Prime(vector<int> &arr, int n)
{
    for(int i=2; i<=n; i++)
    {
        if(arr[i])
        {
            for(int j=(i*i); j<=n; j+=i) arr[j] = 0;
        } 
    }

    // O(Nlog(logN))
}

int Optimal(int l, int r)
{
    vector<int> arr(r+1, 1);
    Prime(arr, r);
    int cnt = 0;

    for(int i=l; i<=r; i++)
    {
        if(arr[i])
        {
            cout << i << " ";
            cnt++;
        }    
    }

    return cnt;
}

int main()
{
    int l = 5;
    int r = 15;

    cout << endl << Optimal(l, r);
}
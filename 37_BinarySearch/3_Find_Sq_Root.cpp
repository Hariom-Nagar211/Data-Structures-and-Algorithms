#include<bits/stdc++.h>
using namespace std;

// Que: Find the square root of given integer.

int Better(int n)
{
    int ans = 0;

    for(int i=0; i<=n; i++)
    {
        long long val = i*i;
        if(val <= n) ans = i;
        else break;
    }
    return ans;

    // Logic: Use the ans trick in linear search.
    //    TC: n
}

int Optimal(int n)
{
    int ans = 0;

    int low = 1;
    int high = n;
    while(low <= high)
    {
        long long mid = (low + high)/2;
        long long val = mid*mid;
        if(val <= n) 
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;

    // Logic: Use the ans trick in BS
    //    TC: log(2,n)
}

int main()
{
    int n  = 37;

    cout << Better(n);
    cout << endl;
    cout << Optimal(n);
}
#include<bits/stdc++.h>
using namespace std;

// Find nth root of m.(ex1: n = 3, m = 27, ans = 3, ex2: n = 4, m = 64, ans = -1)

int Brute(int n, int m)
{
    for(int i=0; i<=m; i++)
    {
        long long val = pow(i,n);
        if(val == m) return i;
        else if(val > m) break;
    }
    return -1;
}

int f(int mid, int n, int m)
{
    long long ans = 1;
    for(int i=0; i<n; i++)
    {
        ans = ans*mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

int Optimal(int n, int m)
{
    int low = 0;
    int high = m;
    while(low <= high)
    {
        long long mid = (low+high)/2;
        // long long val = pow(mid, n); overflow
        int val = f(mid, n, m);
        if(val == 1) return mid;
        else if(val == 2) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 3;
    int m = 27;

    cout << Brute(n, m);
    cout << endl;
    cout << Optimal(n, m);
}
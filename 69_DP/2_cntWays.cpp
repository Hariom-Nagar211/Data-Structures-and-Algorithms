#include<bits/stdc++.h>
using namespace std;

// QUE : Count the number of ways to climb stairs from 0th to Nth stair, 
//       you can climb 1 or 2 upward stairs from a stair.

int f(int ind)
{
    if(ind == 0 || ind == 1) return 1;

    int left = f(ind - 1);
    int right = f(ind - 2);

    return left + right;
}

int main()
{
    int n = 3;
    cout << f(n-1);
}


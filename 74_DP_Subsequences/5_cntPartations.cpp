#include<bits/stdc++.h>
using namespace std;

// QUE : Count pairs of s1, s2 such that |s1 - s2| = d.

// Recursion
int f(vector<int> arr, int ind, int t)
{
    if(t == 0) return 1;
    if(ind == 0)
    {
        if(arr[ind] == t) return 1;
        else return 0;
    }

    int not_take = f(arr, ind-1, t);
    int take = 0;
    if(arr[ind] <= t) take = f(arr, ind-1, t-arr[ind]);

    return (take + not_take);

}

int main()
{
    vector<int> arr = {5,2,6,4};
    int n = arr.size();
    int d = 5;
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    int t = (sum - d);

    if(t >= 0 && t%2 == 0)
    {
        cout << f(arr, n-1, t/2);
    }
    else cout << 0;

    
}
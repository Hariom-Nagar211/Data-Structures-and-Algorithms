#include<bits/stdc++.h>
using namespace std;

int f(vector<int> arr, int n)
{
    int jumps = 0;
    int i = 0, j = 0;

    while(j < n-1)
    {
        int farthest = 0;

        for(int k=0; k<j; k++)
        {
            farthest = max(farthest, i+arr[k]);
        }
        
        i = j+1;
        j = farthest;
        jumps++;
    }
    return jumps;
}

int main()
{
    vector<int> arr = {};
    int n = arr.size();

    cout << f() << endl;
}
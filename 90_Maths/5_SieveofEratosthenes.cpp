#include<bits/stdc++.h>
using namespace std;

// QUE : Given a number N, print all prime till N.

void Brute(int n)
{
    for(int i=2; i<=n; i++) 
    {
        int flag = 0;
        for(int j=2; j<=sqrt(i); j++) 
        {
            if(i % j == 0) flag = 1;
        }
        if(flag == 0) cout << i << " "; 
    }

    // TC : n*sqrt(n)
    // SC : 1
}

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

void Optimal(int n)
{
    vector<int> arr(n+1);
    for(int i=0; i<=n; i++) arr[i] = 1;
    Prime(arr, n);

    for(int i=2; i<=n; i++)
    {
        if(arr[i]) cout << i << " ";
    }
}

int main()
{
    int n = 15;

    Brute(n);
    cout << endl;
    Optimal(n);
}
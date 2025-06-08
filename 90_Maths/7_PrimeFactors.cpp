#include<bits/stdc++.h>
using namespace std;

// print prime factors by division method

void PrimeFactors(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(n == 1) break;
        if(n%i == 0)
        {
            cout << i << " ";
            n = n/i;
            i--;
        } 
    }
}

int main()
{
    int n = 15;

    PrimeFactors(n);
}
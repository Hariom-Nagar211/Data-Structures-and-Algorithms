#include<bits/stdc++.h>
using namespace std;

// Brute Force
void print_Divisors1(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(n%i == 0)
        {
            cout << i << " ";
        }
    }

    // TC : O(n)
    // SC : O(1)
}

// Optimized Approach
void print_Divisors2(int n)
{
    int limit = sqrt(n);
    for(int i=1; i<=limit; i++)
    {
        if(n%i == 0)
        {
            cout << i << " ";
            if(n/i != i)
            {
                cout << n/i << " ";
            }
        }
    }

    // TC : O(sqrt(n))
    // SC : O(1)
}

int main()
{
    print_Divisors2(36);
}




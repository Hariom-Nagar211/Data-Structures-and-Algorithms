#include<bits/stdc++.h>
using namespace std;

// QUE : Print all Divisors of a Number

void PrintDivisors(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;

    // TC : N
    // SC : 1
}

void PrintDivisors2(int n)
{
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cout << i << " ";
            if(n/i == i) break;
            cout << n/i << " ";
        }
    }

    // TC : sqrt(N)
    // SC : 1
}



int main()
{
    int n = 36;

    PrintDivisors(n);

    PrintDivisors2(n);

}
#include<bits/stdc++.h>
using namespace std;

// QUE : Check if a Number if Prime or not

bool checkPrime(int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n = 2763237;

    cout << checkPrime(n);
}
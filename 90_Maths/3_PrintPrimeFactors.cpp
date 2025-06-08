#include<bits/stdc++.h>
using namespace std;

// QUE : Print all prime factors of a Number

bool checkPrime(int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void PrimeFactors(int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(checkPrime(i)) cout << i << " ";
            if(n/i == i) break;
            if(checkPrime(n/i)) cout << n/i << " ";
        }
    }
    cout << endl;
}

// using long division method
void PrimeFactors2(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(n % i == 0)
        {
            cout << i << " ";
            n = n/i;
            i--;
        }
    }
}

int main()
{
    int n = 206;

    PrimeFactors(n);
    PrimeFactors2(n);

}
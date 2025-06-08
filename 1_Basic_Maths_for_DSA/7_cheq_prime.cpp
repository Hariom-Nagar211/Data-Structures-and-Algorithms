#include<iostream>
using namespace std;

// Brute Force
bool cheq_prime1(int n)
{
    for(int i=2; i<n; i++)
    {
        if(n%i == 0)
        {
           return 0;
        }
    }
    return 1;

    // TC : O(n)
    // SC : O(1)
}

// Optimized Approach
void cheq_prime2(int n)
{
    if (n <= 1) 
    {
        cout << "not prime\n";
        return;
    }
    
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            cout << "not prime\n";
            return;
        }
    }
    cout << "prime\n";
}


int main()
{
    cheq_prime2(111);
}


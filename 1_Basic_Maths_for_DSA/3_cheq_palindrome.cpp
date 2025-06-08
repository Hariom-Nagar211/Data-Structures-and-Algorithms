#include<iostream>
using namespace std;

// LC : Digit Exracting Concept
// TC : O(log10(n))
// SC : O(1)

bool cheq_palindrome(int n)
{
    int revNum = 0;
    int store_n = n;
    while(n > 0)
    {
        int ld = n%10;
        revNum = (revNum*10) + ld;
        n = n/10;
    }
    return revNum == store_n;
}

int main()
{
    cout << cheq_palindrome(1321);
}


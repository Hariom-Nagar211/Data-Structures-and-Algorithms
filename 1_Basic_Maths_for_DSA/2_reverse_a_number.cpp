#include<iostream>
using namespace std;

// LC : Digit Exracting Concept
// TC : O(log10(n))
// SC : O(1)

int reverseNumber(int n)
{
    int revNum = 0;
    while(n > 0)
    {
        int ld = n%10;
        revNum = (revNum*10) + ld;
        n = n/10;
    }
    return revNum;

    
    
}

int main()
{
    cout << reverseNumber(12321);
}


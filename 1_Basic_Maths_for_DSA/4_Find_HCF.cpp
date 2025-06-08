#include<iostream>
using namespace std;

// Brute
// LC: 
// TC:
// SC:

// Optimal
// LC: Euclidean algorithm
// TC:
// SC:

// Brute Force
int Find_HCF1(int n1, int n2)
{
    int HCF = 0;
    for(int i = min(n1, n2); i >= 1; i--)
    {
        // Check if 'i' is a common divisor of both numbers
        if(n1 % i == 0 && n2 % i == 0)
        {
           HCF = i; 
           break;  
        }
    }
    return HCF; 
}

// Euclidean algorithm
// If a and b are two integers, and a > b, 
// then the HCF of a and b is the same as the HCF of b and a % b.
int Find_HCF2(int n1, int n2)
{
    // Continue until one of the numbers becomes 0
    while(n1 > 0 && n2 > 0)
    {
        if(n1 > n2)
        {
            n1 = n1 % n2; 
        }
        else
        {
            n2 = n2 % n1; 
        }
    }

    if(n1 == 0)
    {
        return n2;
    }
    else
    {
        return n1; 
    }
}

int main()
{
    cout << "HCF using method 1: " << Find_HCF1(110, 15) << endl;

    cout << "HCF using method 2: " << Find_HCF2(110, 15) << endl;

    return 0; 
}

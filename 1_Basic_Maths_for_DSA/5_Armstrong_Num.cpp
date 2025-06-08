#include<iostream>
using namespace std;

// An Armstrong number equals the sum of the cubes of its digits.
// For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.

// LC: Digit Exracting Concept
// TC:
// SC: 

bool cheq_Armstrong(int n)
{
    int store_n = n;
    int cubed_sum = 0;
    while(n > 0)
    {
        int ld = n%10;
        cubed_sum += ld*ld*ld;
        n = n/10;
    }
   return cubed_sum == store_n;

}

int main()
{
    cout << cheq_Armstrong(76);
}




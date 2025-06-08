#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Que: Given an Integer N, count the number of digits in N.

// Brute
// LC: Digit Exracting Concept
// TC: log10(N) + 1
// SC: 1

// Optimal
// LC: count = log(n) + 1
// TC: log10(N) + 1
// SC: 1

void cntDigits(int n)
{
    int cnt = 0;
    int dmyN = n;
    while(n > 0)
    {
        dmyN = dmyN/10;
        cnt++;
    }
    cout << cnt << endl;

}

void cntDigits2(int N)
{
    int cnt = int(log10(N) + 1);
    cout << cnt;
}


int main()
{
    int N = 2;
    cntDigits(N);
    cntDigits2(N);
}

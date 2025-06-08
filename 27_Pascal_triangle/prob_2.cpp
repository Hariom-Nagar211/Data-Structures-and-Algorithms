#include<iostream>
using namespace std;

// Que: Print rth row of pascal triangle.

void Logic()
{
    /*
    Brute: Loop + nCr
       TC: O(r*c), SC: O(1)

    Optimal: Find new logic from nCr.
         TC: O(n), SC(1)   
    */
}

int nCr(int r, int c)
{
    int e = 1;
    for(int i=r, j=1; i>=c, j<=c; i--, j++)
    {
        e = (e*i)/j;
    }
    return e;
}

void Brute(int r)
{
    for(int c=1; c<=r; c++)
    {
        cout << nCr(r-1,c-1) << " ";
    }       
}

void Optimal(int r)
{
    cout << 1 << " ";
    int ans = 1;
    for(int c=1; c<=r-2; c++)
    {
        ans = ans*(r-c)/c;
        cout << ans << " ";
    }
    cout << 1;
}


int main()
{
    int r = 7;

    Brute(r);
    cout << endl;
    Optimal(r);
}
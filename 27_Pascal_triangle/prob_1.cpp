#include<iostream> 
using namespace std;

// Que: Find the (r,c) element in pascal triangle.

// TC: O(c), SC:O(1)

void nCr(int r, int c)
{
    int e = 1;
    for(int i=r, j=1; i>=c, j<=c; i--, j++)
    {
        e = (e*i)/j;
    }
    cout << e;
}

int main()
{
    int r = 5;
    int c = 3;
    nCr(r-1,c-1);

}
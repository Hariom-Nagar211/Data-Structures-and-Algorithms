#include<bits/stdc++.h>
using namespace std;

// QUE : Power Exponentiation

int Optimal(int x, int n)
{
    int res = 1;
    while(n > 0)
    {
        if(n % 2 == 0)
        {
            x = x*x;
            n = n/2;
        }
        else
        {
            res = res*x;
            n = n - 1;
        }
    }
    return res;
    
    // TC : log(2, n)
    // SC : 1
}

int main()
{
    int n = 3;
    int p = 9;

    int res = 1;
    for(int i=1; i<=p; i++) res = res*n;

    cout << res << endl;
    cout << Optimal(n, p);

}
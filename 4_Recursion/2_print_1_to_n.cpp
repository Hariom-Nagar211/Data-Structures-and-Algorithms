#include<iostream>
using namespace std;

void Print1ToN(int i, int n)
{
    if(i > n) return;
    else
    {
        cout << i << " ";
        Print1ToN(i+1,n);
    }

    // TC : N
    // SC : N(Auxiliary)
}

int main()
{
    int n;
    cout << "enter n:";
    cin >> n;
    Print1ToN(1,n);
}
#include<iostream>
using namespace std;

void PrintNto1(int i, int n)
{
    if(i < 1) return;
    else
    {
        cout << i << " ";
        PrintNto1(i-1,n);
    }
}

int main()
{
    int n;
    cout << "enter n:";
    cin >> n;
    PrintNto1(n,n);
}


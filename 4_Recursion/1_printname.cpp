#include<iostream>
using namespace std;

int name = 0;

void f(int i, int n)
{
    if(i > n) return;
    
    cout << "hariom tat sat\n";
    f(i+1, n);

    // TC : O(n)
    // SC : O(n) ---> auxilarry space ---> no of functions inserted in stack space
}

int main()
{
    int n;
    cin >> n;
    f(1, n);
}


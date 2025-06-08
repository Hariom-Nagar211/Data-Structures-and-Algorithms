#include<iostream>
using namespace std;

int printFact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n*printFact(n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << printFact(n);
}
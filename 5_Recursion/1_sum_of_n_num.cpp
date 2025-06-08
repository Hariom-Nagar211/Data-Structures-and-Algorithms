#include<iostream>
using namespace std;

// My method

void printSum(int n, int i = 1, int sum = 0)
{   
    if(n < i)
    {
        cout << sum;
        return;
    }
    else
    {
        sum = sum + i;
        printSum(n, i+1, sum);
    }

}

// method 1 : using parameter

void printSum1(int n, int sum = 0)
{
    if(n < 1)
    {
        cout << sum;
        return;
    }

    else
    {
        printSum1(n-1,sum + n);
    }
}

// method 2 : Functional recursion

int printSum2(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n + printSum2(n-1);
    }
}


int main()
{
    int n;
    cin >> n ; 
    // printSum(n);
    // printSum1(n);
    cout << printSum2(n);
}
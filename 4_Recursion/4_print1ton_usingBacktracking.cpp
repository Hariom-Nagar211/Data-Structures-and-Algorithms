#include<iostream>
using namespace std;

void print_1_to_n_using_backtracking(int i, int n)
{
    if(i < 1) return;
    else
    {
        print_1_to_n_using_backtracking(i-1,n);
        cout << i << " ";
    }

    // TC : N
    // SC : N(Auxiliary)
}

int main()
{
    int n;
    cout << "enter n:";
    cin >> n;
    print_1_to_n_using_backtracking(n,n);
}

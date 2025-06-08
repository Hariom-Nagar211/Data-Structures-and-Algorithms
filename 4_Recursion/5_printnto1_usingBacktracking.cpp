#include<iostream>
using namespace std;

void print_n_to_1_using_backtracking(int i, int n)
{
    if(i > n) return;
    else
    {
        print_n_to_1_using_backtracking(i+1,n);
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
    print_n_to_1_using_backtracking(1,n);
}

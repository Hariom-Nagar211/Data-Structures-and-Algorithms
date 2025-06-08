#include<bits/stdc++.h>
using namespace std;

int print_fib(int n)
{
   if(n == 1) return 0;
   if(n == 2) return 1;

   int last = print_fib(n-1);
   int slast = print_fib(n-2);

   return last + slast;

   // TC : 2^n --> Total Nodes in Recursion Tree
   // SC : n  ---> Height of Recursion Tree
}

int main()
{
   cout << print_fib(8);
}

// draw tree digram also
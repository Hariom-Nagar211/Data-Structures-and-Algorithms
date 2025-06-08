#include<iostream>
using namespace std;

// Recursion: A programming technique where a function calls itself repeatedly until a specified base condition is met, 
//            enabling problem-solving by breaking it into smaller sub-problems.
// base case  
// stack overflow
// recursion tree
    
void f(int count)
{
   if(count == 5) return;

    cout << count << " ";
    count++;
    f(count);
}

int main()
{
    int cnt = 0;
    f(cnt);
}

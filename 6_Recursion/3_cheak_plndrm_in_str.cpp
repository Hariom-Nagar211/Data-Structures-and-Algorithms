#include<bits/stdc++.h>
using namespace std;

string str = "abcdeffedcba";
int n = 12;

void cheak_palindrome(int a)
{
   if(str[a] == str[n-a-1])
   {
      if(a >= n-a-1)
      {
         cout << "it is a palindrome";
         return;
      }
      return cheak_palindrome(a+1);
   }
   else
   {
      cout << "it is not a palindrome";
   }
}

int main()
{
    cheak_palindrome(0);
}
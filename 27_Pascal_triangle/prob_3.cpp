#include<iostream>
using namespace std;

// Que: Print complete pascal triangle upto n.

void Logic()
{
  /*
  Brute: loop*loop*nCr.
     TC: O(n*n*n), SC: O(1)

  Optimal: loop with modified nCr.
       TC: O(n*n), SC: (1)   
  */
}

int nCr(int r, int c)
{
  int e = 1;
  for(int i=r, j=1; i>=c, j<=c; i--, j++)
  {
    e = (i*e)/j;
  }
  return e ;
}

void Brute(int n)
{
   for(int r=1; r<=n; r++)
   {
      for(int c=1; c<=r; c++)
      {
        cout << nCr(r-1,c-1) << " ";
      }
      cout << endl;
   }
}

void Optimal(int n)
{
  for(int r=1; r<=n; r++)
  {
    if(r != 1) cout << 1 << " ";
    int ans = 1;
    for(int c=1; c<=r-2; c++)
    {
      ans = ans*(r-c)/c;
      cout << ans << " ";
    }
    cout << 1 << endl;
  }       
}


int main()
{
    int n = 5;

    Brute(n);
    cout << endl;
    Optimal(n);
}
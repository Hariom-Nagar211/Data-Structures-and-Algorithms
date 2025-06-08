#include<bits/stdc++.h>
using namespace std;


// Que: Find the number of times a number appear in an string.

int n;
char arr[256];
char a;
char c;

// Method 1 : 

void LOGIC_1()
{
    // iterate over the array
}

// Method 2 :

void count_num()
{
   
   int hash[256] = {0};
   for(int i=0; i<n; i++)
   {
    hash[arr[i]]++;
   }

   cout << c << " occured " << hash[c] << " times"; 


}

int main()
{
    cout << "enter size of array: ";
    cin >> n;
    cout << "enter array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the character: ";
    cin >> c;

    count_num();
}

void LOGIC_2()
{
    // Hashing and typecasting
}

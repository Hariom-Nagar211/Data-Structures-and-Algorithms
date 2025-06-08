#include<iostream>
using namespace std;

/* Some more array hashing methods 
   1. Division method
   2. Folding method
   3. Mid square method */

// Que : Find the frequency of a number appear in an array, using
//       hash array of size < 10.

// Division Method

int arr[10];
int n;
int num;

void cnt_num()
{
    int hash[10] = {0};

    for(int i=0; i<n; i++)
    {
        hash[arr[i]%10]++;
    }

    cout << num << " occured " << hash[num%10] << " times";
}

int main()
{
    cout << "enter size of array: ";
    cin >> n;
    cout << "enter the array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "enter the number: ";
    cin >> num;

    cnt_num();

}

void logic()
{
    // using %10 over the numbers and then storing.
}

// note : you can do chain numbers in a sorted order using linklist

// collosion : all your keys end up in the same hash space.
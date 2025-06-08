#include<iostream>
using namespace std;

// m1 ---> without recursion

int arr[] = {1,7,3,9,54,5};
int n = 6;

void rev_arr1(int n, int arr[])
{
    for(int i=0,j=n-1; i<=(n-1)/2,j>=(n-1)/2; i++,j--)
    {
       int temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;        
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

// m2 ---> by using recursion

void rev_arr2(int a, int b, int size)
{
    if(a >= b)
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }    
    }
    else
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        rev_arr2(a+1, b-1,size);
    }
}

// m3 ---> only using one variable

void rev_arr3(int a = 0)
{
    
    if(a >= n-a-1)
    {
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }    
    }
    else
    {
        int temp = arr[a];
        arr[a] = arr[n-a-1];
        arr[n-a-1] = temp;
        rev_arr3(a+1);
    }
}

int main()
{
    // rev_arr1(5, arr);
    // rev_arr2(0,4,5);
    // rev_arr3();
}

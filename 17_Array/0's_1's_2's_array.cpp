#include<bits/stdc++.h>
using namespace std;

// Que: Sort the array containing 0's, 1's and 2's.

void logic()
{
    /*
    brute: Using Merg Sort
       TC: O(nlogn)
       Sc: O(n)
       
    better: Using variables count0, count1, count2.
        TC: O(2n)
        SC: O(1)
        
    optimal: Using Dutch National Flag Algorithm
             Sketch - - [0, low-1, low, mid-1, mid, high, high+1, n-1]
         TC: O(n)
         SC: O(1)           */
}

void better(vector<int> &arr)
{
    int n = arr.size();
 
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;


    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        else if(arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i < count0)
        {
            arr[i] = 0;
        }
        else if(i >= count0 && i < (count1 + count0))
        {
            arr[i] = 1;
        }
        else if(i >= (count1 + count0) && i < (count0 + count1 + count2))
        {
            arr[i] = 2;
        }
    }

}

void optimal(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
   vector<int> arr;
   arr = {1,0,1,0,1,2,0,0,2,0,};

   optimal(arr);

   for(int i=0; i<arr.size(); i++)
   {
        cout << arr[i] << " ";
   }

}
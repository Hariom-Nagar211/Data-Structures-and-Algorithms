#include<bits/stdc++.h>
using namespace std;

// Que: Rearrange array elements by alternate sign(pos = neg = n/2).

// Brute 
// LC : Using Positive and Negative Hash Array and Two Pointers
// TC : O(2n)
// SC : O(n)

// Optimal
// LC : Using Hash Array + Two Pointers(i = 0 and j = n/2)
// TC : O(n)
// SC : O(n)


void brute1(vector<int> arr)
{
    int n = arr.size();

    vector<int> hash(n);
    int j = 0;
    int k = n/2;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            hash[j] = arr[i];
            j++;
        }
        else
        {
            hash[k] = arr[i];
            k++;
        }
    }

    j = 0;
    k = n/2;

    for(int i=0; i<n; i++)
    {   
        if(i%2 == 0)
        {
            arr[i] = hash[j];
            j++;
        }
        else
        {
            arr[i] = hash[k];
            k++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

void brute2(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    for(int i=0; i<(n/2); i++)
    {
        arr[i*2] = pos[i];
        arr[(i*2) + 1] = neg[i];
    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

void optimal1(vector<int> arr)
{
    int n = arr.size();
    vector<int> hash(n);
    int j = 0;
    int k = 1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            hash[j] = arr[i];
            j = j + 2;
        }
        else
        {
            hash[k] = arr[i];
            k = k + 2;
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << hash[i] << " ";
    }
}



int main()
{
    brute2({3,1,-2,-5,3,-4});
}
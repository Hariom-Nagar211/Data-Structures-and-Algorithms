#include<bits/stdc++.h>
using namespace std;

// Que: Find majority(>(n/2)) occured element in an array(arr[i] <= n).

void logic()
{
    /*
    
    brute: Using Two Nested Loops
       TC: O(n*n)
       SC: O(1)
       
    better1: Using Hash Array
         TC: O(2n)
         SC: O(n)
         
    better2: Using Map
         TC: O(nlogn) + O(n)
         SC: O(n)         
         
    optimal: Using Moore's Voting Algorithm
             Variables(Candidate and Vote)
             check
         TC: O(n) + O(n)[if elmt might not be] 
         SC: O(1)

    */
}

void better1(vector<int> arr)
{
    int n = arr.size();
    int maj = n/2;
    int hash[n] = {0};

    for(int i=0; i<n; i++)
    {
        hash[arr[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        if(hash[i] > maj)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
}

void better2(vector<int> arr)
{
    int n = arr.size();

    map<int,int> mpp;

    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it: mpp)
    {
        if(it.second > (n/2))
        {
            cout << it.first;
            return;
        }
    }
    cout << -1;
}

void optimal(vector<int> arr)
{
    int n = arr.size();
    int element = arr[0];
    int count = 0;

    for(int i=1; i<n; i++)
    {
        if(element == arr[i])
        {
            count++;
        }
        else if(count == 0)
        {
            element = arr[i+1];
        }
        else
        {
            count--;
        }
    }

    count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == element)
        {
            count++;
        }
    }

    if(count > (n/2))
    {
        cout << element;
        return;
    }
    cout << -1;
    
}

int main()
{
    better1({4,4,4,4,4,5,3}); 
    cout << endl;
    optimal({4,4,4,4,4,5,3});
}
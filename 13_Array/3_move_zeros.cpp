#include<bits/stdc++.h>
using namespace std;

// Que: move all zeros to end.

void Logic()
{
    // Brute: non-zero elements into temp array --- shift temp to arr --- rest=0.
    // TC: O(n), SC(n)

    // Optimal: store first zero index in j ---> move inde i from j+1, keep swaping. 
    //          (two pointer approach)
    // TC: O(n), SC: O(1)

}

void brute(int arr[], int n)
{
    int temp[n];
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    for(int i=0; i<j; i++)
    {
        arr[i] = temp[i];
    }

    int zeros = n-j;
    for(int i=j; i<n; i++)
    {
        arr[i] = 0;
    }

    cout << "modified array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

}

void optimal(int arr[], int n)
{
    int j = -1;
    for(int i=0; i<n; i++)      // O(x)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
        
    }

    for(int i=j+1; i<n; i++)           // O(n-x)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "modified array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "enter size: ";
    cin >> n;

    int arr[n];
    cout << "enter array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // brute(arr, n);
    optimal(arr, n);
}


#include<bits/stdc++.h>
using namespace std;

// Que: Find Next Permutation in an Array.

// Brute
// LC : Try All Possible Combinations
// TC : N*N
// SC : 1

// Better
// LC : Use STL function next_permutation()
// TC : O(nlogn)
// SC : O(n)

// Optimal
// LC : Find Breakpoint and store index.
//     Swap arr[index] with greater but the least element.
//     Reverse
// TC : O(3n)
// SC : O(1)[we are modifing array in this case so it can be O(n)]

void better(vector<int> arr)
{
    int n = arr.size();

    next_permutation(arr.begin(), arr.end());

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void optimal(vector<int> arr)
{
    int n = arr.size();
    int index = -1;

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i-1] < arr[i])
        {
            index = i-1;
            break;
        }
    }

    for(int i=n-1; i>=index; i--)
    {
        if(arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    if(index == -1)
    {
        reverse(arr.begin(), arr.end());
    }

    else
    {
        reverse(arr.begin() + index + 1, arr.end());
    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

}

int main()
{
    better({2,1,5,4,3,0,0});
    optimal({2,1,5,4,3,0,0});

}
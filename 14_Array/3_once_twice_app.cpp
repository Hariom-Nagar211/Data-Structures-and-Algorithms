#include<iostream>
#include<vector>
using namespace std;

// Que: Find the number which appear ones in an array(all numbers appers twice
//      except one number).

void logic()
{
    /* brute: Linear Search
          TC: O(n*n), SC:O(1)

       better1: Hashing(size = max element + 1)
           TC: O(2n + max), SC: O(n)

       better2: Using Map data structure
            TC: O(n/2 + 1) + O(nlog(m)), SC: O(n/2 + 1)
    

       optimal: XOR
            TC: O(n), SC: O(1)   */
}

int optimal(vector<int> arr, int n)
{
    int XOR = 0;
    for(int i=0; i<n; i++)
    {
        XOR = XOR^arr[i];
    }

    return XOR;
}

int main()
{
    cout << "num is: " << optimal({1,2,2,3,3,4,4,5,5}, 9);
}
#include<iostream>
#include<vector>
using namespace std;

// Que: Find the max consucative ones in an array.

void logic()
{
    // optimal: Using variables len and maxLen
    //      TC: O(n), SC: O(1) 
}

void optimal(vector<int> arr)
{
    int n = arr.size();

    int len = 0;
    int maxLen = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == 1)
        {
            len++;
            if(len > maxLen)
            {
                maxLen = len;
            }
        }
        else
        {
            len = 0;
        }
    }

    cout << "max_consucative_ones are: " << maxLen;
    
}

int main()
{
    cout << "enter size: ";
    int n;
    cin >> n;

    cout << "enter array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    optimal(arr);
}
#include<bits/stdc++.h>
using namespace std;

int n; 
int arr[100];
int num;

void count_num()
{
    map<int, int> mpp;
    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }

    // cout << num << " occured " << mpp[num] << " times" << endl;
    for(auto it : mpp)
    {
        cout << it.first << "--->" << it.second << endl;
    }
}

int main()
{
    cout << "enter size: ";
    cin >> n;
    cout << "enter array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    // cout << "enter the number: ";
    // cin >> num;

    count_num();

}

// Note : map can also be used for string hashing

void LOGIC()

{
    // using STL function map;
}

/* Calculating TC:

storing and fetching in map always take TC = log(n) in all cases
(best, avg, wrost) where n --> no of elements in map.

we can also use unordered_map instead of map because its best and avg case 
TC is O(1) and wrost case is O(n), the wrost case very rarly happen due to
internal collisions*/



#include<bits/stdc++.h>
using namespace std;

// Que: Find the intersection of two sorted arrays.

void logic()
{
    // optimal: two pointer approach.
    // TC: O(n1 + n2)
    // SC: O(1)
}

void intersection(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> interArr;

    int i=0;
    int j=0;

    while(i<n1 && j<n2)
    {
        if(a[i] == b[j])
        {
            interArr.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << "intersection: ";
    for(int i=0; i<interArr.size(); i++)
    {
        cout << interArr[i] << " ";
    }
}

int main()
{
    intersection({1,2,2,9,4}, {2,2,9,9,7});
}
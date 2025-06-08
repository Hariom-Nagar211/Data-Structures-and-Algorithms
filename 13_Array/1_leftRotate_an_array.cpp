#include<bits/stdc++.h>
using namespace std;

// Que: WAP to left rotate an array by one place.

void Logic()
{
    // store(v[0]) --- left_Shift --- transfer(v[0]->v[n-1])
}

int main()
{
    cout << "enter size: ";
    int n;
    cin >> n;

    cout << "enter array: ";
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    int temp = v[0];
    for(int i=0; i<n-1; i++)
    {
        v[i] = v[i+1];
    }
    v[n-1] = temp;

    cout << "modified array: ";
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }


}
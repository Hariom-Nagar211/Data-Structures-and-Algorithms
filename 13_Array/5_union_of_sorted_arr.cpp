#include<bits/stdc++.h>
using namespace std;

// Que: Find the union of two sorted arrays

void Logic()
{
    // brute: using set
    // optimal: using two pointer approach
    // TC: O(m+n), SC: O(m+n)[to return the answer not for solving problem]
}

void Brute(vector<int> arr1,vector<int> arr2, int m, int n)
{
    set<int> s;
    for(int i=0; i<m; i++)     // O(mlog(s.size()))
    {
        s.insert(arr1[i]);
    }

    for(int i=0; i<n; i++)    // O(nlog(s.size()))
    {
        s.insert(arr2[i]);
    }

    int i=0;
    vector<int> u(s.size());
    for(auto it : s)               // O(m+n)
    {
        u[i++] = it;
    }

    cout << "union array: ";
    for(int i=0; i<s.size(); i++)
    {
        cout << u[i] << " ";
    }
}

void optimal(vector<int> a, vector<int> b, int m, int n)
{
    vector<int> unionArr;
    int i=0;
    int j=0;

    while(i<m && j<n)
    {
        if(a[i] <= b[j])
        {
            if(unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<m)
    {
        if(unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while(j<n)
    {
        if(unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;        
    }

    cout << "union array: ";
    for(int i=0; i<unionArr.size(); i++)
    {
        cout << unionArr[i] << " ";
    }
}

int main()
{
    int m;
    cout << "enter size of arr1: ";
    cin >> m;

    vector<int> arr1(m);
    cout << "enter arr1: ";
    for(int i=0; i<m; i++)
    {
        cin >> arr1[i];
    }

    int n;
    cout << "enter size of arr2: ";
    cin >> n;

    vector<int> arr2(n);
    cout << "enter arr2: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr2[i];
    }

    optimal(arr1, arr2, m, n);

}
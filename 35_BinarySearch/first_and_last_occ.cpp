#include<bits/stdc++.h>
using namespace std;

// Que: Return the first and last occurance indexes of an element in an array.
//  eg: {2,4,6,8,8,8,11,13}, x = 8 ans = {3,5}, x = 11 ans = {6,6}, x = 10 ans = {-1,-1}

pair<int,int> Brute1(vector<int> arr, int n, int x)
{
    int fstocc = -1;
    int lstocc = -1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            fstocc = i;
            break;
        }
    }

    if(fstocc == -1) return {fstocc, lstocc};

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] == x)
        {
            lstocc = i;
            break;
        }
    }
    
    return {fstocc, lstocc};

    // TC: n
}

pair<int,int> Brute2(vector<int> arr, int n, int x)
{
    int fstocc = -1;
    int lstocc = -1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            if(fstocc == -1) fstocc = i;
            lstocc = i;
        }
    }
    return {fstocc, lstocc};

    // TC: n
}


pair<int,int> Optimal1(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n-1;
    int fstocc = -1;
    int lstocc = -1;

    // first occurance
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == x)
        {
            if(arr[mid - 1] == x)
            {
                high = mid-1;
            }
            else
            {
                fstocc = mid;
                break;
            }
        }
        else if(arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(fstocc == -1) return {fstocc, lstocc}; // to reduce iterations

    // last occurance
    low = fstocc; // to reduce iterations
    high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2; 
        if(arr[mid] == x)
        {
            if(arr[mid + 1] == x)
            {
                high = mid-1;
            }
            else
            {
                lstocc = mid;
                break;
            }
        }
        else if(arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return {fstocc, lstocc};

    // TC: 2log(2,n)
}

pair<int,int> Optimal2(vector<int> arr, int n, int x)
{
    int fstocc = -1;
    int lstocc = -1;

    // lower bound code
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] >= x)
        {
            fstocc = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    if(arr[fstocc] != x) return {-1,-1};

    // upper bound code
    low = 0;
    high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] > x)
        {
            lstocc = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    if (lstocc == -1) lstocc = fstocc+1;

    return {fstocc, lstocc-1};

    // TC: 2log(2,n)
}


int main()
{
    vector<int> arr = {2,4,6,8,8,8,11,13};
    int n = arr.size();
    int x = 13;

    cout << Brute1(arr, n, x).first << " " << Brute1(arr, n, x).second;
    cout << endl;
    cout << Brute2(arr, n, x).first << " " << Brute2(arr, n, x).second;
    cout << endl;
    cout << Optimal1(arr, n, x).first << " " << Optimal1(arr, n, x).second;
    cout << endl;
    cout << Optimal2(arr, n, x).first << " " << Optimal2(arr, n, x).second;


}
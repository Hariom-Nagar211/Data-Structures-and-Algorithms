#include<bits/stdc++.h>
using namespace std;

// Que: Find the median of two sorted arraya.

float Brute(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> arr3;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n1)
    {
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < n2)
    {
        arr3.push_back(arr2[j]);
        j++;
    }

    int n3 = arr3.size();
    if(n3%2 == 0)
    {
        float ans = (arr3[n3/2] + arr3[n3/2 - 1])/2;
        return ans; 
    }
    else
    {
        return arr3[n3/2];
    }

    // TC: n1 + n2
    // SC: n1 + n2
}

float Better(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = n1 + n2;
    float ans = -1;
    int i = 0;
    int j = 0;
    int ind1 = (n3-1)/2;
    int ind2 = n3/2;
    int el1 = 0;
    int el2 = 0;
    int cnt = 0;

    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
        {
            if(cnt == ind1) el1 = arr1[i];
            if(cnt == ind2) el2 = arr2[j];
            i++;
            cnt++;
        }
        else
        {
            if(cnt == ind1) el1 = arr1[i];
            if(cnt == ind2) el2 = arr2[j];
            j++;
            cnt++;
        } 
    }
    while(i < n1)
    {
        if(cnt == ind1) el1 = arr1[i];
        if(cnt == ind2) el2 = arr2[j];
        i++;
        cnt++;
    }
    while(j < n2)
    {
        if(cnt == ind1) el1 = arr1[i];
        if(cnt == ind2) el2 = arr2[j];
        j++;
        cnt++;
    }

    if(n3%2 == 1) return el2;
    else return (el1 + el2) / 2;

    // TC: n1 + n2
    // SC: 1
}

float Optimal(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = n1 + n2;

    if(n1 > n2) Optimal(arr2, arr1);

    int low = 0;
    int high = n1;
    int left = (n3 + 1)/2;
    while(low <= high)
    {
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1)r1 = arr1[mid1];
        if(mid1 < n2)r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(l1 <= r2 && l2 <= r1) 
        {
            if(n3%2 == 1) return max(l1, l2);
            else return (max(l1, l2) + min(r1, r2))/2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> arr1 = {1,3,4,7,10,12}; 
    vector<int> arr2 = {2,3,6,15};

    cout << Brute(arr1, arr2);
    cout << endl;
    cout << Better(arr1, arr2);
    cout << endl;
    cout << Optimal(arr1, arr2);
    

}
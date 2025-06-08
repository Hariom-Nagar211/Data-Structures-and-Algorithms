#include<bits/stdc++.h>

using namespace std;

void Brute(vector<int> arr)
{
    int n = arr.size();
    int cnt = 0;
    map<int,int> mpp;

    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it: mpp)
    {
        if(it.second > n/3)
        {
            cnt++;
        }
    }
    cout << cnt;
}

void Better(vector<int> arr)
{
    int n = arr.size();
    int cnt = 0;
    map<int,int> mpp;

    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]] > n/3 && cnt < n/(n/3 + 1))
        {
            cnt++;
        }
    }
    cout << cnt;
}

void Optimal(vector<int> arr)
{
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(cnt1 == 0 && el2 != arr[i])
        {
            el1 = arr[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && el1 != arr[i])
        {
            el2 = arr[i];
            cnt2 = 1;
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else 
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(el1 = arr[i]) cnt1++;
        if(el2 = arr[i]) cnt2++;
    }

    int mini = (int)(arr.size()/3) + 1;
    vector<int> list;
    if(cnt1 >= mini) list.push_back(el1);
    if(cnt2 >= mini) list.push_back(el2);

    for(int i=0; i<list.size(); i++)
    {
        cout << list[i] << " ";
    }
}

int main()
{
    vector<int> arr = {4,4,4,4,3,3,3,3,7,8};

    Brute(arr);
    cout << endl;
    Better(arr);
    cout << endl;
    Optimal(arr);
    
}
#include<bits/stdc++.h>
using namespace std;

// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains 
// positive integer positions of ‘n’ gas stations on the X-axis. You are also given an 
// integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them 
// anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 
// 'dist' be the maximum value of the distance between adjacent gas stations after 
// adding k new gas stations. Find the minimum value of ‘dist’.

int Brute(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    for(int gasStations=1; gasStations<=k; gasStations++)
    {
        long double maxSection = -1;
        long double maxInd = -1;
        for(int i=0; i<n-1; i++)
        {
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff/(long double)(howMany[i] + 1);
            if(sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for(int i=0; i<n-1; i++)
    {
        long double diff = arr[i+1] - arr[i];
        long double sectionLength = diff/(long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;

    // TC: n*k
}

int Optimal1(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0; i<n-1; i++)
    {
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations=1; gasStations<=k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff/(long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;

    // TC: nlogn + klogn
    // SC: n-1;
}

int main()
{
    vector<int> arr = {1,13,17,23};
    int k = 5;

    cout << Brute(arr, k);
}
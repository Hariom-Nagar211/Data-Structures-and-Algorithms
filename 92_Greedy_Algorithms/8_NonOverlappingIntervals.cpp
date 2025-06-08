#include<bits/stdc++.h>
using namespace std;

// Problem Stament: You have given an intervals array you have to return the list of minimum intervals 
// to be removed so there is no overlapping.

// LC: Greedy + Sorting
// TC: O(n log n)
// SC: O(n)

vector<int> nonOverlappingIntervals(vector<pair<int,int>> intervals)
{
    int n = intervals.size();
    vector<pair<pair<int,int>, int>> arr(n); // st, end, position
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        arr[i].first.first = intervals[i].first;
        arr[i].first.second = intervals[i].second;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end(), [](const pair<pair<int,int>, int> &a, const pair<pair<int,int>, int> &b) {
        return a.first.second < b.first.second;
    });

    int cnt = 1;
    int endOfInterval = arr[0].first.second;
    ans.push_back(arr[0].second);
    for(int i=1; i<n; i++)
    {
        if(endOfInterval <= arr[i].first.first)
        {
            endOfInterval = arr[i].first.second;
            cnt++;
            ans.push_back(arr[i].second);
        }
    }
    return ans;
}

int main()
{
    vector<pair<int,int>> intervals = {{0,5},{3,4},{1,2},{5,9},{5,7},{7,9}};

    vector<int> ans = nonOverlappingIntervals(intervals);

    for(int it : ans) cout << it << " ";
}


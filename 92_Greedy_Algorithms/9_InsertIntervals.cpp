#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of intervals and a new interval, insert the new interval such that
// there are no overlapping intervals. If overlapping occurs, merge the intervals, e.g., (1, 4) and (2, 6)
// should be merged into (1, 6).

// LC: Greedy + Sorting
// TC: O(n log n)
// SC: O(n)

vector<pair<int, int>> nonOverlappingIntervals(vector<pair<int, int>> intervals, pair<int, int> newInterval)
{
    int n = intervals.size();
    vector<pair<int,int>> arr = intervals; // st, end
    vector<pair<int, int>> ans;

    arr.push_back(newInterval);

    sort(arr.begin(), arr.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first < b.first;
    });

    int endOfInterval = arr[0].second;
    ans.push_back(arr[0]);
    for(int i=1; i<n+1; i++)
    {
        if(endOfInterval < arr[i].first)
        {
            endOfInterval = arr[i].second;
            ans.push_back(arr[i]);
        }
        else
        {
            endOfInterval = arr[i].second;
            ans.push_back({arr[i-1].first, arr[i].second});
            int size = ans.size();
            ans.erase(ans.begin() + size-1);

        }
    }
    return ans;
}

int main()
{
    vector<pair<int,int>> intervals = {{1,2},{3,4},{6,7},{8,10},{12,16}};

    pair<int, int> newInterval = {5,8};

    vector<pair<int,int>> ans = nonOverlappingIntervals(intervals, newInterval);

    for(auto it : ans) cout << '(' << it.first << ',' << it.second << ')' << ' ';
}


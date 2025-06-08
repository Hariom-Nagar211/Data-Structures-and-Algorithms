#include<bits/stdc++.h>
using namespace std;

// Problem Statment: Given the start and end times of meetings, maximize the number of meetings that can be scheduled in 
// one room without overlapping.

// LC: Greedy + Sorting
// TC: O(n log n)
// SC: O(n)

vector<int> MaxMeetings(vector<int> st, vector<int> end)
{
    int n = st.size();
    vector<pair<pair<int,int>, int>> arr(n); // st, end, position
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        arr[i].first.first = st[i];
        arr[i].first.second = end[i];
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end(), [](const pair<pair<int,int>, int> &a, const pair<pair<int,int>, int> &b) {
        return a.first.second < b.first.second;
    });

    int cnt = 1;
    int freeTime = arr[0].first.second;
    ans.push_back(arr[0].second);
    for(int i=1; i<n; i++)
    {
        if(freeTime < arr[i].first.first)
        {
            freeTime = arr[i].first.second;
            cnt++;
            ans.push_back(arr[i].second);
        }
    }
    return ans;
}

int main()
{
    vector<int> st = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};

    vector<int> ans = MaxMeetings(st, end);

    for(int it : ans) cout << it << " ";
}
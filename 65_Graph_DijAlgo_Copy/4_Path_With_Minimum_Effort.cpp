#include<bits/stdc++.h>
using namespace std;

// Path With Minimum Effort : Dijkstra on a grid.
// Link : https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
private:
    int dijAlgo(vector<vector<int>>& heights, int n, int m) 
    {
        // Min-heap: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) 
        {
            auto top = pq.top();
            pq.pop();

            int effort = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) 
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m) 
                {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), effort);

                    if (newEffort < dist[newr][newc]) 
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }

        return 0; // unreachable (in practice won't happen in valid inputs)
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        return dijAlgo(heights, n, m);
    }
};

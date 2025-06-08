#include<bits/stdc++.h>
using namespace std;

// QUE : Find the city with smallest number of rechable cities with atmost threshold distance.

int FindCity(int n, int m, vector<vector<int>> &edges, int t)
{
    // Using Floyd Warshall Algorithm

    // Creating Distance Matrix(row,col -> cities , value -> smallest distance)
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        dis[u][v] = wt;
        dis[v][u] = wt;
    }

    // Fixing Self-Loops
    for(int i=0; i<n; i++) dis[i][i] = 0;

    // Applying Algorithm
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dis[i][k] == 1e9 || dis[k][j] == 1e9) continue;
                dis[i][j] = min(dis[i][j], (dis[i][k] + dis[k][j]));
            }
        }
    }

    // Finding City
    int cnt = 0;
    int min_cnt = 1e9;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dis[i][j] <= t)
            {
                cnt++;
            }
        }
        if(min_cnt >= cnt) 
        {
            ans = i;
            min_cnt = cnt;
        }
    }
    return ans;
}
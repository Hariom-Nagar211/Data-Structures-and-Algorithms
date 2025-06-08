#include<bits/stdc++.h>
using namespace std;

// Floyd Warshall Algorithm : Find's multisource sortest path 
// and also detect negative cycles.

// Input : adj matrix containing edge weights(-1 if not).

vector<vector<int>> FloydWarshallAlgo(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // number of nodes
    vector<vector<int>> dis = matrix;

    // disjoint nodes
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dis[i][j] == -1) dis[i][j] == 1e9;
            if(i == j) dis[i][j] = 0;
        }
    }

    // Appling algorithm
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dis[i][j] = min(dis[i][j], (dis[i][k] + dis[k][j]));
            }
        }
    }

    // negative cycle
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dis[i][j] < 0) return {{-1}};
        }
    }

    // disjoint nodes
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dis[i][j] == 1e9) dis[i][j] == -1;
        }
    }
    return dis;

    // TC : N x N x N
}



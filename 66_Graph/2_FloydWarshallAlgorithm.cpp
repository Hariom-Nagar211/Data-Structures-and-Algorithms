#include<bits/stdc++.h>
using namespace std;

// Interview Explanation : 
// “Floyd-Warshall finds the shortest paths between all pairs of nodes. It uses dynamic programming. 
// For each pair (i, j), we check if going through an intermediate node k can give a shorter path.”

vector<vector<int>> FloydWarshallAlgo(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dis = matrix;

    // Convert -1 to INF and set diagonal as 0
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dis[i][j] == -1) dis[i][j] = 1e9; 
            if(i == j) dis[i][j] = 0;
        }
    }

    // Floyd-Warshall: Try every node as intermediate
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dis[i][k] != 1e9 && dis[k][j] != 1e9)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // Check for negative cycles
    for(int i = 0; i < n; i++)
    {
        if(dis[i][i] < 0) return {{-1}};
    }

    // Convert INF back to -1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dis[i][j] == 1e9) dis[i][j] = -1;
        }
    }

    return dis;
}

// TC : O(V x V x V)
// SC : O(V x V)



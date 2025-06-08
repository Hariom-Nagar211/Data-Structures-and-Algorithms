#include<bits/stdc++.h>
using namespace std;

// QUE : Bellman Ford Algorithm

vector<int> BellmanFordAlgorithm(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dis(V , 1e9);
    dis[src] = 0;

    // iterating for V-1 times
    for(int i=0; i<V-1; i++)
    {
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u] != 1e9 && dis[u] + wt < dis[v])
            {
                dis[v] = dis[u] + wt;
            }
        }
    }

    // Nth iteration cheaking for negative cycle
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dis[u] != 1e9 && dis[u] + wt < dis[v])
        {
            return {-1};
        }
    }

    return dis;

    // TC : E x V
}
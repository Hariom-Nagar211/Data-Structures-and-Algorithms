#include<bits/stdc++.h>
using namespace std;

// Interview Explanation : 
// “Bellman-Ford is used to find the shortest distance from a single source to all other vertices 
// in a graph — even when there are negative weights. Unlike Dijkstra, it works with negative weights 
// and detects negative cycles.”

// viz : https://algorithms.discrete.ma.tum.de/graph-algorithms/spp-bellman-ford/index_en.html

vector<int> BellmanFordAlgorithm(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dis(V , 1e9); // 1e9 means INF
    dis[src] = 0;

    // Step 1: Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u] != 1e9 && dis[u] + wt < dis[v])
                dis[v] = dis[u] + wt;
        }
    }

    // Step 2: Check for negative weight cycle
    for(auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dis[u] != 1e9 && dis[u] + wt < dis[v])
            return {-1}; // Negative cycle found
    }

    return dis;
}

// TC : O(V x E)
// SC : O(V)




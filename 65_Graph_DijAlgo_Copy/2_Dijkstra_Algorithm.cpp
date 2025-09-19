#include <bits/stdc++.h>
using namespace std;

// Basic implementation using adjacency matrix
// Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

vector<int> DijAlgo(int V, vector<pair<int, int>> adj[]) 
{
    vector<int> dis(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) 
    {
        int node = pq.top().second;
        int dist_from_src = pq.top().first;
        pq.pop();
        
        for (auto it : adj[node]) 
        {
            int neighbor = it.first;
            int edge_weight = it.second;

            if (dist_from_src + edge_weight < dis[neighbor]) 
            {
                dis[neighbor] = dist_from_src + edge_weight;
                pq.push({dis[neighbor], neighbor});
            }
        }
    }

    return dis; 
}







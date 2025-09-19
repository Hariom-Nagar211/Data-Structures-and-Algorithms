#include <bits/stdc++.h>
using namespace std;

// In Dijkstra's algorithm, we start with a source node, set its distance to zero, and others to 
// infinity. We use a min-heap (priority queue) to repeatedly pick the node with the smallest 
// tentative distance. We update the distances to its neighbors if we find a shorter path. This 
// continues until all shortest distances are finalized. The algorithm works efficiently using a 
// priority queue with time complexity O(E log V).

vector<int> DijAlgo(int V, vector<pair<int, int>> adj[]) 
{
    // Step 1: Initialize distance array with INF
    vector<int> dis(V, INT_MAX);

    // Step 2: Min-Heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step 3: Start from source node 0
    dis[0] = 0;
    pq.push({0, 0});

    // Step 4: Process the graph
    while (!pq.empty()) 
    {
        int node = pq.top().second;
        int dist_from_src = pq.top().first;
        pq.pop();

        // Step 5: Explore neighbors
        for (auto it : adj[node]) 
        {
            int neighbor = it.first;
            int edge_weight = it.second;

            // Step 6: If a shorter path is found
            if (dist_from_src + edge_weight < dis[neighbor]) 
            {
                dis[neighbor] = dist_from_src + edge_weight;
                pq.push({dis[neighbor], neighbor});
            }
        }
    }

    return dis; // Final shortest distances
}

// TC : O(E log V) for Each edge is relaxed once → E and PQ operations → log V
// SC : O(V + E) for adjacency list and distance array






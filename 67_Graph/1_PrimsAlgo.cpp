#include<bits/stdc++.h>
using namespace std;

// Greedy
// "Prim's Algorithm is a greedy method to find the Minimum Spanning Tree. It starts with any node and always adds the edge with the smallest weight that connects a new node to the growing MST.
// I use a min-heap (priority queue) to pick the minimum edge quickly, and I track visited nodes to avoid cycles.
// The total cost is simply the sum of all the selected edge weights."

// Visualization : https://upload.wikimedia.org/wikipedia/commons/9/9b/PrimAlgDemo.gif
// Visualization2 : https://see-algorithms.com/graph/PrimsMST

/*
    Prim’s Algorithm (Using Min Heap)
    ----------------------------
    Time Complexity: O(E * logV)
    where E = number of edges, V = number of vertices
*/

void primMST(int V, vector<vector<int>> adj[]) 
{
    // Min-heap to get edge with minimum weight: {weight, {current_node, parent_node}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    vector<int> vis(V, 0);              // Track visited nodes
    vector<pair<int, int>> mst_edges;       // Store MST edges
    int total_cost = 0;                     // MST total weight

    // Start from node 0, with weight 0 and no parent (-1)
    pq.push({0, {0, -1}});

    while (!pq.empty()) 
    {
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        int wt = pq.top().first;
        pq.pop();

        // Skip if already included in MST
        if (vis[node]) continue;
        vis[node] = 1;

        // If not the starting node, add edge to MST
        if (parent != -1) 
        {
            mst_edges.push_back({parent, node});
            total_cost += wt;
        }

        // Traverse all adjacent nodes
        for (auto it : adj[node]) 
        {
            int conn_node = it[0];
            int edgeWt = it[1];
            if (!vis[conn_node]) 
            {
                pq.push({edgeWt, {conn_node, node}});
            }
        }
    }

    // Print the MST edges
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto [u, v] : mst_edges) 
    {
        cout << u << " --- " << v << "\n";
    }

    // Print total weight
    cout << "Total Weight of MST: " << total_cost << "\n";
}




#include<bits/stdc++.h>
using namespace std;

// Prims Algorithm to find minimum spanning tree

void MinimumSpanningTree(int V, vector<vector<int>> adj[])
{
    // Data Structures
    vector<int> vis(V, 0);
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, 
    greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0,0},-1});  // {wt, node, parent} 
    vector<pair<int, int>> MST;
    int sum = 0;

    // Applying Algorithm
    while(!pq.empty())
    {
        int wt = pq.top().first.first;
        int node = pq.top().first.second;
        int parent = pq.top().second;
        pq.pop();

        if(vis[node] == 1) continue;
        
        vis[node] = 1;

        for(auto it : adj[node])
        {       
            int adjNode = it[0];
            int edge = it[1];
            pq.push({{edge, adjNode}, node});

        }

        if(parent == -1) continue;

        MST.push_back({parent, node});
        sum += wt;
    }

    // Printing MST and its Sum
    for(auto it : MST)
    {
        cout << it.first << "---" << it.second << endl;
    }
    cout << "Sum is : " << sum;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj[V];
    adj[0] = {{1,2},{2,1}};
    adj[1] = {{0,2},{2,1}};
    adj[2] = {{0,1},{1,1},{4,2},{3,2}};
    adj[3] = {{2,2},{4,1}};
    adj[4] = {{2,2},{3,1}};

    MinimumSpanningTree(V, adj);
}
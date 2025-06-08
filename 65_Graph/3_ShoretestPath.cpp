#include<bits/stdc++.h>
using namespace std;

vector<int> ShortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    int V = n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V+1, 1e9);
    vector<int> parent(V+1);
    for(int i=1; i<V+1; i++) parent[i] = i;
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int edge = it.second;
            if(dis + edge < dist[adjNode])
            {
                parent[adjNode] = node;
                dist[adjNode] = dis + edge;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if(dist[V] == 1e9) return {-1};
    vector<int> path;
    int node = V;
    while(parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n = 5;
    int m = 6;
    vector<vector<int>> edges[n+1];
    adj[0] = {{1,4},{2,4}};
    adj[1] = {{0,4},{2,2}};
    adj[2] = {{0,4},{1,2},{3,3},{4,1},{5,6}};
    adj[3] = {{2,3},{5,2}};
    adj[4] = {{2,1},{5,3}};
    adj[5] = {{3,2},{4,3},{2,6}};

    vector<int> ans = ShortestPath(V, adj);
    for(auto it : ans)
    {
        cout << it << " ";
    }
}
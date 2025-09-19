#include<bits/stdc++.h>
using namespace std;

// Link : https://cses.fi/problemset/task/1671/
// Concept : Optimised DijAlgo

// Test Example :
// 4 Nodes (0 to 3), 5 Edges:
// 0 -> 1 (2)
// 0 -> 2 (4)
// 1 -> 2 (1)
// 1 -> 3 (7)
// 2 -> 3 (3)

vector<long long> dijAlgo(int V, vector<vector<pair<int, int>>> &adj) 
{
    vector<long long> dis(V, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis[0] = 0;
    pq.push({0, 0});
  
    while(!pq.empty()) 
    {
        int node = pq.top().second;
        long long node_dis_from_src = pq.top().first;
        pq.pop();

        // ✅ Skip if already visited with better distance
        if(dis[node] < node_dis_from_src) continue;

        for(auto it : adj[node])
        {
            int conn_node = it.first;
            int conn_node_dis_from_parent = it.second;

            if(node_dis_from_src + conn_node_dis_from_parent < dis[conn_node])
            {
                dis[conn_node] = node_dis_from_src + conn_node_dis_from_parent;
                pq.push({dis[conn_node], conn_node});
            }
        }
    }
    return dis;
}
 
int main() 
{
    int V, m;
    cin >> V >> m;

    vector<vector<pair<int, int>>> adj(V);
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        adj[a].emplace_back(b, c);
    }

    vector<long long> dis = dijAlgo(V, adj);

    for(auto it : dis)
    {
        cout << it << " ";
    }
    cout << '\n';

}

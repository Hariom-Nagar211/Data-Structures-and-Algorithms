#include<bits/stdc++.h>
using namespace std;

// prob : Cycle with minimum cost.
// Link : https://atcoder.jp/contests/abc191/tasks/abc191_e
// new idea :
// 🔁 For every edge (u, v, wt):
// Temporarily remove edge (u, v)
// Run Dijkstra from u to v
// If a path exists:
// Total cycle length = distance from u to v + edge weight
// Restore the edge
// Repeat this for all edges connected to node u, and keep the minimum.

int dijAlgo(int V, const vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dis(V+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dis[src] = 0;
    pq.push({0, src});

    int min_cycle = 1e9;

    while(!pq.empty())
    {
        int node_dis_from_src = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node])
        {
            int conn_node = it.first;
            int conn_node_dis = it.second;

            // If we come back to src and it's not the starting edge
            if(conn_node == src && node_dis_from_src + conn_node_dis > 0) {
                min_cycle = min(min_cycle, node_dis_from_src + conn_node_dis);
            }

            if(node_dis_from_src + conn_node_dis < dis[conn_node]) {
                dis[conn_node] = node_dis_from_src + conn_node_dis;
                pq.push({dis[conn_node], conn_node});
            }
        }
    }

    return (min_cycle == 1e9) ? -1 : min_cycle;
}

int main()
{
    int V, m;
    cin >> V >> m;
    vector<vector<pair<int, int>>> adj(V+1);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<int> time(V+1, -1);
    for(int i = 1; i <= V; i++)
    {
        time[i] = dijAlgo(V, adj, i);
    }

    for(int i = 1; i <= V; i++)
    {
        cout << time[i] << endl;
    }
}

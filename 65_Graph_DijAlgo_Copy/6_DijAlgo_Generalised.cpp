#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Link : https://codeforces.com/problemset/problem/20/C

vector<int> dijAlgo(int V, vector<vector<pair<int, ll>>> &adj)
{
    const ll INF = 1e18;  // Much larger than INT_MAX
    vector<ll> dis(V + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<int> parent(V + 1, -1);

    dis[1] = 0;
    pq.push({0, 1});
    parent[1] = 1;

    while (!pq.empty())
    {
        int node = pq.top().second;
        ll node_dis_from_src = pq.top().first;
        pq.pop();

        for (auto &it : adj[node])
        {
            int conn_node = it.first;
            ll conn_node_dis_from_parent = it.second;

            if (node_dis_from_src + conn_node_dis_from_parent < dis[conn_node])
            {
                dis[conn_node] = node_dis_from_src + conn_node_dis_from_parent;
                pq.push({dis[conn_node], conn_node});
                parent[conn_node] = node;
            }
        }
    }

    if (dis[V] == INF)
        return {-1}; 

    vector<int> path;
    int node = V;
    while (node != parent[node])
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
    int V, m;
    cin >> V >> m;

    vector<vector<pair<int, ll>>> adj(V + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<int> path = dijAlgo(V, adj);

    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;
}

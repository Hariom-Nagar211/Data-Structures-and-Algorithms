#include<bits/stdc++.h>
using namespace std;

// QUE : Find the shortest path fron source to all nodes if path is not possible then take it -1.

vector<int> ShortestPath(int V, vector<int> adj[], int src)
{
    int vis[V] = {0};
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    vector<int> dis(V);
    for(int i=0; i<V; i++) dis[i] = -1;
    dis[src] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
                dis[it] = dis[node] + 1;
            }
        }
    }
    return dis;
}

int main()
{
    int V = 9;
    vector<int> adj[V];
    adj[0] = {1,3};
    adj[1] = {0,2,3};
    adj[2] = {1,6};
    adj[3] = {0,1,4};
    adj[4] = {3,5};
    adj[5] = {4,6};
    adj[6] = {2,5,7,8};
    adj[7] = {6,8};
    adj[8] = {6,7};

    int src = 0;

    vector<int> ans  = ShortestPath(V, adj, src);
    for(auto it : ans)
    {
        cout << it << " ";
    }
}
#include<bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q; // node, parent
    q.push({src, -1});
    
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjecentNode : adj[node])
        {
            if(!vis[adjecentNode])
            {
                vis[adjecentNode] = 1;
                q.push(adjecentNode, node);
            }
            else if(parent != adjecentNode) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;

    // TC : n + 2*E + n
    // SC : n + n
}
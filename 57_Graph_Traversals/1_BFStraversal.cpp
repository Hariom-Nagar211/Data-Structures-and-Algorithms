#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    int vis[v] = {0};
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    vector<int> bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;

    // SC : 3n
    // TC : V + 2*E

}
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    for(auto it : adj[node]) 
        if(!vis[it]) dfs(it, adj ,vis);
    
}

int cntProvinces2(int v, vector<vector<int>> adjMat)
{
    // converting adj matrix to adj list
    vector<int> adj[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(adjMat[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);

            }
        }
    }

    int vis[v] = {0};
    int cnt = 0;
    for(int i=0; i<v; i++)
    {
        if(!vis[i]) 
        {
            cnt++;
            dfs(i, adj, vis);
        }
    }
    return cnt;

}
